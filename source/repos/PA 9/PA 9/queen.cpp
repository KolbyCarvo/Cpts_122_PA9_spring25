#include "queen.h"

int queen::checkMove() const {

	// check if move is valid in diagonal line, lateral line, or vertical line
	// check for other pieces in the way (occupied == 1)
	// iterate through array of available squares??
	return 0;
}

void queen::move(int moveChoice, int scale) {

	if (moveChoice == 1) {

		piece.setPosition({ piece.getPosition().x, piece.getPosition().y + 113.0f * scale });
		return;

	}

	if (moveChoice == 2) {

		piece.setPosition({ piece.getPosition().x + 113.0f * scale, piece.getPosition().y + 113.0f * scale });
		return;

	}

	if (moveChoice == 3) {

		piece.setPosition({ piece.getPosition().x + 113.0f * scale, piece.getPosition().y });
		return;

	}

	if (moveChoice == 4) {

		piece.setPosition({ piece.getPosition().x + 113.0f * scale, piece.getPosition().y - 113.0f * scale });
		return;

	}

	if (moveChoice == 5) {

		piece.setPosition({ piece.getPosition().x, piece.getPosition().y - 113.0f * scale });
		return;

	}

	if (moveChoice == 6) {

		piece.setPosition({ piece.getPosition().x - 113.0f * scale, piece.getPosition().y - 113.0f * scale });
		return;

	}

	if (moveChoice == 7) {

		piece.setPosition({ piece.getPosition().x - 113.0f * scale, piece.getPosition().y });
		return;

	}

	if (moveChoice == 8) {

		piece.setPosition({ piece.getPosition().x - 113.0f * scale, piece.getPosition().y + 113.0f * scale });
		return;

	}

}