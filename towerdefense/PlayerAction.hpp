#pragma once
#include "SFML\Graphics.hpp"

enum Action {
	NEW_TOWER = 0,
	UPGRADE_TOWER = 1,
	DESTROY_TOWER = 2,
	SEND_MSG = 3
};

class PlayerAction {
public:
	//constructeurs

	//accesseurs
	//get
	Action getAction();
	//set
	void setAction(Action newAction);

	//méthodes
	void updatePlayerAction(sf::RenderWindow * window);

private:
	Action action;
	sf::Vector2i mouseClick;
	//....

};
