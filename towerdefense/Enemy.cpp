#include "Enemy.hpp"

//CONSTRUCTEUR
Enemy::Enemy(std::vector<sf::Vector3i> s, int n, int l)
{
	maxLife = 4;
	life = 4;
	spawns = s;
	posX = s[n].x;
	posY = s[n].y;
	dir = s[n].z;
	num = n;
	hitbox = 30.0f;
	alive = true;
	setLevel(l);
}

//GET
std::vector<sf::Vector3i>& Enemy::getEnemy()
{
	return spawns;
}
sf::Vector2i& Enemy::getPosition()
{
	return sf::Vector2i(posX,posY);
}
sf::Vector2i& Enemy::getCenter()
{
	return sf::Vector2i(posX + hitbox / 2, posY + hitbox / 2);
}
int& Enemy::getDir() {
	return dir;
}
int& Enemy::getNum() {
	return num;
}
int& Enemy::getLife() {
	return life;
}
int& Enemy::getMaxLife() {
	return maxLife;
}
int& Enemy::getGoldValue() {
	return goldValue;
}
int& Enemy::getLevel() {
	return level;
}
float& Enemy::getHitbox()
{
	return hitbox;
}
bool& Enemy::getAlive() {
	return alive;
}

//SET
void Enemy::setLife(int l) {
	life = l;
}
void Enemy::setDir(int d)
{
		dir = d;
}
void Enemy::setAlive(bool b)
{
	alive = b;
}
void Enemy::setGoldValue(int g) {
	goldValue = g;
}
void Enemy::setLevel(int l) {
	level = l;
	goldValue = level * 5;
	life = (4 * level) - (maxLife - life);
	maxLife = 4 * level;
}

//METHODES
void Enemy::takeDamage(int damage) {
	life -= damage;
	if (life <= 0) {
		this->setAlive(false);
	}
}

void Enemy::nextMove()
{
	updateDir();
	if (dir == 0) {
		posY++;
	}
	if (dir == 1) {
		posY--;
	}
	if (dir == 2) {
		posX--;
	}
	if (dir == 3) {
		posX++;
	}
}

void Enemy::updateDir()
{
	for (int i = 0; i < 7; i++) {
		if (getPosition().x == spawns[i].x  && getPosition().y == spawns[i].y) {
			setDir(spawns[i].z);
			break;
		}
	}
}
