#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class piece {

protected:

	char color;
	sf::Sprite sprite;
	sf::Vector2f pos;

public:
	piece(char newColor = '\0', sf::Vector2f newPos = sf::Vector2f(), sf::Texture newTexture = sf::Texture());
	~piece();

	char& getColor();
	sf::Vector2f& getPosition();
	sf::Sprite& getSprite();

	void setColor(char newColor);
	void setPosition(sf::Vector2f newPosition);
	void setSprite(sf::Sprite newSprite);

};
