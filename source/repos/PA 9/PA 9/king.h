#pragma once
#include "piece.h"

class king : public piece {

private:

public:

	int check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale) override;

	int determine_move(sf::Vector2f next_position, int& scale) override;

	void move(int type, int& scale) override;

};