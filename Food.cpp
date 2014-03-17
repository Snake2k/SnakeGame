#include "Food.h"
#include <random>

Food::Food(sf::RenderWindow *mainwindow)
{
	Food::gamewindow = mainwindow;
	TheFood.setFillColor(sf::Color::Red);
	TheFood.setSize(sf::Vector2f(10,10));

	SpecialFood.setFillColor(sf::Color::Magenta);
	SpecialFood.setRadius(15.f);

	setRandPositions();
}

void Food::setRandPositions(void)
{
    srand(time(NULL));
    fX = (rand() % 400);
    fY = (rand() % 400);
	TheFood.setPosition(fX, fY);
}

void Food::setSpecialRandPositions(void)
{
    sfX = (rand() % 400);
    sfY = (rand() % 400);
    SpecialFood.setPosition(sfX, sfY);
}

void Food::drawFood(void)
{
	gamewindow->draw(TheFood);
}

void Food::SpawnSpecialFood(void)
{
	gamewindow->draw(SpecialFood);
}
