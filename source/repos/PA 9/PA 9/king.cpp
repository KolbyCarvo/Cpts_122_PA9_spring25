#include "king.h"

int king::check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale)
{
	int x_pos = (pos.x / 113.0f);
	int y_pos = (pos.y / 113.0f);

	int temp_int = 0;

	if (color == 'w')
	{
		switch (move)
		{
		case (1): //up
			
			if (intWhiteBoard[y_pos - temp_int - 1][x_pos] == 0)
			{
				return 1;
			}
			if (intWhiteBoard[y_pos - temp_int - 1][x_pos] == 1)
			{
				return 0;
			}

			return 1;
			break;
		case (2): // down
			
			if (intWhiteBoard[y_pos + temp_int + 1][x_pos] == 0)
			{
				return 1;
			}
			if (intWhiteBoard[y_pos + temp_int + 1][x_pos] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (3): // Left
			
			if (intWhiteBoard[y_pos][x_pos - temp_int - 1] == 0)
			{
				return 1;
			}
			if (intWhiteBoard[y_pos][x_pos - temp_int - 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (4): // Right
			
			if (intWhiteBoard[y_pos][x_pos + temp_int + 1] == 0)
			{
				return 1;
			}
			if (intWhiteBoard[y_pos][x_pos + temp_int + 1] == 1)
			{
				return 0;
			}
			return 1;
			break;

		case (5):
			
			if (intWhiteBoard[y_pos - temp_int - 1][x_pos - temp_int - 1] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos - temp_int - 1][x_pos - temp_int - 1] == 1)
			{
				return 0;
			}

			return 1;
			break;
		case (6): // Up-Right
			
			if (intWhiteBoard[y_pos - temp_int - 1][x_pos + temp_int + 1] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos - temp_int - 1][x_pos + temp_int + 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (7): // Down-Left
			
			if (intWhiteBoard[y_pos + temp_int + 1][x_pos - temp_int + -1] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos + temp_int + 1][x_pos - temp_int - 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (8): // Down-Right
			
			if (intWhiteBoard[y_pos + temp_int + 1][x_pos + temp_int + 1] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos + temp_int + 1][x_pos + temp_int + 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		}
	}
	else if (color == 'b')
	{
		switch (move)
		{
		case (1): //up
			
			if (intBlackBoard[y_pos + temp_int + 1][x_pos] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos + temp_int + 1][x_pos] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (2): // down
			
			if (intBlackBoard[y_pos - temp_int - 1][x_pos] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos - temp_int - 1][x_pos] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (3): //Left
			
			if (intBlackBoard[y_pos][x_pos + temp_int + 1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos][x_pos + temp_int + 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (4): //Right
			
			if (intBlackBoard[y_pos][x_pos - temp_int - 1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos][x_pos - temp_int - 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (5):
			
			if (intBlackBoard[y_pos + temp_int + 1][x_pos + temp_int + 1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos + temp_int + 1][x_pos + temp_int + 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (6): // Up-Right
			
			if (intBlackBoard[y_pos + temp_int + 1][x_pos - temp_int + -1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos + temp_int + 1][x_pos - temp_int - 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (7): // Down-Left
			
			if (intBlackBoard[y_pos - temp_int - 1][x_pos + temp_int + 1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos - temp_int - 1][x_pos + temp_int + 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (8): // Down-Right
			if (intBlackBoard[y_pos - temp_int - 1][x_pos - temp_int - 1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos - temp_int - 1][x_pos - temp_int - 1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		}
	}
}

int king::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	int difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	if (color == 'w')
	{
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
	}
	else if (color == 'b')
	{
		if (difference_x == 0 && difference_y == 1)
		{
			return 1; // Up
		}
		else if (difference_x == 0 && difference_y == -1)
		{
			return 2; // Down
		}
		else if (difference_x == 1 && difference_y == 0)
		{
			return 3; // Left
		}
		else if (difference_x == -1 && difference_y == 0)
		{
			return 4; // Right
		}
		else if (difference_x == 1 && difference_y == 1)
		{
			return 5; // Up-Left
		}
		else if (difference_x == -1 && difference_y == 1)
		{
			return 6; // Up-Right
		}
		else if (difference_x == 1 && difference_y == +1)
		{
			return 7; // Down-Left
		}
		else if (difference_x == -1 && difference_y == -1)
		{
			return 8; // Down-Right
		}
	}
	return 0; //invalid
}

void king::move(int type, int& scale)
{
	if (color == 'w')
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
	else if (color == 'b')
	{
		switch (type)
		{
		case (1): // Up
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + 113.0f });
			break;
		case (2): // Down
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 113.0f });
			break;
		case (3): // Left
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y });
			break;
		case (4): // Right
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y });
			break;
		case (5): // Up Left
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y + 113.0f });
			break;
		case (6): // Up Right
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y + 113.0f });
			break;
		case (7): // Down Left
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 113.0f });
			break;
		case (8): // Down Right
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 113.0f });
			break;
		}
	}
	pos = sprite.getPosition();
}