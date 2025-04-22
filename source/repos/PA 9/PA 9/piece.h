#include "position.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class piece {

private:

	char color;

	position pos;

	sf::Sprite sprite;

public:

	piece();
	piece(char newColor, position newPos, sf::Sprite newSprite);
	~piece();

	char getColor() const;
	position getPosition() const;

	void setColor(char newColor);
	void setPosition(position newPosition);

	void getMove() const;

	int checkMove() const;

	void move();

};