#include "bishop.h"

int bishop::check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale)
{
	int x_pos = (pos.x / 113.0f);
	int y_pos = (pos.y / 113.0f);
	int temp_int = 0;
	if (color == 'w')
	{
		switch (move)
		{
		case (1): 
			for (int i = 1; i < scale ; i++)
			{
				if (intWhiteBoard[y_pos - i][x_pos - i] != 0 || intBlackBoard[y_pos - i][x_pos - i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos - temp_int-1][x_pos - temp_int-1] == 0 )
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos - temp_int-1][x_pos - temp_int-1] == 1 )
			{
				return 0;
			}

			return 1;
			break;
		case (2): // Up-Right
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos - i][x_pos + i] != 0 || intBlackBoard[y_pos - i][x_pos + i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos - temp_int - 1][x_pos + temp_int + 1] == 0 )
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos - temp_int - 1][x_pos + temp_int + 1] == 1 )
			{
				return 0;
			}
			return 1;
			break;
		case (3): // Down-Left
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos + i][x_pos - i] != 0 || intBlackBoard[y_pos + i][x_pos - i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos + temp_int+1][x_pos - temp_int+-1] == 0 )
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos + temp_int+1][x_pos - temp_int-1] == 1 )
			{
				return 0;
			}
			return 1;
			break;
		case (4): // Down-Right
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos + i][x_pos + i] != 0 || intBlackBoard[y_pos + i][x_pos + i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos + temp_int+1][x_pos + temp_int+1] == 0 )
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos + temp_int+1][x_pos + temp_int+1] == 1)
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
		case (1):
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos + i][x_pos + i] != 0 || intBlackBoard[y_pos + i][x_pos + i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intBlackBoard[y_pos + temp_int+1][x_pos + temp_int+1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos + temp_int+1][x_pos + temp_int+1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (2): // Up-Right
			for (int i = 1; i < scale ; i++)
			{
				if (intWhiteBoard[y_pos + i][x_pos - i] != 0 || intBlackBoard[y_pos + i][x_pos - i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intBlackBoard[y_pos + temp_int+1][x_pos - temp_int+-1] == 0 )
			{
				return 1;
			}
			else if (intBlackBoard[y_pos + temp_int+1][x_pos - temp_int-1] == 1 )
			{
				return 0;
			}
			return 1;
			break;
		case (3): // Down-Left
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos - i][x_pos + i] != 0 || intBlackBoard[y_pos - i][x_pos + i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intBlackBoard[y_pos - temp_int-1][x_pos + temp_int+1] == 0 )
			{
				return 1;
			}
			else if (intBlackBoard[y_pos - temp_int -1][x_pos + temp_int +1] == 1 )
			{
				return 0;
			}
			return 1;
			break;
		case (4): // Down-Right
			for (int i = 1; i < scale  ; i++)
			{
				if (intWhiteBoard[y_pos - i][x_pos - i] != 0 || intBlackBoard[y_pos - i][x_pos - i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intBlackBoard[y_pos - temp_int - 1][x_pos - temp_int -1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos - temp_int -1][x_pos - temp_int -1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		}
	}
}

void bishop::move(int type, int& scale)
{
	if (color == 'w')
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
	else if (color == 'b')
	{
		switch (type)
		{
		case (1): // Up-Left
			sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y + scale * 113.0f });
			break;
		case (2): // Up-Right
			sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y + scale * 113.0f });
			break;
		case (3): // Down-Left
			sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y - scale * 113.0f });
			break;
		case (4): // Down-Right
			sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y - scale * 113.0f });
			break;
		}
	}
	pos = sprite.getPosition();
}


int bishop::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	int difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	if (std::abs(difference_x) == std::abs(difference_y)) 
	{
		scale = std::abs(difference_x);
		if (color == 'w')
		{
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
		else if (color == 'b')
		{
			if (difference_x > 0 && difference_y > 0)
			{
				return 1; // Up-Left
			}
			else if (difference_x < 0 && difference_y > 0)
			{
				return 2; // Up-Right
			}
			else if (difference_x > 0 && difference_y < 0)
			{
				return 3; // Down-Left
			}
			else if (difference_x < 0 && difference_y < 0)
			{
				return 4; // Down-Right
			}
		}
	}
	// Invalid move
	
	scale = 1;
	return 0;
}