#include "king.h"

int king::determine_move(sf::Vector2f next_position)
{
	int difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	int difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	
	if (difference_x == 0 && difference_y == -1)
	{
		return 1; // Up
	}
	else if (difference_x == 0 && difference_y == 1)
	{
		return 2; // Down
	}
	else if (difference_x == -1 && difference_y == 0)
	{
		return 3; // Left
	}
	else if (difference_x == 1 && difference_y == 0)
	{
		return 4; // Right
	}
	else if (difference_x == -1 && difference_y == -1)
	{
		return 5; // Up-Left
	}
	else if (difference_x == 1 && difference_y == -1)
	{
		return 6; // Up-Right
	}
	else if (difference_x == -1 && difference_y == 1)
	{
		return 7; // Down-Left
	}
	else if (difference_x == 1 && difference_y == 1)
	{
		return 8; // Down-Right
	}
	else
	{
		return 0; //invalid
	}
}

void king::move(int type)
{
	switch (type)
	{
	case (1): // Up
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 113.0f });
		break;
	case (2): // Down
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + 113.0f });
		break;
	case (3): // Left
		sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y });
		break;
	case (4): // Right
		sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y });
		break;
	case (5): // Up Left
		sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 113.0f });
		break;
	case (6): // Up Right
		sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 113.0f });
		break;
	case (7): // Down Left
		sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y + 113.0f });
		break;
	case (8): // Down Right
		sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y + 113.0f });
		break;
	}
}