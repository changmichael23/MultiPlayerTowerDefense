#include "RenderCastle.hpp"

void updateRender(sf::RenderWindow *window, Castle& castle) {
	sf::Texture texture;
	texture.loadFromFile("Texture/Chateau.png");


	if (castle.getAlive())
	{
		sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(castle.getHitbox(), castle.getHitbox()));
		rect.setTexture(&texture);
		rect.setPosition(castle.getPos().x - castle.getHitbox() / 2, castle.getPos().y - castle.getHitbox() / 2);
		window->draw(rect);
	}
}