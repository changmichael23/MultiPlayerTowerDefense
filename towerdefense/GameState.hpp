#include "Global.hpp"
//include SFML
#include <SFML/Graphics.hpp>
//include standard
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
//include des fichiers de jeu
#include "Enemy.hpp"
//include des fichiers de rendu
#include "RenderPlayzone.hpp"
#include "RenderEnemy.hpp"
#include "RenderTower.hpp"
#include "RenderCastle.hpp"
#include "RenderMap.hpp"
#include "RenderGold.hpp"

class GameState
{
public:
	//constructeurs
	GameState();
	~GameState();

	//accesseurs
	MapTW& getMap();
	std::vector<Turret>& getListTurret();
	std::vector<Enemy>& getListEnemy();
	int& getCpt();
	int& getLevel();
	int& getMaxLvl();
	int& getIdClient();
	Castle& getCastle();
	Gold& getGold();
	void setIdClient(int id);
	void setMaxLvl(int maxLvl);
	void setCpt(int newCpt);
	void setLevel(int l);

	

	//méthodes
	void nextGameState();
	void collide();
	void createTower(sf::Vector2i cible, int id);
	void updateRenderGamestate(sf::RenderWindow * window);
	Enemy cible(Turret t);
	void increaseLevel();
	

private:
	MapTW map;
	std::vector<Turret> listTurret;
	std::vector<Enemy> listEnemy;
	int cpt;
	int level;
	Castle castle;
	Gold gold;
	int maxLvl = 30;
	int idClient;
};
