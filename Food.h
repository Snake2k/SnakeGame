#ifndef FOOD_H_
#define FOOD_H_
#include <SFML/Graphics.hpp>

class Food
{
	private:
		sf::RenderWindow *gamewindow;
		int fX;
		int fY;
		int sfX;
		int sfY;

	public:
		Food(sf::RenderWindow *mainwindow);
		sf::RectangleShape TheFood;
		sf::CircleShape SpecialFood;
		void drawFood(void);
		void setRandPositions(void);
		void setSpecialRandPositions(void);
		void SpawnSpecialFood(void);
};

#endif
