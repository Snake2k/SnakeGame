#ifndef FOOD_H_
#define FOOD_H_
#include <SFML/Graphics.hpp>

class Food
{
	private:
		sf::RenderWindow *gamewindow;
		int fX;
		int fY;

	public:
		Food(sf::RenderWindow *mainwindow);
		sf::RectangleShape TheFood;
		void drawFood(void);
		void setRandPositions(void);
};

#endif
