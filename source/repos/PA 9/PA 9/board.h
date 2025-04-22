#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class board
{
public:
	board(sf::RenderWindow* window = nullptr);

private:
	sf::RectangleShape chess_board[8][8];

	pawn[8] white_pawns;
	rook[2] white_rooks;
	knight[2] white_knights;
	bishop[2] white_bishops;
	queen white_queen;
	king white_king;

	pawn[8] black_pawns;
	rook[2] black_rooks;
	knight[2] black_knights;
	bishop[2] black_bishops;
	queen black_queen;
	king black_king;
};

