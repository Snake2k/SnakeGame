#ifndef SNAKE_H_
#define SNAKE_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Food.h"

class Snake
{
	private:
		sf::RenderWindow *gamewindow;
		sf::RectangleShape TheSnake;
		std::vector<int> SnakeSizeX;
		std::vector<int> SnakeSizeY;
		unsigned int SnakeLimit;
		int pX;
		int pY;
		std::string Direction;
		std::vector<sf::Vector2f> SnakeTail;

	public:
		int Score;
		Snake(sf::RenderWindow *mainwindow);
		std::string getDirection(sf::Event event);
		void setDirection(std::string Directions);
		void setSnakeSize(void);
		bool getFoodCollision(Food food);
		bool getSpecialFoodCollision(Food food);
		void drawSnake(void);
		void getScreenCollision(void);
		bool getSelfCollision(void);
};
#endif
