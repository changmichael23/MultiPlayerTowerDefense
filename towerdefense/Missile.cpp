#include "Missile.hpp"

//Constructeurs
Missile::Missile()
	{
		angle = 0;
		velocity = 0;
		alive = false;
	}
Missile::Missile(sf::Vector2i position, float a)
	{
		pos = position;
		angle = a + 90;
		velocity = 20;
		alive = true;
	}

//Accesseurs
sf::Vector2i Missile::getPos()
	{
		return pos;
	}
int Missile::getVelocity() {
		return velocity;
	}
float Missile::getAngle() {
		return angle;
	}
bool Missile::getAlive(){
	return alive;
}
void Missile::setAlive(bool newStatus) {
	alive = newStatus;
}

//Méthodes
void Missile::nextMove()
	{
		pos.x += cos(angle*M_PI / 180)*velocity;
		pos.y += sin(angle*M_PI / 180)*velocity;
	}
