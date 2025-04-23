#include "piece.h"
#include "pawn.h"

void pawn::move(int type)
{
	switch (type)
	{
	case(1): //up 1
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 113.0f });
		break;
	case(2): //up 2
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 2 * 113.0f });
		break;
	case(3): // capture left
		sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 113.0f });
		break;
	case(4): // capture right
		sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 113.0f });
		break;
	}
}

int pawn::determine_move(sf::Vector2f next_position)
{
	int difference_x = 0, difference_y = 0;
	difference_x = (int)(pos.x / 113) - (int)(next_position.x / 113);
	difference_y = (int)(pos.y / 113) - (int)(next_position.y / 113);

	if (difference_x == 0 && difference_y == 1)
	{
		return 1; // up 1
	}
	else if (difference_x == 0 && difference_y == 2)
	{
		return 2; // up 2
	}
	else if (difference_x == 1 && difference_y == 1)
	{
		return 3; // capture left
	}
	else if (difference_x == -1 && difference_y == 1)
	{
		return 4; // capture right
	}
	else
	{
		return 0; // invalid
	}
}