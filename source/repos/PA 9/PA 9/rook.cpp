#include "rook.h"

void rook::move(int type, int scale)
{
	switch (type)
	{
	case (1): // Up
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - scale * 113.0f });
		break;
	case (2): // Down
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + scale * 113.0f });
		break;
	case (3): // Left
		sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y });
		break;
	case (4): // Right
		sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y });
		break;
	}
}

int rook::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	int difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	if (difference_x == 0 && difference_y < 0) 
	{
		scale = -difference_y;
		return 1; // Up
	}
	else if (difference_x == 0 && difference_y > 0) 
	{
		scale = difference_y;
		return 2; // Down
	}
	else if (difference_y == 0 && difference_x < 0) 
	{
		scale = -difference_x;
		return 3; // Left
	}
	else if (difference_y == 0 && difference_x > 0) 
	{
		scale = difference_x;
		return 4; // Right
	}
	else 
	{
		scale = 0;
		return 0; // Invalid 
	}
}
