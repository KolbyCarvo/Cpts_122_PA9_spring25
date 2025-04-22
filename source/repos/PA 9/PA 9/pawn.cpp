#include "piece.h"

piece::piece() {

	this->color = NULL;
	this->pos = position();

}

piece::piece(char newColor, position newPos, sf::Sprite newSprite) {

	this->color = newColor;
	this->pos = newPos;
	this->sprite = newSprite;

}

piece::~piece() {



}

char piece::getColor() const {

	return color;

}

position piece::getPosition() const {

	return pos;

}

void piece::setColor(char newColor) {

	this->color = newColor;

}

void piece::setPosition(position newPosition) {

	this->pos = newPosition;

}

void piece::getMove() const {

	// waits for player to select piece
	// highlights available squares
	// wait for player to select available square using checkMove function
	// adjust capture value for piece if square is occupied by moving piece

}

int piece::checkMove() const {

	// check the square that the player clicks on

}

void piece::move() {

	// adjust piece coordinate values
	// animate piece moving
	// check if any pieces are captured, remove if true

}