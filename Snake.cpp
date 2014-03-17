#include "Snake.h"
#include <iostream>

Snake::Snake(sf::RenderWindow *mainwindow)
{
	pX = 200;
	pY = 200;
	Snake::gamewindow = mainwindow;
	Score = 0;
	Direction = "Left";
	SnakeLimit = 5;
	TheSnake.setFillColor(sf::Color::Green);
	TheSnake.setSize(sf::Vector2f(10,10));
}

std::string Snake::getDirection(sf::Event event)
{
	if(event.key.code==sf::Keyboard::Up)
	{
		if(Direction=="Down")
		{
			//do nothing
		}
		else
		{
			Direction="Up";
		}
	}
	else if(event.key.code==sf::Keyboard::Down)
	{
		if(Direction=="Up")
		{
			//do nothing
		}
		else
		{
			Direction="Down";
		}
	}
	else if(event.key.code==sf::Keyboard::Left)
	{
		if(Direction=="Right")
		{
			//do nothing
		}
		else
		{
			Direction="Left";
		}
	}
	else if(event.key.code==sf::Keyboard::Right)
	{
		if(Direction=="Left")
		{
			//do nothing
		}
		else
		{
			Direction="Right";
		}
	}
	return Direction;
}

void Snake::setDirection(std::string Directions)
{
	if(Directions=="Up")
	{
		pY-=11;
	}
	else if(Directions=="Down")
	{
		pY+=11;
	}
	else if(Directions=="Left")
	{
		pX-=11;
	}
	else if(Directions=="Right")
	{
		pX+=11;
	}
	SnakeSizeX.push_back(pX);
	SnakeSizeY.push_back(pY);
	SnakeTail.push_back(sf::Vector2f(pX,pY));
	setSnakeSize();
}

void Snake::setSnakeSize(void)
{
	if(SnakeSizeX.size()>SnakeLimit && SnakeSizeY.size()>SnakeLimit)
	{
		SnakeSizeX.erase(SnakeSizeX.begin());
		SnakeSizeY.erase(SnakeSizeY.begin());
	}
}

bool Snake::getFoodCollision(Food food)
{
	if(TheSnake.getGlobalBounds().intersects(food.TheFood.getGlobalBounds()))
	{
		Score++;
		SnakeLimit+=1;
		return true;
	}
	else
	{
		return false;
	}
}

bool Snake::getSpecialFoodCollision(Food food)
{
	if(TheSnake.getGlobalBounds().intersects(food.SpecialFood.getGlobalBounds()))
	{
		Score+=10;
		return true;
	}
	else
	{
		return false;
	}
}

void Snake::drawSnake(void)
{
	gamewindow->clear();
	if(SnakeSizeX.size()==0)
	{
		TheSnake.setPosition(pX, pY);
		gamewindow->draw(TheSnake);
	}
	for(unsigned int i=0; i!=SnakeSizeX.size(); i++)
	{
		TheSnake.setPosition(SnakeSizeX[i], SnakeSizeY[i]);
		gamewindow->draw(TheSnake);
	}
}

void Snake::getScreenCollision(void)
{
	if(pX>=400)
	{
		pX=0;
	}
	else if(pX<=0)
	{
		pX=400;
	}
	else if(pY>=400)
	{
		pY=0;
	}
	else if(pY<=0)
	{
		pY=400;
	}
}

bool Snake::getSelfCollision(void)
{
	bool Collision = false;
	if(SnakeSizeX.size()<SnakeLimit)
	{
		//Do nothing for now
	}
	else if(SnakeSizeX.size()==SnakeLimit && SnakeSizeY.size()==SnakeLimit)
	{
		for(unsigned int i=0; i<SnakeSizeX.size()-1; ++i)
		{
			if(pX == SnakeSizeX[i] && pY == SnakeSizeY[i])
			{
				Collision = true;
				break;
			}
			else
			{
				Collision = false;
			}
		}
	}
	return Collision;
}
