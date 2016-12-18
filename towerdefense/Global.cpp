#include "Global.hpp"

sf::RectangleShape line(int x, int y, int width, int length) {

	sf::RectangleShape rect(sf::Vector2f(width, length));
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color(150, 0, 200, 255));
	return rect;
}
