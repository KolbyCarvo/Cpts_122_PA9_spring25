#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class piece {

protected:

	char color;
	sf::Sprite sprite;
	sf::Vector2f pos;
	int clicked;
	int has_moved;

public:
	piece(char newColor = '\0', sf::Vector2f newPos = sf::Vector2f(), sf::Texture newTexture = sf::Texture(),int clicked = -1, int has_moved = 0);
	~piece();

	char& getColor();
	sf::Vector2f& getPosition();
	sf::Sprite& getSprite();
	int& getclicked();

	void setColor(char newColor);
	void setPosition(sf::Vector2f newPosition);
	void setSprite(sf::Sprite newSprite);
	void setClicked(int newClicked);

	virtual int check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale) = 0;
	virtual void move(int type, int& scale) = 0;
	virtual int determine_move(sf::Vector2f next_position, int& scale) = 0;

};
