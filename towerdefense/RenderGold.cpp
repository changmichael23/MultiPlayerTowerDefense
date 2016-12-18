#include "RenderGold.hpp"
#include <iostream>
#include <string>

void updateRender(sf::RenderWindow *window, Gold& gold)
{
	sf::String s="Gold : ";
	s = s + std::to_string(gold.getGold());

	sf::Font font;
	if (!font.loadFromFile("Asimov.otf"))
		std::cout << " error while loading font" << std::endl;

	sf::Text text(s,font,40);
	text.move(sf::Vector2f(300,0));
	window->draw(text);
}
