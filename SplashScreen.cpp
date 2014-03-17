#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
	sf::Texture texture;
	if(texture.loadFromFile("Images/Snake.png") != true)
	{
		return;
	}
	sf::Sprite sprite(texture);

	renderWindow.setPosition(sf::Vector2i(100,100));
	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed
		    || event.type == sf::Event::MouseButtonPressed
		    || event.type == sf::Event::Closed )
			{
				return;
			}
		}
	}
}
