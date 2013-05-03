#include "Food.h"
#include <random>

Food::Food(sf::RenderWindow *mainwindow)
{
	Food::gamewindow = mainwindow;
	TheFood.setFillColor(sf::Color::Red);
	TheFood.setSize(sf::Vector2f(10,10));
	setRandPositions();
}

void Food::setRandPositions(void)
{
    srand(time(NULL));
    fX = (rand() % 800);
    fY = (rand() % 600);
	TheFood.setPosition(fX, fY);
}

void Food::drawFood(void)
{
	gamewindow->draw(TheFood);
}
