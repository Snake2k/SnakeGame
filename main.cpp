#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow GameWindow(sf::VideoMode(800,600,32), "Snake");

	Snake GameSnake(&GameWindow);
	Food GameFood(&GameWindow);

	std::string dir="Left";

	while(GameWindow.isOpen())
	{
		if(GameSnake.getFoodCollision(GameFood))
		{
			GameWindow.clear();
			GameFood.setRandPositions();
		}
		GameSnake.getScreenCollision();
		GameSnake.getSelfCollision();
		GameSnake.drawSnake();
		GameFood.drawFood();
		GameWindow.display();
		sf::Event event;
		while(GameWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				GameWindow.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				dir = GameSnake.getDirection(event);
			}
		}
		GameSnake.setDirection(dir);
	}
}
