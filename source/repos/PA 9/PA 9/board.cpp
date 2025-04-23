#include "board.h"

board::board(sf::RenderWindow* window)
{
	int TILE_SIZE = (window->getSize().x / 8.0f);

	sf::RectangleShape board[8][8];

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			chess_board[row][col].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
			chess_board[row][col].setPosition(sf::Vector2f(col * TILE_SIZE + 3, row * TILE_SIZE + 3));
			chess_board[row][col].setOutlineThickness(3);
			chess_board[row][col].setOutlineColor(sf::Color::Black);

			if ((row + col) % 2 == 0)
				chess_board[row][col].setFillColor(sf::Color(240, 220, 180));  // light square
			else
				chess_board[row][col].setFillColor(sf::Color(90, 65, 50));   // dark square
		}
	}
}

sf::RectangleShape board::get_board(int row, int col)
{
	return chess_board[row][col];
}