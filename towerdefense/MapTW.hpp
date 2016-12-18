#include <SFML/Graphics.hpp>
#include "Global.hpp"


class MapTW 
{

private:
	//Listes de points, x y et dir, dir correspond a la direction du chemin
	std::vector<sf::Vector3i> points;
	std::vector<sf::Vector3i> spawns;
	std::vector<int> listEnemySpawns;
	int cptEnemySpawn;
	
public:
	//Constructeur
	MapTW();

	//Accesseurs
	std::vector<sf::Vector3i> getPoints();
	std::vector<sf::Vector3i> getSpawns();
	std::vector<int> getListEnemySpawns();

	//Méthodes
	int getNextEnemySpawns();
	
};