#include "GameState.hpp"

//constructeurs
GameState::GameState() {
	listEnemy = {};
	listTurret = {};
	gold = 400;
	cpt = 1;
	level = 1;
}
GameState::~GameState() {}

//accesseurs
MapTW& GameState::getMap() {
	return map;
}
std::vector<Turret>& GameState::getListTurret() {
	return listTurret;
}
int& GameState::getCpt() {
	return cpt;
}
int& GameState::getLevel() {
	return level;
}
int& GameState::getMaxLvl()
{
	return maxLvl;
}
int& GameState::getIdClient()
{
	return idClient;
}
Castle& GameState::getCastle()
{
	return castle;
}
std::vector<Enemy>& GameState::getListEnemy()
{
	return listEnemy;
}
void GameState::setMaxLvl(int m)
{
	maxLvl = m;
}
void GameState::setCpt(int newCpt) {
	cpt = newCpt;
}
void GameState::setLevel(int l) {
	int tmp = level - l;
	for (int i = 0; i < tmp; i++) {
		increaseLevel();
	}
}
void GameState::setIdClient(int id)
{
	idClient = id;
}

//Next Game State
void  GameState::nextGameState()
{
	collide();
	for (int i = 0; i < listTurret.size(); i++)
	{
		//Oriente la tourelle vers l'enemy
		Enemy newCible = cible(listTurret[i]);
		listTurret[i].updateTurret(newCible.getCenter());
		if (listEnemy.size() == 0 || (cpt % 50 != 0) || (listTurret[i].getRange() < sqrt(powf(newCible.getCenter().x - listTurret[i].getPos().x, 2) + powf(newCible.getCenter().y - listTurret[i].getPos().y, 2))))
		{
			listTurret[i].setFire(false);
		}
		else
		{
			listTurret[i].setFire(true);
		}
		
		listTurret[i].fire();
	}
	//met a jour tous les ennemis
	for (int i = 0; i < listEnemy.size(); i++)
	{
		if (listEnemy[i].getAlive() == false){
			gold.increaseGold(listEnemy[i].getGoldValue());
			listEnemy.erase(listEnemy.begin()+i);
		}
		else {
			listEnemy[i].nextMove();
		}
	}
}

void GameState::createTower(sf::Vector2i clickPos, int id) {
	Turret newTurret(clickPos);
	switch (id) {
	case 0:
		if (clickPos.x >= 200 && clickPos.x <= 400 && clickPos.y >= 200 && clickPos.y <= 600)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);	
		}
		break;
	case 1:
		if (clickPos.x >= 400 && clickPos.x <= 600 && clickPos.y >= 200 && clickPos.y <= 600)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;

	case 2:
		if (clickPos.x >= 0 && clickPos.x <= 200 && clickPos.y >= 0 && clickPos.y <= 200)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;
	case 3:
		if (clickPos.x >= 0 && clickPos.x <= 200 && clickPos.y >= 200 && clickPos.y <= 400)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;
	case 4:
		if (clickPos.x >= 0 && clickPos.x <= 200 && clickPos.y >= 400 && clickPos.y <= 600)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;
	case 5:
		if (clickPos.x >= 600 && clickPos.x <= 800 && clickPos.y >= 0 && clickPos.y <= 200)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;
	case 6:
		if (clickPos.x >= 600 && clickPos.x <= 800 && clickPos.y >= 200 && clickPos.y <= 400)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;
	case 7:
		if (clickPos.x >= 600 && clickPos.x <= 800 && clickPos.y >= 400 && clickPos.y <= 600)
		{
			if (gold.decreaseGold(newTurret.getCost()))
				listTurret.push_back(newTurret);
		}
		break;
	}
}

void GameState::updateRenderGamestate(sf::RenderWindow * window) {
	window->clear(sf::Color(205, 205, 255));
	//Trace les chemins
	updateRender(window,map);
	updateRender(window, castle);
	updateRender(window, listEnemy);
	updateRender(window, idClient);
	updateRender(window, listTurret);
	updateRender(window, gold);
	for (int i = 0; i < listTurret.size(); i++)
	{
		updateRender(window, listTurret[i].getListMissile());
	}
	window->display();
	window->clear();

}

Enemy GameState::cible(Turret t)
{
	int d1;
	Enemy tmp=listEnemy[0];
	d1 = sqrt(powf(listEnemy[0].getCenter().x - t.getPos().x, 2) + powf(listEnemy[0].getCenter().y - t.getPos().y, 2));
	for (int b = 1; b < listEnemy.size(); b++)
	{
		if (d1 > sqrt(powf(listEnemy[b].getCenter().x - t.getPos().x, 2) + powf(listEnemy[b].getCenter().y - t.getPos().y, 2)))
		{
			d1 = sqrt(powf(listEnemy[b].getCenter().x - t.getPos().x, 2) + powf(listEnemy[b].getCenter().y - t.getPos().y, 2));
			tmp = listEnemy[b];
		}
	}
	return tmp;
}

void GameState::collide()
{
	for (int t=0;t<listEnemy.size();t++)
	{
		if ((listEnemy[t].getCenter().y + listEnemy[t].getHitbox()/2) > 500 && listEnemy[t].getCenter().x==400 && castle.getAlive())
		{
			listEnemy[t].setAlive(false);
			castle.updateCastleUponCollision();
		}
		for (int y = 0; y < listTurret.size(); y++)
		{
			for (int f = 0; f < listTurret[y].getListMissile().size(); f++)
			{
				if (sqrt(powf(listEnemy[t].getCenter().x - listTurret[y].getListMissile()[f].getPos().x, 2) + powf(listEnemy[t].getCenter().y - listTurret[y].getListMissile()[f].getPos().y, 2))<=listEnemy[t].getHitbox())
				{
					listEnemy[t].takeDamage(listTurret[y].getDamage());
					listTurret[y].getListMissile().erase(listTurret[y].getListMissile().begin()+f);
				}
				else 
				{
					if (listTurret[y].getListMissile()[f].getPos().x > 800|| listTurret[y].getListMissile()[f].getPos().y > 600)
					{
						listTurret[y].getListMissile().erase(listTurret[y].getListMissile().begin()+f);
					}
				}
			}
		}
	}
}

Gold& GameState::getGold()
{
	return gold;
}

void GameState::increaseLevel() {
	level++;
	for (int i = 0; i < listEnemy.size(); i++) {
		listEnemy[i].setLevel(level);
	}
}