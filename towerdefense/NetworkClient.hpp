#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <thread>
#include <iostream>
#include "Game.hpp"

#define NB_MAX_CLIENT 8
#define DEFAULT_PORT 54000
#define DEFAULT_IP "167.0.0.1"


//structure qui stock les informations d'un client (vu par le réseau)
struct Client {
	sf::UdpSocket udpSocket;
	sf::IpAddress myIp;
	unsigned short myPort;
	sf::Packet packet;
	std::string name;
	sf::Vector2i posTower;
	int id;
};
//structure contenant les données du serveur
struct Server {
	sf::IpAddress ip;
	unsigned short port;
};

//variables pour le réseau
extern Client client;
extern Server server;
extern std::vector<Game> listGame;
extern std::vector<sf::Vector3i> listAction;
extern int nbClient;
extern int nbMessageRecu;
extern bool isAllMessagesReceived;

//fonction de serialisation / déserialisation des données de jeu
sf::Packet serialize();
void deserialize(sf::Packet packet);

//fonction qui permet d'envoyer des informations au serveur
void send();
//fonction qui permet de recevoir les informations du serveur
void receive();
//fonction d'initialisation du client
void initClient();
//fonction qui initialise les données de reception/envoi
void initData();


