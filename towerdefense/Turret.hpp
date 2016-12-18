#include <SFML/Graphics.hpp>
//#include "Missile.hpp"
#include "RenderMissile.hpp"
#include <vector>

class Turret
{
private:
	sf::Vector2i pos;
	float angle;
	bool alive;
	bool fireM;
	std::vector<Missile> listMissile;
	float hitbox;
	int damage, range, cost;

public:
//Constructeur vide, tourelle n'existe pas encore
	Turret();
	Turret(sf::Vector2i position);

//accesseurs
	//get
	std::vector<Missile>& getListMissile();
	float& getAngle();
	float& getHitbox();
	sf::Vector2i& getPos();
	int& getDamage();
	int& getRange();
	int& getCost();

	//set
	void setAlive(bool newAlive);
	void setPos(sf::Vector2i newPos);
	void setAngle(float a);
	void setAngle(sf::Vector2i cible);
	void setFire(bool b);
	void setDamage(int d);
	void setRange(int r);
	void setCost(int c);

//méthodes
	//Tir consiste a juste active le missile, ne fait pas bouger le missile
	void fire();
	//update l'angle de la tourelle est les missiles associés à celle ci
	void updateTurret(sf::Vector2i cible);
};



