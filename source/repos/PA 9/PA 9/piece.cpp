#include "piece.h"


piece::piece(char newColor, sf::Vector2f newPos, sf::Texture newTexture, int newClicked) : color(newColor), pos(newPos), sprite(newTexture), clicked(newClicked) {}

piece::~piece()
{

}

char& piece::getColor()
{
	return color;
}

sf::Vector2f& piece::getPosition() 
{
	return pos;
}

sf::Sprite& piece::getSprite()
{
	return sprite;
}

int& piece::getclicked()
{
	return clicked;
}

void piece::setColor(char newColor)
{
	this->color = newColor;
}

void piece::setPosition(sf::Vector2f newPosition)
{
	this->pos = newPosition;
}

void piece::setSprite(sf::Sprite newSprite)
{
	this->sprite = newSprite;
}

void piece::setClicked(int newClicked)
{
	this->clicked = newClicked;
}
