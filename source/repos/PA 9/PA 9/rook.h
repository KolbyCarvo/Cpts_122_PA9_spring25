#pragma once
#include "piece.h"

class rook : public piece {

private:

public:	

	void move(int type, int scale);

	int determine_move(sf::Vector2f next_position, int &scale);

};
