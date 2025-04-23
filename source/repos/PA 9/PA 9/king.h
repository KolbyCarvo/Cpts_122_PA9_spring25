#pragma once
#include "piece.h"

class king : public piece {

private:

public:
	int determine_move(sf::Vector2f next_position);

	void move(int type);

};