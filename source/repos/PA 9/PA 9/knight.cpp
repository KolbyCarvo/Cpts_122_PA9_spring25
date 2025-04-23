#include "knight.h"

int knight::checkMove() const {

	// check if move is valid L shape
	// no need to check for other pieces in the way
	// iterate through array of available squares??
	return 0;
}

void knight::move(int moveChoice) {

	if (moveChoice == 1) {

		piece.setPosition({ piece.getPosition().x - 113.0f, piece.getPosition().y + 226.0f });
		return;

	}

	if (moveChoice == 2) {

		piece.setPosition({ piece.getPosition().x + 113.0f, piece.getPosition().y + 226.0f });
		return;

	}

	if (moveChoice == 3) {

		piece.setPosition({ piece.getPosition().x - 113.0f, piece.getPosition().y - 226.0f});
		return;

	}

	if (moveChoice == 4) {

		piece.setPosition({ piece.getPosition().x - 113.0f, piece.getPosition().y - 226.0f });
		return;

	}

	if (moveChoice == 5) {

		piece.setPosition({ piece.getPosition().x - 226.0f, piece.getPosition().y + 113.0f });
		return;

	}

	if (moveChoice == 6) {

		piece.setPosition({ piece.getPosition().x + 226.0f, piece.getPosition().y + 113.0f });
		return;

	}

	if (moveChoice == 7) {

		piece.setPosition({ piece.getPosition().x - 226.0f, piece.getPosition().y - 113.0f });
		return;

	}

	if (moveChoice == 8) {

		piece.setPosition({ piece.getPosition().x + 226.0f, piece.getPosition().y - 113.0f });
		return;

	}

}