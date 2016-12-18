#include "RenderTower.hpp"

void updateRender(sf::RenderWindow *window, Turret& tower) {
	sf::Texture texture;
	texture.loadFromFile("Texture/TowerT.png");
	
		sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(tower.getHitbox()/2, tower.getHitbox()));
		rect.setTexture(&texture);
		sf::CircleShape turret = sf::CircleShape(tower.getHitbox());
		turret.setFillColor(sf::Color::Blue);

		rect.setRotation(tower.getAngle());
		rect.setPosition(tower.getPos().x, tower.getPos().y);

		turret.setPosition(tower.getPos().x - tower.getHitbox(), tower.getPos().y - tower.getHitbox());
		window->draw(turret);
		window->draw(rect);
		
	
}

void updateRender(sf::RenderWindow *window, std::vector<Turret>& tower) {
	sf::Texture texture;
	texture.loadFromFile("Texture/TowerT.png");
	sf::RectangleShape rect;
	sf::CircleShape turret;
	
		for (int i = 0; i < tower.size(); i++) {
			turret = sf::CircleShape(tower[0].getHitbox());
			turret.setFillColor(sf::Color::Blue);
			rect = sf::RectangleShape(sf::Vector2f(tower[0].getHitbox() / 2, tower[0].getHitbox()));
			rect.setTexture(&texture);
			rect.setRotation(tower[i].getAngle());
			rect.setPosition(tower[i].getPos().x , tower[i].getPos().y);
			turret.setPosition(tower[i].getPos().x - tower[i].getHitbox(), tower[i].getPos().y - tower[i].getHitbox());
			window->draw(turret);
			window->draw(rect);
			
		}
	
}