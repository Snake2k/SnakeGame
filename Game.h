#ifndef GAME_H_
#define GAME_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Game
{
	public:
		static void Start();

	private:
		static bool IsExiting();
		static void GameLoop();

		static void ShowSplashScreen();
		static void ShowMenu();
		static void PlayGame();

		enum GameState { Uninitialized, ShowingSplash, Paused,
						 ShowingMenu, Playing, Exiting};

		static GameState _gameState;
		static sf::RenderWindow _mainWindow;
};

#endif
