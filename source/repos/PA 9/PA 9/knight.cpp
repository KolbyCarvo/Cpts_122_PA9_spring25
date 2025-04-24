#include "knight.h"

int knight::check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale)
{
	int x_pos = (pos.x / 113.0f);
	int y_pos = (pos.y / 113.0f);

	if (move == 0)
	{
		return 0;
	}
	if (color == 'w') {
		
		switch(move)
		{
		case(1):
			if (intWhiteBoard[y_pos - 1][x_pos - 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(2):
			if (intWhiteBoard[y_pos - 2][x_pos - 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(3):
			if (intWhiteBoard[y_pos - 2][x_pos +1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break; 
		case(4):
			if (intWhiteBoard[y_pos - 1][x_pos + 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(5):
			if (intWhiteBoard[y_pos + 1][x_pos + 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(6):
			if (intWhiteBoard[y_pos + 2][x_pos + 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(7):
			if (intWhiteBoard[y_pos + 2][x_pos - 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(8):
			if (intWhiteBoard[y_pos + 1][x_pos - 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		}
	}
	else if (color == 'b')
	{
		switch (move)
		{
		case(1):
			if (intBlackBoard[y_pos + 1][x_pos + 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(2):
			if (intBlackBoard[y_pos + 2][x_pos + 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(3):
			if (intBlackBoard[y_pos + 2][x_pos - 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(4):
			if (intBlackBoard[y_pos + 1][x_pos - 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(5):
			if (intBlackBoard[y_pos - 1][x_pos - 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(6):
			if (intBlackBoard[y_pos - 2][x_pos - 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(7):
			if (intBlackBoard[y_pos - 2][x_pos + 1] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(8):
			if (intBlackBoard[y_pos - 1][x_pos + 2] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		}
	}
}

void knight::move(int type, int& scale)
{
	switch (type)
	{
	case(1): // 2 left, 1 up 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x - 2 * 113.0f, sprite.getPosition().y - 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x + 2 * 113.0f, sprite.getPosition().y + 113.0f });
		}
		break;
	case(2): // 1 left, 2 up 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 2 * 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y + 2 * 113.0f });
		}
		break;
	case(3): // 1 right, 2 up 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 2 * 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y + 2 * 113.0f });
		}
		break;
	case(4): // 2 right, 1 up 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x + 2 * 113.0f, sprite.getPosition().y - 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x - 2 * 113.0f, sprite.getPosition().y + 113.0f });
		}
		break;
	case(5): // 2 right, 1 down
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x + 2 * 113.0f, sprite.getPosition().y + 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x - 2 * 113.0f, sprite.getPosition().y - 113.0f });
		}
		break;
	case(6): // 1 right, 2 down 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y + 2 * 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 2 * 113.0f });

		}
		break;
	case(7): // 1 left, 2 down 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y + 2 * 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 2 * 113.0f });
		}
		break;
	case(8): // 2 left, 1 down 
		if (color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x - 2 * 113.0f, sprite.getPosition().y + 113.0f });
		}
		else if (color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x + 2 * 113.0f, sprite.getPosition().y - 113.0f });
		}
		break;
	}
	pos = sprite.getPosition();
}

int knight::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = 0, difference_y = 0;
	difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	if (color == 'w')
	{
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
		return 0; // Invalid knight move
	}
	if (color == 'b')
	{
		if (difference_x == 2 && difference_y == 1)
		{
			return 1; // 2 left, 1 up
		}
		else if (difference_x == 1 && difference_y == 2)
		{
			return 2; // 1 left, 2 up
		}
		else if (difference_x == -1 && difference_y == 2)
		{
			return 3; // 1 right, 2 up
		}
		else if (difference_x == -2 && difference_y == 1)
		{
			return 4; // 2 right, 1 up
		}
		else if (difference_x == -2 && difference_y == -1)
		{
			return 5; // 2 right, 1 down
		}
		else if (difference_x == -1 && difference_y == -2)
		{
			return 6; // 1 right, 2 down
		}
		else if (difference_x == 1 && difference_y == -2)
		{
			return 7; // 1 left, 2 down
		}
		else if (difference_x == 2 && difference_y == -1)
		{
			return 8; // 2 left, 1 down
		}
		else
		{
			return 0; // Invalid knight move
		}
	}
}

