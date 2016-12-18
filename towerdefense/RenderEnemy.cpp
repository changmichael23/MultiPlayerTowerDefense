#include "RenderEnemy.hpp"

void updateRender(sf::RenderWindow * window, Enemy& enemy)
{
	sf::Texture texture;
	texture.loadFromFile("Texture/Bob.png");
	sf::RectangleShape enemyRect=sf::RectangleShape(sf::Vector2f(30,30));
	enemyRect.setTexture(&texture);
	enemyRect.setPosition(sf::Vector2f(enemy.getPosition()));
	window->draw(enemyRect);
}

void updateRender(sf::RenderWindow * window, std::vector<Enemy>& enemy)
{
	sf::Texture texture;
	texture.loadFromFile("Texture/Bob.png");
	sf::RectangleShape enemyRect = sf::RectangleShape(sf::Vector2f(30, 30));
	enemyRect.setTexture(&texture);
	for each (Enemy e in enemy)
	{
		//on affiche l'ennemi à sa position
		enemyRect.setPosition(sf::Vector2f(e.getPosition()));
		window->draw(enemyRect);
		//pour chaque ennemi on créé une barre de vie en 2 partie (rouge/blanc) pour que la vie perdu soit visible
		sf::RectangleShape lifeBarRedSide = sf::RectangleShape(sf::Vector2f(15*e.getLife()/e.getMaxLife(), 5));
		lifeBarRedSide.setFillColor(sf::Color::Red);
		lifeBarRedSide.setPosition(e.getCenter().x - (15 * e.getLife() / e.getMaxLife())/2, e.getCenter().y-e.getHitbox()/1.2);
		window->draw(lifeBarRedSide);
	}
}