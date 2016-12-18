#include "RenderMissile.hpp"

void updateRender(sf::RenderWindow *window, Missile& missile){
	sf::CircleShape ball = sf::CircleShape(5, 500);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(missile.getPos().x, missile.getPos().y);
	ball.setRotation(missile.getAngle());
	window->draw(ball);
}

void updateRender(sf::RenderWindow *window, std::vector<Missile>& missile) {
	sf::CircleShape ball = sf::CircleShape(5, 500);
	ball.setFillColor(sf::Color::Red);
	for (int i = 0; i < missile.size(); i++) {
		ball.setPosition(missile[i].getPos().x, missile[i].getPos().y);
		ball.setRotation(missile[i].getAngle());
		window->draw(ball);
	}
}