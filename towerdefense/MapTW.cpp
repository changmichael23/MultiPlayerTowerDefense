#include "MapTW.hpp"


MapTW::MapTW()
{
	points.push_back(sf::Vector3i(100, 0,0));
	points.push_back(sf::Vector3i(150, 600,1));
	points.push_back(sf::Vector3i(100, 350,3));
	points.push_back(sf::Vector3i(650,0,0));
	points.push_back(sf::Vector3i(700, 600,1));
	points.push_back(sf::Vector3i(700, 300,2));
	points.push_back(sf::Vector3i(375, 300,0));

	spawns.push_back(sf::Vector3i(110, 10, 0));
	spawns.push_back(sf::Vector3i(110,560, 1));
	spawns.push_back(sf::Vector3i(110,310, 3));
	spawns.push_back(sf::Vector3i(660,10, 0));
	spawns.push_back(sf::Vector3i(660, 560, 1));
	spawns.push_back(sf::Vector3i(660, 310, 2));
	spawns.push_back(sf::Vector3i(385, 310, 0));

	listEnemySpawns.push_back(0);
	listEnemySpawns.push_back(2);
	listEnemySpawns.push_back(4);
	listEnemySpawns.push_back(5);
	listEnemySpawns.push_back(6);
	listEnemySpawns.push_back(0);
	listEnemySpawns.push_back(3);
	listEnemySpawns.push_back(4);
	listEnemySpawns.push_back(1);
	listEnemySpawns.push_back(2);
	listEnemySpawns.push_back(0);
	listEnemySpawns.push_back(2);
	listEnemySpawns.push_back(4);
	listEnemySpawns.push_back(5);
	listEnemySpawns.push_back(6);

	cptEnemySpawn = -1;
}
	
std::vector<sf::Vector3i> MapTW::getPoints()
{
	return points;
}

std::vector<sf::Vector3i> MapTW::getSpawns()
{
	return spawns;
}

std::vector<int> MapTW::getListEnemySpawns()
{
	return listEnemySpawns;
}

int MapTW::getNextEnemySpawns() {
	cptEnemySpawn++;
	if (cptEnemySpawn >= listEnemySpawns.size()) {
		cptEnemySpawn = 0;
	}
	return listEnemySpawns[cptEnemySpawn];
}