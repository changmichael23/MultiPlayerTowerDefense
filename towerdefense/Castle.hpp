#pragma once
#include<SFML\Graphics.hpp>

class Castle
{
private:
	int hp;
	float posX,posY;
	float hitbox;
	bool alive;

public:
	int& getHp();
	sf::Vector2f& getPos();
	float& getHitbox();
	
	bool& getAlive();


	Castle();

	void updateCastleUponCollision();
	
	void setAlive(bool b);
};