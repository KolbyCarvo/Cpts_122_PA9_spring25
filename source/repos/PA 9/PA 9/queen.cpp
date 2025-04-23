#include "queen.h"


void queen::move(int type, int scale)
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
	case (5): // Up Left
		sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y - scale * 113.0f });
		break;
	case (6): // Up Right
		sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y - scale * 113.0f });
		break;
	case (7): // Down Left
		sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y + scale * 113.0f });
		break;
	case (8): // Down Right
		sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y + scale * 113.0f });
		break;
	}
}

int queen::determine_move(sf::Vector2f next_position, int& scale)
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
	else if (difference_x == difference_y && difference_x < 0)
	{
		scale = -difference_x;
		return 5; // Up-Left
	}
	else if (difference_x == -difference_y && difference_x > 0)
	{
		scale = difference_x;
		return 6; // Up-Right
	}
	else if (difference_x == -difference_y && difference_x < 0)
	{
		scale = -difference_x;
		return 7; // Down-Left
	}
	else if (difference_x == difference_y && difference_x > 0)
	{
		scale = difference_x;
		return 8; // Down-Right
	}
	else
	{
		scale = 0;
		return 0; // Invalid
	}
}

