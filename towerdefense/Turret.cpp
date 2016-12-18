#include "Turret.hpp"

//constructeurs
Turret::Turret() 
{
	fireM = true;
	angle = 0;
	alive = false;
	hitbox = 20.0f;
	damage = 1;
	range = 140;
	cost = 50;
}
Turret::Turret(sf::Vector2i position) {
	fireM = true;
	pos = position;
	alive = true;
	angle = 0;
	hitbox = 10.0f;
	damage = 1;
	range = 140;
	cost = 50;
}

//accesseurs
//get
std::vector<Missile>& Turret::getListMissile() {
	return listMissile;
}
float& Turret::getAngle() {
	return angle;
}
sf::Vector2i& Turret::getPos() {
	return pos;
}
float& Turret::getHitbox()
{
	return hitbox;
}
int& Turret::getDamage() {
	return damage;
}
int& Turret::getRange() {
	return range;
}
int& Turret::getCost() {
	return cost;
}

//set
void Turret::setFire(bool b)
{
	fireM = b;
}
void Turret::setAlive(bool newAlive)
{
	alive = newAlive;
}
void Turret::setPos(sf::Vector2i newPos)
{
	pos = newPos;
}
void Turret::setAngle(float a)
{
		angle = a;
}
void Turret::setAngle(sf::Vector2i cible) {
	setAngle(fmod((atan2((cible.y - this->pos.y), (cible.x - this->pos.x)) * 180 / M_PI + 270), 360));
}
void Turret::setDamage(int d) {
	damage = d;
}
void Turret::setRange(int r) {
	this->range = r;
}
void Turret::setCost(int c) {
	this->cost = c;
}

//méthodes
void Turret::fire()
{
	if (fireM)
	{
		Missile newMissile = Missile(pos, angle);
		listMissile.push_back(newMissile);
	}
}
void Turret::updateTurret(sf::Vector2i cible)
{
	setAngle(cible);
	for (int i = 0; i < listMissile.size(); i++) {
		listMissile[i].nextMove();
		if (listMissile[i].getAlive() == false) {
			listMissile.erase(listMissile.begin()+i);
			i--;
		}
	}
}