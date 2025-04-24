#include "rook.h"

int rook::check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale)
{
	int x_pos = (pos.x / 113.0f);
	int y_pos = (pos.y / 113.0f);

	int temp_int = 0;

	if (color == 'w')
	{
		switch (move)
		{
		case (1): //up
			for (int i = 1; i < scale  ; i++)
			{
				if (intWhiteBoard[y_pos - i][x_pos] != 0 || intBlackBoard[y_pos - i][x_pos] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos - temp_int-1][x_pos] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos - temp_int-1][x_pos] == 1)
			{
				return 0;
			}

			return 1;
			break;
		case (2): // down
			for (int i = 1; i < scale ; i++)
			{
				if (intWhiteBoard[y_pos + i][x_pos] != 0 || intBlackBoard[y_pos - i][x_pos] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos + temp_int+1][x_pos] == 0)
			{
				return 1;
			}
			else if ( intWhiteBoard[y_pos + temp_int+1][x_pos] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (3): // Left
			for (int i = 1; i < scale ; i++)
			{
				if (intWhiteBoard[y_pos][x_pos - i] != 0 || intBlackBoard[y_pos][x_pos - i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos][x_pos - temp_int-1] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos][x_pos - temp_int-1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (4): // Right
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos][x_pos + i] != 0 || intBlackBoard[y_pos][x_pos + i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intWhiteBoard[y_pos][x_pos + temp_int+1] == 0)
			{
				return 1;
			}
			else if (intWhiteBoard[y_pos][x_pos + temp_int+1] == 1)
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
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos + i][x_pos] != 0 || intBlackBoard[y_pos + i][x_pos] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if ( intBlackBoard[y_pos + temp_int+1][x_pos] == 0)
			{
				return 1;
			}
			else if ( intBlackBoard[y_pos + temp_int+1][x_pos] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (2): // down
			for (int i = 1; i < scale ; i++)
			{
				if (intWhiteBoard[y_pos - i][x_pos] != 0 || intBlackBoard[y_pos - i][x_pos] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if ( intBlackBoard[y_pos - temp_int-1][x_pos] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos - temp_int-1][x_pos] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (3): //Left
			for (int i = 1; i < scale ; i++)
			{
				if (intWhiteBoard[y_pos][x_pos + i] != 0 || intBlackBoard[y_pos][x_pos + i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intBlackBoard[y_pos][x_pos + temp_int+1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos][x_pos + temp_int+1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		case (4): //Right
			for (int i = 1; i < scale; i++)
			{
				if (intWhiteBoard[y_pos][x_pos - i] != 0 || intBlackBoard[y_pos][x_pos - i] != 0)
				{
					return 0;
				}
				temp_int = i;
			}
			if (intBlackBoard[y_pos][x_pos - temp_int-1] == 0)
			{
				return 1;
			}
			else if (intBlackBoard[y_pos][x_pos - temp_int-1] == 1)
			{
				return 0;
			}
			return 1;
			break;
		}
	}
}

void rook::move(int type, int& scale)
{
	if (color == 'w')
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
	else if (color == 'b')
	{
		switch (type)
		{
		case (1): // Up
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + scale * 113.0f });
			break;
		case (2): // Down
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - scale * 113.0f });
			break;
		case (3): // Left
			sprite.setPosition({ sprite.getPosition().x + scale * 113.0f, sprite.getPosition().y });
			break;
		case (4): // Right
			sprite.setPosition({ sprite.getPosition().x - scale * 113.0f, sprite.getPosition().y });
			break;
		}
	}
	pos = sprite.getPosition();
}

int rook::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = (int)(next_position.x / 113) - (int)(pos.x / 113);
	int difference_y = (int)(next_position.y / 113) - (int)(pos.y / 113);

	if (color == 'w')
	{
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
	}
	else if (color == 'b')
	{
		if (difference_x == 0 && difference_y > 0)
		{
			scale = difference_y;
			return 1; // Up
		}
		else if (difference_x == 0 && difference_y < 0)
		{
			scale = -difference_y;
			return 2; // Down
		}
		else if (difference_y == 0 && difference_x > 0)
		{
			scale = difference_x;
			return 3; // Left
		}
		else if (difference_y == 0 && difference_x < 0)
		{
			scale = -difference_x;
			return 4; // Right
		}
	}
	scale = 1;
	return 0; // Invalid 
}
