#include "NetworkClient.hpp"

//variables pour le réseau
Client client;
Server server;
std::vector<sf::Vector3i> listAction;
sf::Mutex mutex;
int nbClient;
int nbMessageRecu;
bool isAllMessagesReceived;

sf::Packet serialize() {
	sf::Packet packet;
	packet << client.posTower.x << client.posTower.y << client.id;
	return packet;
}
void deserialize(sf::Packet packet) {
	int x, y, id;
	packet >> x >> y >> id;
	mutex.lock();
	listAction.push_back(sf::Vector3i(x, y, id));
	mutex.unlock();
}

void send() {
	//envoyer un message
	sf::Packet packet;
	packet = serialize();
	if (client.udpSocket.send(packet, client.myIp, client.myPort) != sf::Socket::Done)
	{
		printf("err with socket.send");// erreur...
	}
}

void receive() {
	//recevoir un message
	while (true)
	{
		sf::Packet packet;
		sf::IpAddress sender;
		unsigned short port;
		if (client.udpSocket.receive(packet, sender, port) != sf::Socket::Done)
		{
			printf("err with socket.receive");// erreur...
		}
		else
		{
			mutex.lock();
			deserialize(packet);
			nbMessageRecu++;
			if (nbMessageRecu == nbClient) {
				isAllMessagesReceived = true;
				nbMessageRecu = 0;
			}
			mutex.unlock();
		}
	}
}

void initClient() {
	client.myIp = DEFAULT_IP;
	client.myPort = DEFAULT_PORT;
	client.name = "toto";
	client.posTower = sf::Vector2i(0, 0);
	isAllMessagesReceived = false;
	client.id = 0;
	//on demande les informations au client 
	std::cout << "quel est votre nom?" << std::endl;
	std::cin >> client.name;
	std::cout << std::endl << "adresse du serveur" << std::endl;
	std::cin >> client.myIp;
	//on initialise la socket
	if (client.udpSocket.bind(client.udpSocket.getLocalPort()) != sf::Socket::Done)
	{
		printf("err with socket.bind");// erreur...
	}
	//envoyer un message
	sf::Packet packet;
	sf::IpAddress sender;
	unsigned short port;
	packet << client.name;
	if (client.udpSocket.send(packet, client.myIp, client.myPort) != sf::Socket::Done)
	{
		printf("err with socket.send");// erreur...
	}
	if (client.udpSocket.receive(packet, sender, port) != sf::Socket::Done)
	{
		printf("err with socket.receive");// erreur...
	}
	packet >> client.id >> nbClient;
}

void initData() {
	mutex.lock();
	listAction.clear();
	mutex.unlock();
}