#include "bishop.h"

void bishop::move(int type, int scale)
{
	switch (type)
	{
	case (1): // Up-Left
		sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y - scale * 113.0f });
		break;
	case (2): // Up-Right
		sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y - scale * 113.0f });
		break;
	case (3): // Down-Left
		sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y + scale * 113.0f });
		break;
	case (4): // Down-Right
		sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y + scale * 113.0f });
		break;
	}
}


int bishop::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	int difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	if (std::abs(difference_x) == std::abs(difference_y)) 
	{
		scale = std::abs(difference_x);

		if (difference_x < 0 && difference_y < 0)
		{
			return 1; // Up-Left
		}
		else if (difference_x > 0 && difference_y < 0)
		{
			return 2; // Up-Right
		}
		else if (difference_x < 0 && difference_y > 0)
		{
			return 3; // Down-Left
		}
		else if (difference_x > 0 && difference_y > 0)
		{
			return 4; // Down-Right
		}
	}
	else// Invalid move
	{
		scale = 0;
		return 0;
	}
}