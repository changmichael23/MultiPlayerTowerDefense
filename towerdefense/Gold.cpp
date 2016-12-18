#include "Gold.hpp"


Gold::Gold()
{
	gold = 300;
}

Gold::Gold(int g)
{
	gold = g;
}

int& Gold::getGold()
{
	return gold;
}

void Gold::setGold(int g)
{
	gold = g;
}

bool Gold::decreaseGold(int value) {
	if (gold - value >= 0) {
		gold -= value;
		return true;
	}
	return false;
}

void Gold::increaseGold(int value)
{
	gold += value;
}

