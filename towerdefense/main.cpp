#include "NetworkClient.hpp"



int main()
{
	//initialisation des variables réseau
	initData();
	initClient();
	Game game;
	//variable de gestion du jeu
	sf::RenderWindow window;
	game.init(&window);
	game.getGamestate().setIdClient(client.id);

	//lance l'écoute du serveur
	std::thread t1(receive);

	//on lance la premiere game loop et le premier envoie de donnée
	game.setPositionSouris(sf::Vector2i(0, 0));
	game.gameLoop(&window);
	isAllMessagesReceived = true;
	
	//boucle de jeu complète
	while (window.isOpen()) {
		if (isAllMessagesReceived) {
			//création du message à envoyer au serveur
			client.posTower = game.getPositionSouris();
			send();
			//réinit l'action du joueur
			game.setPositionSouris(sf::Vector2i(0, 0));
			//on met a jour le booléen qui détecte la reception de message
			isAllMessagesReceived = false;
			std::vector<sf::Vector3i> temp = listAction;
			initData();
			//on récupère les données envoyées par les autres joueurs pour mettre réellement le jeu à jour
			for (int nbTower = 0; nbTower < temp.size(); nbTower++) {
				if (temp[nbTower].x != 0 || temp[nbTower].y != 0) {
					game.createTower(sf::Vector2i(temp[nbTower].x, temp[nbTower].y), temp[nbTower].z);
				}
			}
			//affiche 20 frame de facon autonome
			game.gameLoop(&window);
		}
		else 
		{
			//création du message à envoyer au serveur
			client.posTower = game.getPositionSouris();
			send();
		}
	}
	return 0;
}