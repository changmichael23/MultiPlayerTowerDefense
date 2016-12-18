#pragma once
#include <SFML/Graphics.hpp>


class Enemy
{
private:
	std::vector<sf::Vector3i> spawns;
	int posX,posY,dir,num,life,maxLife, goldValue, level;
	float hitbox;
	bool alive;

public:
	//Constructeur
	Enemy(std::vector<sf::Vector3i> s, int n, int l);

	//Accesseurs
	//GET
	std::vector<sf::Vector3i>& getEnemy();
	sf::Vector2i& getCenter();
	float& getHitbox();
	int& getDir();
	int& getNum();
	int& getLife();
	int& getMaxLife();
	int& getGoldValue();
	int& getLevel();
	sf::Vector2i& getPosition();
	bool& getAlive();
	

	//SET
	void setLife(int l);
	void setDir(int d);
	void setAlive(bool b);
	void setGoldValue(int g);
	void setLevel(int l);

	//Methodes
	void updateDir();
	void nextMove();
	void takeDamage(int damage);
};