#include "pawn.h"

pawn::pawn() {

	sf::Texture white_pawn_sprite;

	if (!white_pawn_sprite.loadFromFile("Sprites/w_pawn_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_pawn_png_128px.png" << std::endl;
		return;
	}

	sprite(white_pawn_sprite);



}

void pawn::move() {

	// move forward one or two squares
	// move diagonal if capturing piece

}

int pawn::checkMove() const {

		// check if pawn is in original position
		// if true, allow two square move
		// Else, move one forward, or one diagonal if capturing

}