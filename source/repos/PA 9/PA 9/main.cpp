#include "Header.h"

int main(void)
{
	unsigned int width = 1006;
	unsigned int height = 1006;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Chess PA 9");
	window->setFramerateLimit(60);

	
	while (window->isOpen())
	{
		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window->close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window->close();
				}
			}
		}

		window->clear();

		make_board(window);

		window->display();
	}

	delete window;
	return 0;
}