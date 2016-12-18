#include "RenderMap.hpp"


void updateRender(sf::RenderWindow *window, MapTW map)
{
	sf::RectangleShape l;
	for (int i = 0; i<7; i++)
	{
		l = line(map.getPoints()[i].x, map.getPoints()[i].y, 50, 300);			

		if (map.getPoints()[i].z == 1)											
		{
			l.rotate(180);

		}
		if (map.getPoints()[i].z == 2)											
		{
			l.rotate(90);

		}
		if (map.getPoints()[i].z == 3)											
		{
			l.rotate(270);

		}
		window->draw(l);
	}
}