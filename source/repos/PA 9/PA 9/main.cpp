#include "board.h"

int main(void)
{
	unsigned int width = 906;
	unsigned int height = 906;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Chess PA 9");
	window->setFramerateLimit(30);

	board chessboard(window);

	sf::Texture white_pawn_texture, white_rook_texture, white_knight_texture, white_bishop_texture, white_queen_texture, white_king_texture;

	sf::Texture black_pawn_texture, black_rook_texture, black_knight_texture, black_bishop_texture, black_queen_texture, black_king_texture;

	if (!white_pawn_texture.loadFromFile("Sprites/w_pawn_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_pawn_png_128px.png" << std::endl;
		return-1;
	}
	if (!white_rook_texture.loadFromFile("Sprites/w_rook_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_rook_png_128px.png" << std::endl;
		return-1;
	}
	if (!white_knight_texture.loadFromFile("Sprites/w_knight_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_knight_png_128px.png" << std::endl;
		return-1;
	}
	if (!white_bishop_texture.loadFromFile("Sprites/w_bishop_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_bishop_png_128px.png" << std::endl;
		return-1;
	}
	if (!white_queen_texture.loadFromFile("Sprites/w_queen_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_queen_png_128px.png" << std::endl;
		return-1;
	}
	if (!white_king_texture.loadFromFile("Sprites/w_king_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/w_king_png_128px.png" << std::endl;
		return-1;
	}
	if (!black_pawn_texture.loadFromFile("Sprites/b_pawn_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/b_pawn_png_128px.png" << std::endl;
		return-1;
	}
	if (!black_rook_texture.loadFromFile("Sprites/b_rook_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/b_rook_png_128px.png" << std::endl;
		return-1;
	}
	if (!black_knight_texture.loadFromFile("Sprites/b_knight_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/b_knight_png_128px.png" << std::endl;
		return-1;
	}
	if (!black_bishop_texture.loadFromFile("Sprites/b_bishop_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/b_bishop_png_128px.png" << std::endl;
		return-1;
	}
	if (!black_queen_texture.loadFromFile("Sprites/b_queen_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/b_queen_png_128px.png" << std::endl;
		return-1;
	}
	if (!black_king_texture.loadFromFile("Sprites/b_king_png_128px.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/b_king_png_128px.png" << std::endl;
		return-1;
	}

	sf::Sprite white_pawn(white_pawn_texture), white_rook(white_rook_texture), white_knight(white_knight_texture),
		white_bishop(white_bishop_texture), white_queen(white_queen_texture), white_king(white_king_texture);

	sf::Sprite black_pawn(black_pawn_texture), black_rook(black_rook_texture), black_knight(black_knight_texture),
		black_bishop(black_bishop_texture), black_queen(black_queen_texture), black_king(black_king_texture);

	white_pawn.setOrigin({ 52.5f, 64.0f });
	white_rook.setOrigin({ 58.0f, 64.0f });
	white_knight.setOrigin({ 57.5f, 64.0f });
	white_bishop.setOrigin({ 63.5f, 64.0f });
	white_queen.setOrigin({ 70.5f, 64.0f });
	white_king.setOrigin({ 63.5f, 64.0f });

	black_pawn.setOrigin({ 52.5f, 64.0f });
	black_rook.setOrigin({ 58.0f, 64.0f });
	black_knight.setOrigin({ 57.5f, 64.0f });
	black_bishop.setOrigin({ 63.5f, 64.0f });
	black_queen.setOrigin({ 70.5f, 64.0f });
	black_king.setOrigin({ 63.5f, 64.0f });

	white_pawn.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_rook.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	white_rook.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	white_knight.setTextureRect(sf::IntRect({ 0, 0 }, { 115, 128 }));
	white_bishop.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));
	white_queen.setTextureRect(sf::IntRect({ 0, 0 }, { 141, 128 }));
	white_king.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));

	black_pawn.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_rook.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	black_knight.setTextureRect(sf::IntRect({ 0, 0 }, { 115, 128 }));
	black_bishop.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));
	black_queen.setTextureRect(sf::IntRect({ 0, 0 }, { 141, 128 }));
	black_king.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));

	white_pawn.setScale({ 0.6f, 0.6f });
	white_rook.setScale({ 0.6f, 0.6f });
	white_rook.setScale({ 0.6f, 0.6f });
	white_knight.setScale({ 0.6f, 0.6f });
	white_knight.setScale({ 0.6f, 0.6f });
	white_bishop.setScale({ 0.6f, 0.6f });
	white_bishop.setScale({ 0.6f, 0.6f });
	white_queen.setScale({ 0.6f, 0.6f });
	white_king.setScale({ 0.6f, 0.6f });

	black_pawn.setScale({ 0.6f, 0.6f });
	black_rook.setScale({ 0.6f, 0.6f });
	black_knight.setScale({ 0.6f, 0.6f });
	black_bishop.setScale({ 0.6f, 0.6f });
	black_queen.setScale({ 0.6f, 0.6f });
	black_king.setScale({ 0.6f, 0.6f });

	pawn white_pawns[8];
	rook white_rooks[2];
	knight white_knights[2];
	bishop white_bishops[2];
	queen white_queens;
	king white_kings;

	pawn black_pawns[8];
	rook black_rooks[2];
	knight black_knights[2];
	bishop black_bishops[2];
	queen black_queens;
	king black_kings;

	for (int i = 0; i < 8; i++)
	{
		white_pawns[i].setSprite(white_pawn);
		black_pawns[i].setSprite(black_pawn);
	}
	for (int i = 0; i < 2; i++)
	{
		white_rooks[i].setSprite(white_rook);
		black_rooks[i].setSprite(black_rook);
		white_knights[i].setSprite(white_knight);
		black_knights[i].setSprite(black_knight);
		white_bishops[i].setSprite(white_bishop);
		black_bishops[i].setSprite(black_bishop);
	}
	white_queens.setSprite(white_queen);
	black_queens.setSprite(black_queen);
	white_kings.setSprite(white_king);
	black_kings.setSprite(black_king);

	int n = 1;
	for (int i = 0; i < 8; i++ )
	{
		white_pawns[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * n , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		black_pawns[i].getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * n , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f});
		n += 2;
	}
	n = 1;
	int j = 3;
	int k = 5;
	for (int i = 0; i < 2; i++)
	{
		white_rooks[i].getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * n, chessboard.get_board(1,1).getGeometricCenter().y * 15.0f});
		white_knights[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * j , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_bishops[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * k , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f});
		black_rooks[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * n, chessboard.get_board(1,1).getGeometricCenter().y });
		black_knights[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * j, chessboard.get_board(1,1).getGeometricCenter().y });
		black_bishops[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * k, chessboard.get_board(1,1).getGeometricCenter().y });
		n = 15;
		j = 13;
		k = 11;
	}
	white_queens.getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f});
	white_kings.getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
	black_queens.getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y});
	black_kings.getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y});

	while (window->isOpen())
	{
		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window->close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window->close();
				}
			}
		}

		window->clear();

		for (int row = 0; row < 8; row++)
		{
			for (int col = 0; col < 8; col++)
			{
				window->draw(chessboard.get_board(row, col));
			}
		}
		for (int i = 0; i < 8 ;i++)
		{ 
			window->draw(white_pawns[i].getSprite());
			window->draw(black_pawns[i].getSprite());
		}
		for (int i = 0; i < 2 ;i++)
		{
			window->draw(white_rooks[i].getSprite());
			window->draw(black_rooks[i].getSprite());
			window->draw(white_knights[i].getSprite());
			window->draw(black_knights[i].getSprite());
			window->draw(white_bishops[i].getSprite());
			window->draw(black_bishops[i].getSprite());
		}
		window->draw(white_queens.getSprite());
		window->draw(white_kings.getSprite());
		window->draw(black_queens.getSprite());
		window->draw(black_kings.getSprite());

		window->display();
	}

	delete window;
	return 0;
}