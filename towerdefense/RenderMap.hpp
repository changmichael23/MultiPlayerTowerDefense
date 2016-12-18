#pragma once
#include "MapTW.hpp"

// Affiche la map par rapport au direction de chaque chemin
// 0 correspond a la direction du bas
// 1 correspond a la direction du haut
// 2 correspond a la direction de gauche
// 3 correspond a la direction de droite
void updateRender(sf::RenderWindow *window, MapTW map);