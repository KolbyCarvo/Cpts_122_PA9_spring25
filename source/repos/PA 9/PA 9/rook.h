#pragma once
#include "piece.h"

class rook : public piece {

private:

public:	

	void move(int type, int& scale) override;

	int determine_move(sf::Vector2f next_position, int &scale) override;

};
