#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include <iostream>
#include <string>
#include <sstream>
#include "level.h"
#include <math.h>

void Game::Start(void)
{
	if(_gameState != Uninitialized)
	{
		return;
	}
	_mainWindow.create(sf::VideoMode(400,500,32), "Snake");

	_gameState = Game::ShowingSplash;

	while(!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if(_gameState == Game::Exiting)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::GameLoop()
{
	sf::Event currentEvent;

	while(_mainWindow.pollEvent(currentEvent))
	{
		switch(_gameState)
		{
		case Game::ShowingSplash:
			ShowSplashScreen();
			break;

		case Game::ShowingMenu:
			ShowMenu();
			break;

		case Game::Playing:
			PlayGame();
			break;

		case Game::Exiting:
			_mainWindow.close();
			break;

		case Game::Paused:
			//Nothing for now
			break;

		case Game::Uninitialized:
			//Obviously nothing lol
			break;
		}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
		case MainMenu::Exit:
			_gameState = Exiting;
			break;

		case MainMenu::Play:
			_gameState = Playing;
			break;

		case MainMenu::Nothing:
			break;
	}
}

void Game::PlayGame()
{
	_mainWindow.clear(sf::Color::White);
	_mainWindow.setFramerateLimit(600);
	sf::Clock GameClock;

	Snake GameSnake(&_mainWindow);
	Food GameFood(&_mainWindow);

	Food GameSpecialFood(&_mainWindow);
	GameSpecialFood.setSpecialRandPositions();
	bool sFoodEaten = false;
	bool sFoodSpawn = false;


	std::string dir = "Left";

	bool Collision = false;

	/*
	Level map;
	map.LoadFromFile("Images/Snake.tmx");
	map.SetDrawingBounds(sf::FloatRect(0.f, 0.f, 400.f, 400.f));
	*/

	sf::Font font;
	font.loadFromFile("Fonts/Ubuntu-C.ttf");

	sf::Text text;
	text.setPosition(sf::Vector2f(10,425));
	text.setColor(sf::Color::White);
	text.setFont(font);

	sf::RectangleShape wall(sf::Vector2f(400,5));

	wall.setPosition(0,405);

	_mainWindow.setFramerateLimit(18);

	sf::Clock timer;

	GameClock.restart();
	while(!Collision)
	{
		if(GameSnake.getFoodCollision(GameFood))
		{
			_mainWindow.clear();
			GameFood.setRandPositions();
		}
		if(GameSnake.getSpecialFoodCollision(GameSpecialFood) && sFoodSpawn)
		{
			_mainWindow.clear();
		}

		if(GameSnake.Score>1 && GameSnake.Score%5==0)
		{
			if(sFoodEaten==false && sFoodSpawn==false)
			{
				GameSpecialFood.SpawnSpecialFood();
				sf::Clock timer;
				timer.restart();
				sFoodSpawn=true;
			}
			else if(sFoodSpawn && timer.getElapsedTime().asSeconds()<=10)
			{
				GameSpecialFood.SpawnSpecialFood();
			}
			else if(timer.getElapsedTime().asSeconds()>10)
			{
				_mainWindow.clear();
			}
		}

		Collision = GameSnake.getSelfCollision();

		GameSnake.getScreenCollision();

		GameSnake.drawSnake();
		GameFood.drawFood();

		float timeInSecs = GameClock.getElapsedTime().asSeconds();
		std::string score = std::to_string(GameSnake.Score);
		score = "Score: " + score +
				"\nTime: " + std::to_string((int)timeInSecs) + "s";
		text.setString(score);

		_mainWindow.draw(text);
		_mainWindow.draw(wall);
		_mainWindow.display();

		sf::Event event;
		while(_mainWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				_gameState = Exiting;
				break;
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				dir = GameSnake.getDirection(event);
			}
		}
		GameSnake.setDirection(dir);
		if(_gameState==Exiting)
		{
			break;
		}
	}
	_gameState = Exiting;
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
