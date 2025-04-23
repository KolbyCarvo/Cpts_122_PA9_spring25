#include "knight.h"

void knight::move(int type)
{
	switch (type)
	{
	case(1): // 2 left, 1 up 
		sprite.setPosition({ sprite.getPosition().x - 2 * 113.0f, sprite.getPosition().y - 113.0f });
		break;
	case(2): // 1 left, 2 up 
		sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 2 * 113.0f });
		break;
	case(3): // 1 right, 2 up 
		sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 2 * 113.0f });
		break;
	case(4): // 2 right, 1 up 
		sprite.setPosition({ sprite.getPosition().x + 2 * 113.0f, sprite.getPosition().y - 113.0f });
		break;
	case(5): // 2 right, 1 down
		sprite.setPosition({ sprite.getPosition().x + 2 * 113.0f, sprite.getPosition().y + 113.0f });
		break;
	case(6): // 1 right, 2 down 
		sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y + 2 * 113.0f });
		break;
	case(7): // 1 left, 2 down 
		sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y + 2 * 113.0f });
		break;
	case(8): // 2 left, 1 down 
		sprite.setPosition({ sprite.getPosition().x - 2 * 113.0f, sprite.getPosition().y + 113.0f });
		break;
	}
}

int knight::determine_move(sf::Vector2f next_position)
{
	int difference_x = 0, difference_y = 0;
	difference_x = (int)(pos.x / 113) - (int)(next_position.x / 113);
	difference_y = (int)(pos.y / 113) - (int)(next_position.y / 113);

	if (difference_x == -2 && difference_y == -1)
	{
		return 1; // 2 left, 1 up
	}
	else if (difference_x == -1 && difference_y == -2)
	{
		return 2; // 1 left, 2 up
	}
	else if (difference_x == 1 && difference_y == -2)
	{
		return 3; // 1 right, 2 up
	}
	else if (difference_x == 2 && difference_y == -1)
	{
		return 4; // 2 right, 1 up
	}
	else if (difference_x == 2 && difference_y == 1)
	{
		return 5; // 2 right, 1 down
	}
	else if (difference_x == 1 && difference_y == 2)
	{
		return 6; // 1 right, 2 down
	}
	else if (difference_x == -1 && difference_y == 2)
	{
		return 7; // 1 left, 2 down
	}
	else if (difference_x == -2 && difference_y == 1)
	{
		return 8; // 2 left, 1 down
	}
	else
	{
		return 0; // Invalid knight move
	}
}

