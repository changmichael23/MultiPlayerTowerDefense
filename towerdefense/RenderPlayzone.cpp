#include "RenderPlayzone.hpp"

void updateRender(sf::RenderWindow * window, int idClient) {
	sf::RectangleShape rect;
	switch (idClient) {
	case 0:
		rect = sf::RectangleShape(sf::Vector2f(200, 400));
		rect.setPosition(200,200);
		break;
	case 1:
		rect = sf::RectangleShape(sf::Vector2f(200, 400));
		rect.setPosition(400, 200);
		break;

	case 2:
		rect = sf::RectangleShape(sf::Vector2f(200, 200));
		rect.setPosition(0, 0);
		break;
	case 3:
		rect = sf::RectangleShape(sf::Vector2f(200, 200));
		rect.setPosition(0, 200);
		break;
	case 4:
		rect = sf::RectangleShape(sf::Vector2f(200, 200));
		rect.setPosition(0, 400);
		break;
	case 5:
		rect = sf::RectangleShape(sf::Vector2f(200, 200));
		rect.setPosition(600, 0);
		break;
	case 6:
		rect = sf::RectangleShape(sf::Vector2f(200, 200));
		rect.setPosition(600, 200);
		break;
	case 7:
		rect = sf::RectangleShape(sf::Vector2f(200, 200));
		rect.setPosition(600, 400);
		break;
	}
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(1);
	window->draw(rect);
}
