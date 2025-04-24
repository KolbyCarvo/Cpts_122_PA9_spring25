#include "piece.h"
#include "pawn.h"

int pawn::check(int (intWhiteBoard[8][8]), int (intBlackBoard[8][8]), int move, int scale) {
	
	int x_pos = (pos.x / 113.0f);
	int y_pos = (pos.y / 113.0f);

	if (move == 0)
	{
		return 0;
	}
	if (color == 'w') {

		switch (move)
		{
		case(1):
			if (intWhiteBoard[y_pos - 1][x_pos] != 0 || intBlackBoard[y_pos - 1][x_pos] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(2):
			if (intWhiteBoard[y_pos - 1][x_pos] != 0 || intBlackBoard[y_pos - 1][x_pos] != 0)
			{
				return 0;
			}
			else if (intWhiteBoard[y_pos - 2][x_pos] != 0 || intBlackBoard[y_pos - 2][x_pos] != 0)
			{
				return 0;
			}
			else 
			{
				return 1;
			}
			break;
		case(3):
			if (intBlackBoard[y_pos - 1][x_pos - 1] == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(4):
			if (intBlackBoard[y_pos - 1][x_pos + 1] == 0)
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
			if (intBlackBoard[y_pos + 1][x_pos] != 0 || intWhiteBoard[y_pos + 1][x_pos] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(2):
			if (intBlackBoard[y_pos + 1][x_pos] != 0 || intWhiteBoard[y_pos + 1][x_pos] != 0)
			{
				return 0;
			}
			else if (intBlackBoard[y_pos + 2][x_pos] != 0 || intWhiteBoard[y_pos + 2][x_pos] != 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(3):
			if (intWhiteBoard[y_pos + 1][x_pos + 1] == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			break;
		case(4):
			if (intWhiteBoard[y_pos + 1][x_pos - 1] == 0)
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

void pawn::move(int type, int& scale)
{
	switch (type)
	{
	case(1): //forward 1
		if (this->color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 113.0f });
		}
		else if (this->color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + 113.0f });
		}
		break;
	case(2): //forward 2
		if (this->color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 2 * 113.0f });
		}
		else if (this->color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + 2 * 113.0f });
		}
		break;
	case(3): // capture left
		if (this->color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y - 113.0f });
		}
		else if (this->color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y + 113.0f });
		}
		break;
	case(4): // capture right
		if (this->color == 'w')
		{
			sprite.setPosition({ sprite.getPosition().x + 113.0f, sprite.getPosition().y - 113.0f });
		}
		else if (this->color == 'b')
		{
			sprite.setPosition({ sprite.getPosition().x - 113.0f, sprite.getPosition().y + 113.0f });
		}
		break;
	}
	has_moved = 1;
	pos = sprite.getPosition();
}

int pawn::determine_move(sf::Vector2f next_position, int& scale)
{
	int difference_x = 0, difference_y = 0;
	difference_x = (int)(pos.x / 113.0f) - (int)(next_position.x / 113.0f);
	difference_y = (int)(pos.y / 113.0f) - (int)(next_position.y / 113.0f);

	if (this->color == 'w') 
	{
		if (difference_x == 0 && difference_y == 1)
		{
			return 1; // up 1
		}
		else if (difference_x == 0 && difference_y == 2 && has_moved == 0)
		{
			return 2; // up 2
		}
		if (difference_x == 1 && difference_y == 1) 
		{
			return 3; // capture left for white
		}
		else if (difference_x == -1 && difference_y == 1) 
		{
			return 4; // capture right for white
		}
	}
	else if (this->color == 'b') 
	{
		if (difference_x == 0 && difference_y == -1)
		{
			return 1; // up 1
		}
		else if (difference_x == 0 && difference_y == -2 && has_moved == 0)
		{
			return 2; // up 2
		}
		if (difference_x == -1 && difference_y == -1) 
		{
			return 3; // capture left for black
		}
		else if (difference_x == 1 && difference_y == -1) 
		{
			return 4; // capture right for black
		}
	}
	return 0; // invalid
}