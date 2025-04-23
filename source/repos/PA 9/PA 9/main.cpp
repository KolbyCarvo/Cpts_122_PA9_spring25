#include "board.h"

int main(void)
{
	unsigned int width = 1006;
	unsigned int height = 1006;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Chess PA 9");
	window->setFramerateLimit(60);

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

	sf::Sprite white_pawn_1(white_pawn_texture),
		white_pawn_2(white_pawn_texture),
		white_pawn_3(white_pawn_texture),
		white_pawn_4(white_pawn_texture),
		white_pawn_5(white_pawn_texture),
		white_pawn_6(white_pawn_texture),
		white_pawn_7(white_pawn_texture),
		white_pawn_8(white_pawn_texture),
		white_rook_1(white_rook_texture),
		white_rook_2(white_rook_texture),
		white_knight_1(white_knight_texture),
		white_knight_2(white_knight_texture),
		white_bishop_1(white_bishop_texture),
		white_bishop_2(white_bishop_texture),
		white_queen(white_queen_texture),
		white_king(white_king_texture);

	sf::Sprite black_pawn_1(black_pawn_texture),
		black_pawn_2(black_pawn_texture),
		black_pawn_3(black_pawn_texture),
		black_pawn_4(black_pawn_texture),
		black_pawn_5(black_pawn_texture),
		black_pawn_6(black_pawn_texture),
		black_pawn_7(black_pawn_texture),
		black_pawn_8(black_pawn_texture),
		black_rook_1(black_rook_texture),
		black_rook_2(black_rook_texture),
		black_knight_1(black_knight_texture),
		black_knight_2(black_knight_texture),
		black_bishop_1(black_bishop_texture),
		black_bishop_2(black_bishop_texture),
		black_queen(black_queen_texture),
		black_king(black_king_texture);

	white_pawn_1.setOrigin({ 52.5f, 64.0f });
	white_pawn_2.setOrigin({ 52.5f, 64.0f });
	white_pawn_3.setOrigin({ 52.5f, 64.0f });
	white_pawn_4.setOrigin({ 52.5f, 64.0f });
	white_pawn_5.setOrigin({ 52.5f, 64.0f });
	white_pawn_6.setOrigin({ 52.5f, 64.0f });
	white_pawn_7.setOrigin({ 52.5f, 64.0f });
	white_pawn_8.setOrigin({ 52.5f, 64.0f });
	white_rook_1.setOrigin({ 58.0f, 64.0f });
	white_rook_2.setOrigin({ 58.0f, 64.0f });
	white_knight_1.setOrigin({ 57.5f, 64.0f });
	white_knight_2.setOrigin({ 57.5f, 64.0f });
	white_bishop_1.setOrigin({ 63.5f, 64.0f });
	white_bishop_2.setOrigin({ 63.5f, 64.0f });
	white_queen.setOrigin({ 70.5f, 64.0f });
	white_king.setOrigin({ 63.5f, 64.0f });

	black_pawn_1.setOrigin({ 52.5f, 64.0f });
	black_pawn_2.setOrigin({ 52.5f, 64.0f });
	black_pawn_3.setOrigin({ 52.5f, 64.0f });
	black_pawn_4.setOrigin({ 52.5f, 64.0f });
	black_pawn_5.setOrigin({ 52.5f, 64.0f });
	black_pawn_6.setOrigin({ 52.5f, 64.0f });
	black_pawn_7.setOrigin({ 52.5f, 64.0f });
	black_pawn_8.setOrigin({ 52.5f, 64.0f });
	black_rook_1.setOrigin({ 58.0f, 64.0f });
	black_rook_2.setOrigin({ 58.0f, 64.0f });
	black_knight_1.setOrigin({ 57.5f, 64.0f });
	black_knight_2.setOrigin({ 57.5f, 64.0f });
	black_bishop_1.setOrigin({ 63.5f, 64.0f });
	black_bishop_2.setOrigin({ 63.5f, 64.0f });
	black_queen.setOrigin({ 70.5f, 64.0f });
	black_king.setOrigin({ 63.5f, 64.0f });

	white_pawn_1.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_2.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_3.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_4.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_5.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_6.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_7.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_pawn_8.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	white_rook_1.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	white_rook_2.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	white_knight_1.setTextureRect(sf::IntRect({ 0, 0 }, { 115, 128 }));
	white_knight_2.setTextureRect(sf::IntRect({ 0, 0 }, { 115, 128 }));
	white_bishop_1.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));
	white_bishop_2.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));
	white_queen.setTextureRect(sf::IntRect({ 0, 0 }, { 141, 128 }));
	white_king.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));

	black_pawn_1.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_2.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_3.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_4.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_5.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_6.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_7.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_pawn_8.setTextureRect(sf::IntRect({ 0, 0 }, { 105, 128 }));
	black_rook_1.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	black_rook_2.setTextureRect(sf::IntRect({ 0, 0 }, { 116, 128 }));
	black_knight_1.setTextureRect(sf::IntRect({ 0, 0 }, { 115, 128 }));
	black_knight_2.setTextureRect(sf::IntRect({ 0, 0 }, { 115, 128 }));
	black_bishop_1.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));
	black_bishop_2.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));
	black_queen.setTextureRect(sf::IntRect({ 0, 0 }, { 141, 128 }));
	black_king.setTextureRect(sf::IntRect({ 0, 0 }, { 127, 128 }));

	white_pawn_1.setScale({ 0.6f, 0.6f });
	white_pawn_2.setScale({ 0.6f, 0.6f });
	white_pawn_3.setScale({ 0.6f, 0.6f });
	white_pawn_4.setScale({ 0.6f, 0.6f });
	white_pawn_5.setScale({ 0.6f, 0.6f });
	white_pawn_6.setScale({ 0.6f, 0.6f });
	white_pawn_7.setScale({ 0.6f, 0.6f });
	white_pawn_8.setScale({ 0.6f, 0.6f });
	white_rook_1.setScale({ 0.6f, 0.6f });
	white_rook_2.setScale({ 0.6f, 0.6f });
	white_knight_1.setScale({ 0.6f, 0.6f });
	white_knight_2.setScale({ 0.6f, 0.6f });
	white_bishop_1.setScale({ 0.6f, 0.6f });
	white_bishop_2.setScale({ 0.6f, 0.6f });
	white_queen.setScale({ 0.6f, 0.6f });
	white_king.setScale({ 0.6f, 0.6f });

	black_pawn_1.setScale({ 0.6f, 0.6f });
	black_pawn_2.setScale({ 0.6f, 0.6f });
	black_pawn_3.setScale({ 0.6f, 0.6f });
	black_pawn_4.setScale({ 0.6f, 0.6f });
	black_pawn_5.setScale({ 0.6f, 0.6f });
	black_pawn_6.setScale({ 0.6f, 0.6f });
	black_pawn_7.setScale({ 0.6f, 0.6f });
	black_pawn_8.setScale({ 0.6f, 0.6f });
	black_rook_1.setScale({ 0.6f, 0.6f });
	black_rook_2.setScale({ 0.6f, 0.6f });
	black_knight_1.setScale({ 0.6f, 0.6f });
	black_knight_2.setScale({ 0.6f, 0.6f });
	black_bishop_1.setScale({ 0.6f, 0.6f });
	black_bishop_2.setScale({ 0.6f, 0.6f });
	black_queen.setScale({ 0.6f, 0.6f });
	black_king.setScale({ 0.6f, 0.6f });

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
				window->draw(chessboard.get_board(row,col));
			}
		}

		white_pawn_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 3.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_3.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 5.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_4.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_5.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_6.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 11.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_7.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 13.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawn_8.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 15.0f , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_rook_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_rook_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 15.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_knight_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 3.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_knight_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 13.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_bishop_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 5.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_bishop_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 11.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_queen.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_king.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });

		black_pawn_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 3.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_3.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 5.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_4.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_5.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_6.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 11.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_7.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 13.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_pawn_8.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 15.0f , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f });
		black_rook_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x , chessboard.get_board(1,1).getGeometricCenter().y });
		black_rook_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 15.0f , chessboard.get_board(1,1).getGeometricCenter().y });
		black_knight_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 3.0f , chessboard.get_board(1,1).getGeometricCenter().y });
		black_knight_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 13.0f , chessboard.get_board(1,1).getGeometricCenter().y });
		black_bishop_1.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 5.0f , chessboard.get_board(1,1).getGeometricCenter().y });
		black_bishop_2.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 11.0f , chessboard.get_board(1,1).getGeometricCenter().y });
		black_queen.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y });
		black_king.setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y });

		window->draw(white_pawn_1);
		window->draw(white_pawn_2);
		window->draw(white_pawn_3);
		window->draw(white_pawn_4);
		window->draw(white_pawn_5);
		window->draw(white_pawn_6);
		window->draw(white_pawn_7);
		window->draw(white_pawn_8);
		window->draw(white_rook_1);
		window->draw(white_rook_2);
		window->draw(white_knight_1);
		window->draw(white_knight_2);
		window->draw(white_bishop_1);
		window->draw(white_bishop_2);
		window->draw(white_queen);
		window->draw(white_king);

		window->draw(black_pawn_1);
		window->draw(black_pawn_2);
		window->draw(black_pawn_3);
		window->draw(black_pawn_4);
		window->draw(black_pawn_5);
		window->draw(black_pawn_6);
		window->draw(black_pawn_7);
		window->draw(black_pawn_8);
		window->draw(black_rook_1);
		window->draw(black_rook_2);
		window->draw(black_knight_1);
		window->draw(black_knight_2);
		window->draw(black_bishop_1);
		window->draw(black_bishop_2);
		window->draw(black_queen);
		window->draw(black_king);

		window->display();
	}

	delete window;
	return 0;
}