#pragma once
#include "piece.h"

class king : public piece {

private:

public:
	int determine_move(sf::Vector2f next_position, int& scale) override;

	void move(int type, int& scale) override;

};