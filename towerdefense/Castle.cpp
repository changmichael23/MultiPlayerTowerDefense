#include "Castle.hpp"


Castle::Castle()
{
	hp = 3;
	posX = 400;
	posY = 600;
	hitbox = 200.0f;
	alive = true;
}

float& Castle::getHitbox()
{
	return hitbox;
}

int& Castle::getHp()
{
	return hp;
}

sf::Vector2f& Castle::getPos()
{
	return sf::Vector2f(posX, posY);
}

void Castle::updateCastleUponCollision()
{
	hp--;
	if (hp == 0)
		setAlive(false);
}

void Castle::setAlive(bool b)
{
	alive = b;
}

bool& Castle::getAlive()
{
	return alive;
}