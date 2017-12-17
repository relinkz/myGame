#include "stdafx.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(320, 240);

	sf::Texture texture;
	if (!texture.loadFromFile(ASSETS_PATH + "Test.jpg"))
		std::printf("Error reading texture from file");

	sf::Sprite jinx(texture);
	jinx.setScale(0.8f, 0.8f);

	sf::Vector2u size = texture.getSize();



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(jinx);
		window.display();
	}

	return 0;
}

