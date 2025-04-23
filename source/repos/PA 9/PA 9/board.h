#pragma once
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class board
{
public:
	board(sf::RenderWindow* window = nullptr);

	sf::RectangleShape get_board(int row, int col);

private:
	sf::RectangleShape chess_board[8][8];
};

