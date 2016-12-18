#include <SFML/Graphics.hpp>

class Gold
{
private:
	int gold;

public:
	//Constructeurs
	Gold();
	Gold(int g);

	//accesseurs
	int& getGold();
	void setGold(int g);
	int& getCost();
	void setCost(int g);

	//methodes
	bool decreaseGold(int value);
	void increaseGold(int value);
};