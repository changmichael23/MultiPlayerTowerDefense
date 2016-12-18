#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <thread>
#include <iostream>
#include <vector>

#define NB_MAX_CLIENT 8
#define DEFAULT_PORT 54000
#define DEFAULT_IP "167.0.0.1"

//structure qui stock les informations d'un client (vu par le réseau)
struct Client {
	sf::IpAddress ip;
	unsigned short port;
	sf::Packet packet;
	std::string name;
	bool isMessageReceived = false;
};
//structure contenant les données du serveur
struct Server {
	sf::UdpSocket socket;
	sf::IpAddress ip;
	unsigned short port;
	int nbMessageRecus = 0;
	int nbClient;
};
//variables globales
std::vector<Client> listClient;
Server server;
bool test_exit = 0;
sf::Mutex mutex;


//Fonctions à placer dans 1 thread chacunes pour géré le serveur
void handleServeur();
void handleClient(int i);
//Autre fonctions
void init();
Client createClient(sf::Packet packet, sf::IpAddress ip,unsigned short port, std::string name);

//création de nouveaux clients
Client createClient(sf::Packet packet, sf::IpAddress ip, unsigned short port, std::string name) {
	Client newClient;
	newClient.ip = ip;
	newClient.port = port;
	newClient.packet = packet;
	newClient.name = name;
	return newClient;
}

//initialisation des données du serveur
void init() {
	server.port = DEFAULT_PORT;
	server.ip = sf::IpAddress().getLocalAddress();
	//liaison de la socket à un port
	if (server.socket.bind(server.port) != sf::Socket::Done)
	{
		printf("bind error\n");// erreur
	}
	server.nbMessageRecus = 0;
	std::cout << "Nombre de joueur : ";
	std::cin >> server.nbClient;
	std::cout << "adresse du serveur : " << server.ip;
}
//thread qui gère le serveur et donc l'envoi des messages reçus à tous les clients
void handleServeur() {
	while (!test_exit) {	
		if (listClient.size()>0 && server.nbMessageRecus >= listClient.size()) {
			mutex.lock();
			//envoyer le message aux tous les clients dans liste
			for (int i = 0; i < listClient.size(); i++) {
				for (int j = 0; j < listClient.size(); j++) {
					if (server.socket.send(listClient[j].packet, listClient[i].ip, listClient[i].port) != sf::Socket::Done)
					{
						printf("send error\n");// erreur
					}
				}
				listClient[i].isMessageReceived = false;
			}
			printf("message sent to all client\n");
			server.nbMessageRecus = 0;
			mutex.unlock();
		}
	}
}
//thread qui gère un client
void handleClient(int i) {
	Client * client = &listClient[i];
	sf::Packet packet;
	sf::IpAddress sender;
	unsigned short port;
	//on initialise chaque client en lui envoyant le nombre de client sur le serveur
	packet << i << server.nbClient;
	if (server.socket.send(packet, client->ip, client->port) != sf::Socket::Done)
	{
		printf("send error\n");// erreur
	}
	//boucle de gestion du client
	while (!test_exit)
	{
		if (server.socket.receive(packet, sender, port) != sf::Socket::Done)
		{
			printf("receive error\n");// erreur
		}
		else 
		{	
			mutex.lock();
			if (sender == client->ip && !client->isMessageReceived) {
				printf("message recu\n");
				client->packet = packet;
				server.nbMessageRecus++;
				client->isMessageReceived = true;
			}
			mutex.unlock();
		}
	}
}


int main() {
	init();
	std::vector<std::thread> listThread;
	bool isNewClient;
	sf::Packet packet;
	sf::IpAddress sender;
	unsigned short port;
	while (listClient.size() < server.nbClient)
	{
		isNewClient = true;
		//recevoir un message
		if (server.socket.receive(packet, sender, port) != sf::Socket::Done)
		{
			printf("receive error\n");// erreur
		}
		else {
			for (int i = 0; i < listClient.size(); i++) {
				if (sender == listClient[i].ip) {
					isNewClient = false;
				}
			}
			if (isNewClient) {
				std::string tmp;
				packet >> tmp;
				listClient.push_back(createClient(packet, sender, port, tmp));
			}
		}
	}
	for (int i = 0; i < listClient.size(); i++) {
		listThread.push_back(std::thread(handleClient, i));
	}
	std::thread t1(handleServeur);
	t1.join();
}