#pragma once
#include "piece.h"

class knight : public piece {

private:

public:

	void move(int type);

	int determine_move(sf::Vector2f next_position);
};