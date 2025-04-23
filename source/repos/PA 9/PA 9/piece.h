#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class piece {

protected:

	char color;
	sf::Sprite sprite;
	sf::Vector2f pos;
	int clicked;

public:
	piece(char newColor = '\0', sf::Vector2f newPos = sf::Vector2f(), sf::Texture newTexture = sf::Texture(),int clicked = -1);
	~piece();

	char& getColor();
	sf::Vector2f& getPosition();
	sf::Sprite& getSprite();
	int& getclicked();

	void setColor(char newColor);
	void setPosition(sf::Vector2f newPosition);
	void setSprite(sf::Sprite newSprite);
	void setClicked(int newClicked);

	virtual void move(int type, int& scale) = 0;
	virtual int determine_move(sf::Vector2f next_position, int& scale) = 0;

};
