#include <SFML/Graphics.hpp>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Missile
{
public:
	//Constructeurs
	Missile();
	Missile(sf::Vector2i position, float a);

	//accesseurs
	sf::Vector2i getPos();
	float getAngle();
	int getVelocity();
	void setAlive(bool newStatus);
	bool getAlive();

	//methodes
	//Calcul de la trajectoire
	void nextMove();

private:
	float angle;
	sf::Vector2i pos;
	int velocity;
	bool alive;
};