#include "piece.h"

class pawn : public piece {

private:

	sf::Sprite sprite;

public:

	pawn();

	void move();

	int checkMove() const;

};