#include "piece.h"


piece::piece(char newColor, sf::Vector2f newPos, sf::Texture newTexture) : color(newColor),pos(newPos), sprite(newTexture) {}

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
