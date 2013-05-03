#include "Snake.h"
#include <iostream>

Snake::Snake(sf::RenderWindow *mainwindow)
{
	pX = 400;
	pY = 300;
	Snake::gamewindow = mainwindow;
	Score = 0;
	Direction = "Left";
	SnakeLimit = 50;
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
		pY--;
	}
	else if(Directions=="Down")
	{
		pY++;
	}
	else if(Directions=="Left")
	{
		pX--;
	}
	else if(Directions=="Right")
	{
		pX++;
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
		SnakeLimit+=10;
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
	if(pX>=800)
	{
		pX=0;
	}
	else if(pX<=0)
	{
		pX=800;
	}
	else if(pY>=600)
	{
		pY=0;
	}
	else if(pY<=0)
	{
		pY=600;
	}
}

void Snake::getSelfCollision(void)
{
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
				gamewindow->close();
			}
			else
			{
				//do nothing
			}
		}
	}
}
