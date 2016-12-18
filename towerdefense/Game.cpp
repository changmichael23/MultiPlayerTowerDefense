#include "Game.hpp"

//constructeurs
Game::Game() 
{
	sf::Vector2i positionSouris = sf::Vector2i();
	MapTW map = MapTW();
	GameState g = GameState();
}
Game::~Game() {}

//accesseurs
sf::Vector2i& Game::getPositionSouris()
{
	return positionSouris;
}
GameState& Game::getGamestate() {
	return g;
}
void Game::setPositionSouris(sf::Vector2i newPos) {
	positionSouris = newPos;
}

//methodes
void Game::init(sf::RenderWindow *window)
{
	window->clear();
	window->create(sf::VideoMode(800, 600), "TowerDefense");
	window->setFramerateLimit(60);
}
void Game::clicksouris(sf::RenderWindow *window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		click = true;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click)
	{
		click = false;
		positionSouris = sf::Mouse::getPosition(*window);
	}
}
void Game::createTower(sf::Vector2i cible, int id)
{
	g.createTower(cible, id);
}
void Game::gameLoop(sf::RenderWindow *window)
{
	for(int j=0; j<20; j++)
	{
		if ((g.getCpt() / 120 > g.getMaxLvl() && g.getListEnemy().size() == 0) || g.getCastle().getAlive() == false) {
			exit(0);
		}
		if (g.getCpt() % 1200 == 0) {
			g.increaseLevel();
		}
		if (g.getCpt() % 120 == 0 && g.getCpt() / 120 < g.getMaxLvl()) {
			g.getListEnemy().push_back(Enemy(g.getMap().getSpawns(), g.getMap().getNextEnemySpawns(),g.getLevel()));
		}
		g.setCpt(g.getCpt() + 1);
		sf::Event event;
		clicksouris(window);
		g.nextGameState();
		updateRenderGame(window);
		// Fermer fenetre
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				exit(0);
			}
		}
	}
}
void Game::updateRenderGame(sf::RenderWindow * window)
{
	g.updateRenderGamestate(window);
}

