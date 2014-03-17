#include "MainMenu.h"
#include <iostream>

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	sf::Texture texture;
	if(!texture.loadFromFile(("Images/Mainmenu.png")))
	{
		std::cout << "Error loading Mainmenu.png";
	}
	sf::Sprite sprite(texture);

	MenuItem playButton;
	playButton.rect.top = 0;
	playButton.rect.height = 250;
	playButton.rect.left = 0;
	playButton.rect.width = 400;
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect.top = 251;
	exitButton.rect.height = 500;
	exitButton.rect.left = 0;
	exitButton.rect.width = 400;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for( it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if(menuItemRect.height > y &&
		   menuItemRect.top < y &&
		   menuItemRect.left < x &&
		   menuItemRect.width > x)
		{
			return (*it).action;
		}
	}
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while(true)
	{
		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
	return Nothing;
}
