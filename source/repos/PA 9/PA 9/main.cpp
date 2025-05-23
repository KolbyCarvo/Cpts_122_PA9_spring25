#include "board.h"

int main(void)
{
	unsigned int width = 906;
	unsigned int height = 906;

	std::cout << "This is a fairly regular chess game spare a few details\n" << std::endl;
	std::cout << "White moves first, to select a piece left click, to move right click wanted square \n" << std::endl;
	std::cout << "Unlike Standard chess you must capture the King in order to win \n" << std::endl;
	std::cout << "press any key to continue\n" << std::endl;
	std::cin.ignore();
	system("cls");

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Chess PA 9");
	window->setFramerateLimit(15);
	char turn = 'w';
	int temp_scale = 1, move_integer = 0;
	int whiteBoard[8][8], blackBoard[8][8];

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (row == 0 || row == 1)
			{
				blackBoard[row][col] = 1;
			}
			else
			{
				blackBoard[row][col] = 0;
			}
		}
	}

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (row == 6 || row == 7)
			{
				whiteBoard[row][col] = 1;
			}
			else
			{
				whiteBoard[row][col] = 0;
			}
		}
	}

	piece* selected_piece = nullptr;
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
	rook white_rooks[8];
	knight white_knights[8];
	bishop white_bishops[8];
	queen white_queens[8];
	king white_kings;

	pawn black_pawns[8];
	rook black_rooks[8];
	knight black_knights[8];
	bishop black_bishops[8];
	queen black_queens[8];
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
	white_queens[0].setSprite(white_queen);
	black_queens[0].setSprite(black_queen);
	white_kings.setSprite(white_king);
	black_kings.setSprite(black_king);

	int n = 1;
	for (int i = 0; i < 8; i++ )
	{
		white_pawns[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * n , chessboard.get_board(1,1).getGeometricCenter().y * 13.0f });
		white_pawns[i].setPosition(white_pawns[i].getSprite().getPosition());
		white_pawns[i].setColor('w');
		black_pawns[i].getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * n , chessboard.get_board(1,1).getGeometricCenter().y * 3.0f});
		black_pawns[i].setPosition(black_pawns[i].getSprite().getPosition());
		black_pawns[i].setColor('b');
		n += 2;
	}
	n = 1;
	int j = 3;
	int k = 5;
	for (int i = 0; i < 2; i++)
	{
		white_rooks[i].getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * n, chessboard.get_board(1,1).getGeometricCenter().y * 15.0f});
		white_rooks[i].setPosition(white_rooks[i].getSprite().getPosition());
		white_rooks[i].setColor('w');
		white_knights[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * j , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
		white_knights[i].setPosition(white_knights[i].getSprite().getPosition());
		white_knights[i].setColor('w');
		white_bishops[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * k , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f});
		white_bishops[i].setPosition(white_bishops[i].getSprite().getPosition());
		white_bishops[i].setColor('w');

		black_rooks[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * n, chessboard.get_board(1,1).getGeometricCenter().y });
		black_rooks[i].setPosition(black_rooks[i].getSprite().getPosition());
		black_rooks[i].setColor('b');
		black_knights[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * j, chessboard.get_board(1,1).getGeometricCenter().y });
		black_knights[i].setPosition(black_knights[i].getSprite().getPosition());
		black_knights[i].setColor('b');
		black_bishops[i].getSprite().setPosition({ chessboard.get_board(1,1).getGeometricCenter().x * k, chessboard.get_board(1,1).getGeometricCenter().y });
		black_bishops[i].setPosition(black_bishops[i].getSprite().getPosition());
		black_bishops[i].setColor('b');
		n = 15;
		j = 13;
		k = 11;
	}
	white_queens[0].getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f});
	white_queens[0].setPosition(white_queens[0].getSprite().getPosition());
	white_queens[0].setColor('w');
	white_kings.getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y * 15.0f });
	white_kings.setPosition(white_kings.getSprite().getPosition());
	white_kings.setColor('w');
	black_queens[0].getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 7.0f , chessboard.get_board(1,1).getGeometricCenter().y});
	black_queens[0].setPosition(black_queens[0].getSprite().getPosition());
	black_queens[0].setColor('b');
	black_kings.getSprite().setPosition({chessboard.get_board(1,1).getGeometricCenter().x * 9.0f , chessboard.get_board(1,1).getGeometricCenter().y});
	black_kings.setPosition(black_kings.getSprite().getPosition());
	black_kings.setColor('b');

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
			else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
			{

				sf::Vector2i mousePixel = sf::Mouse::getPosition(*window);
				sf::Vector2f mouseWorld = window->mapPixelToCoords(mousePixel);

				if (turn == 'w')
				{
					for (int i = 0; i < 8; i++) {
						white_pawns[i].setClicked(-1);
						white_pawns[i].getSprite().setScale({ 0.6f, 0.6f });
					}
					for (int i = 0; i < 2; i++) {
						white_rooks[i].setClicked(-1);
						white_rooks[i].getSprite().setScale({ 0.6f, 0.6f });

						white_bishops[i].setClicked(-1);
						white_bishops[i].getSprite().setScale({ 0.6f, 0.6f });

						white_knights[i].setClicked(-1);
						white_knights[i].getSprite().setScale({ 0.6f, 0.6f });
					}
					white_queens[0].setClicked(-1);
					white_queens[0].getSprite().setScale({0.6f, 0.6f});

					white_kings.setClicked(-1);
					white_kings.getSprite().setScale({ 0.6f, 0.6f });

					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						selected_piece = nullptr;
						for (int i = 0; i < 8; i++)
						{
							if (white_pawns[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								white_pawns[i].setClicked(-white_pawns[i].getclicked());

								if (white_pawns[i].getclicked() == 1)
								{
									selected_piece = &white_pawns[i];
									white_pawns[i].getSprite().setScale({ 0.7f,0.7f });
								}
								else if (white_pawns[i].getclicked() == -1)
								{
									white_pawns[i].getSprite().setScale({ 0.6f,0.6f });
								}
							}
						}
						for (int i = 0; i < 2; i++)
						{
							if (white_rooks[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								white_rooks[i].setClicked(-white_rooks[i].getclicked());

								if (white_rooks[i].getclicked() == 1)
								{
									selected_piece = &white_rooks[i];
									white_rooks[i].getSprite().setScale({ 0.7f, 0.7f });
								}
								else if (white_rooks[i].getclicked() == -1)
								{
									white_rooks[i].getSprite().setScale({ 0.6f, 0.6f });
								}
							}
							if (white_bishops[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								white_bishops[i].setClicked(-white_bishops[i].getclicked());

								if (white_bishops[i].getclicked() == 1)
								{
									selected_piece = &white_bishops[i];
									white_bishops[i].getSprite().setScale({ 0.7f, 0.7f });
								}
								else if (white_bishops[i].getclicked() == -1)
								{
									white_bishops[i].getSprite().setScale({ 0.6f, 0.6f });
								}
							}
							if (white_knights[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								white_knights[i].setClicked(-white_knights[i].getclicked());

								if (white_knights[i].getclicked() == 1)
								{
									selected_piece = &white_knights[i];
									white_knights[i].getSprite().setScale({ 0.7f, 0.7f });
								}
								else if (white_knights[i].getclicked() == -1)
								{
									white_knights[i].getSprite().setScale({ 0.6f, 0.6f });
								}
							}
						}
						if (white_queens[0].getSprite().getGlobalBounds().contains(mouseWorld))
						{
							white_queens[0].setClicked(-white_queens[0].getclicked());
							if (white_queens[0].getclicked() == 1)
							{
								selected_piece = &white_queens[0];
								white_queens[0].getSprite().setScale({0.7f, 0.7f});
							}
							else if (white_queens[0].getclicked() == -1)
							{
								white_queens[0].getSprite().setScale({0.6f, 0.6f});
							}
						}
						if (white_kings.getSprite().getGlobalBounds().contains(mouseWorld))
						{
							white_kings.setClicked(-white_kings.getclicked());
							if (white_kings.getclicked() == 1)
							{
								selected_piece = &white_kings;
								white_kings.getSprite().setScale({ 0.7f, 0.7f });
							}
							else if (white_kings.getclicked() == -1)
							{
								white_kings.getSprite().setScale({ 0.6f, 0.6f });
							}
						}
					}
				}
				if (turn == 'b')
				{
					for (int i = 0; i < 8; i++) {
						black_pawns[i].setClicked(-1);
						black_pawns[i].getSprite().setScale({ 0.6f, 0.6f });
					}
					for (int i = 0; i < 2; i++) {
						black_rooks[i].setClicked(-1);
						black_rooks[i].getSprite().setScale({ 0.6f, 0.6f });

						black_bishops[i].setClicked(-1);
						black_bishops[i].getSprite().setScale({ 0.6f, 0.6f });

						black_knights[i].setClicked(-1);
						black_knights[i].getSprite().setScale({ 0.6f, 0.6f });
					}
					black_queens[0].setClicked(-1);
					black_queens[0].getSprite().setScale({0.6f, 0.6f});

					black_kings.setClicked(-1);
					black_kings.getSprite().setScale({ 0.6f, 0.6f });


					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						selected_piece = nullptr;
						for (int i = 0; i < 8; i++)
						{
							if (black_pawns[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								black_pawns[i].setClicked(-black_pawns[i].getclicked());

								if (black_pawns[i].getclicked() == 1)
								{
									selected_piece = &black_pawns[i];
									black_pawns[i].getSprite().setScale({ 0.7f,0.7f });
								}
								else if (black_pawns[i].getclicked() == -1)
								{
									black_pawns[i].getSprite().setScale({ 0.6f,0.6f });
								}
							}
						}
						for (int i = 0; i < 2; i++)
						{
							if (black_rooks[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								black_rooks[i].setClicked(-black_rooks[i].getclicked());

								if (black_rooks[i].getclicked() == 1)
								{
									selected_piece = &black_rooks[i];
									black_rooks[i].getSprite().setScale({ 0.7f, 0.7f });
								}
								else if (black_rooks[i].getclicked() == -1)
								{
									black_rooks[i].getSprite().setScale({ 0.6f, 0.6f });
								}
							}
							if (black_bishops[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								black_bishops[i].setClicked(-black_bishops[i].getclicked());

								if (black_bishops[i].getclicked() == 1)
								{
									selected_piece = &black_bishops[i];
									black_bishops[i].getSprite().setScale({ 0.7f, 0.7f });
								}
								else if (black_bishops[i].getclicked() == -1)
								{
									black_bishops[i].getSprite().setScale({ 0.6f, 0.6f });
								}
							}
							if (black_knights[i].getSprite().getGlobalBounds().contains(mouseWorld))
							{
								black_knights[i].setClicked(-black_knights[i].getclicked());

								if (black_knights[i].getclicked() == 1)
								{
									selected_piece = &black_knights[i];
									black_knights[i].getSprite().setScale({ 0.7f, 0.7f });
								}
								else if (black_knights[i].getclicked() == -1)
								{
									black_knights[i].getSprite().setScale({ 0.6f, 0.6f });
								}
							}
						}
						if (black_queens[0].getSprite().getGlobalBounds().contains(mouseWorld))
						{
							black_queens[0].setClicked(-black_queens[0].getclicked());
							if (black_queens[0].getclicked() == 1)
							{
								selected_piece = &black_queens[0];
								black_queens[0].getSprite().setScale({0.7f, 0.7f});
							}
							else if (black_queens[0].getclicked() == -1)
							{
								black_queens[0].getSprite().setScale({0.6f, 0.6f});
							}
						}
						if (black_kings.getSprite().getGlobalBounds().contains(mouseWorld))
						{
							black_kings.setClicked(-black_kings.getclicked());
							if (black_kings.getclicked() == 1)
							{
								selected_piece = &black_kings;
								black_kings.getSprite().setScale({ 0.7f, 0.7f });
							}
							else if (black_kings.getclicked() == -1)
							{
								black_kings.getSprite().setScale({ 0.6f, 0.6f });
							}
						}
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) 
				{
					if (selected_piece != nullptr) 
					{
						float squareSize = 113.0f; 
						float x = std::floor(mouseWorld.x / squareSize) * squareSize + 56.5f;
						float y = std::floor(mouseWorld.y / squareSize) * squareSize + 56.5f;


						move_integer = selected_piece->determine_move({ x , y }, temp_scale);

						if (move_integer > 0)
						{
							if (selected_piece->check(whiteBoard, blackBoard, move_integer, temp_scale) == 1)
							{
								sf::Vector2f oldPos = selected_piece->getSprite().getPosition();
								selected_piece->move(move_integer, temp_scale);
								sf::Vector2f newPos = selected_piece->getSprite().getPosition();

								if (turn == 'w')
								{
									whiteBoard[(int)(oldPos.y / 113.0f)][(int)(oldPos.x / 113.0f)] = 0;
									whiteBoard[(int)(newPos.y / 113.0f)][(int)(newPos.x / 113.0f)] = 1;

								}
								else if (turn == 'b')
								{
									blackBoard[(int)(oldPos.y / 113.0f)][(int)(oldPos.x / 113.0f)] = 0;
									blackBoard[(int)(newPos.y / 113.0f)][(int)(newPos.x / 113.0f)] = 1;

								}

								turn = (turn == 'w') ? 'b' : 'w';

								selected_piece->setClicked(-1);
								selected_piece->getSprite().setScale({ 0.6f, 0.6f });
								for (int i = 0; i < 8; i++)
								{
									if (selected_piece->getColor() == 'w')
									{
										if (selected_piece->getSprite().getGlobalBounds().contains(black_pawns[i].getPosition()))
										{
											black_pawns[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											black_pawns[i].setPosition({ -1000.0f, -1000.0f });
										}
									}
									else if (selected_piece->getColor() == 'b')
									{
										if (selected_piece->getSprite().getGlobalBounds().contains(white_pawns[i].getPosition()))
										{
											white_pawns[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											white_pawns[i].setPosition({ -1000.0f, -1000.0f });
										}
									}
								}
								for (int i = 0; i < 2; i++)
								{
									if (selected_piece->getColor() == 'w')
									{
										if (selected_piece->getSprite().getGlobalBounds().contains(black_rooks[i].getPosition()))
										{
											black_rooks[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											black_rooks[i].setPosition({ -1000.0f, -1000.0f });
										}
										else if (selected_piece->getSprite().getGlobalBounds().contains(black_knights[i].getPosition()))
										{
											black_knights[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											black_knights[i].setPosition({ -1000.0f, -1000.0f });
										}
										else if (selected_piece->getSprite().getGlobalBounds().contains(black_bishops[i].getPosition()))
										{
											black_bishops[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											black_bishops[i].setPosition({ -1000.0f, -1000.0f });
										}
									}
									else if (selected_piece->getColor() == 'b')
									{
										if (selected_piece->getSprite().getGlobalBounds().contains(white_rooks[i].getPosition()))
										{
											white_rooks[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											white_rooks[i].setPosition({ -1000.0f, -1000.0f });
										}
										else if (selected_piece->getSprite().getGlobalBounds().contains(white_knights[i].getPosition()))
										{
											white_knights[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											white_knights[i].setPosition({ -1000.0f, -1000.0f });
										}
										else if (selected_piece->getSprite().getGlobalBounds().contains(white_bishops[i].getPosition()))
										{
											white_bishops[i].getSprite().setPosition({ -1000.0f,-1000.0f });
											white_bishops[i].setPosition({ -1000.0f, -1000.0f });
										}
									}
									if (selected_piece->getColor() == 'w')
									{
										if (selected_piece->getSprite().getGlobalBounds().contains(black_queens[0].getPosition()))
										{
											black_queens[0].getSprite().setPosition({ -1000.0f,-1000.0f });
											black_queens[0].setPosition({ -1000.0f, -1000.0f });
										}
										else if (selected_piece->getSprite().getGlobalBounds().contains(black_kings.getPosition()))
										{
											black_kings.getSprite().setPosition({ -1000.0f,-1000.0f });
											black_kings.setPosition({ -1000.0f, -1000.0f });
										}
									}
									else if (selected_piece->getColor() == 'b')
									{
										if (selected_piece->getSprite().getGlobalBounds().contains(white_queens[0].getPosition()))
										{
											white_queens[0].getSprite().setPosition({ -1000.0f,-1000.0f });
											white_queens[0].setPosition({ -1000.0f, -1000.0f });
										}
										else if (selected_piece->getSprite().getGlobalBounds().contains(white_kings.getPosition()))
										{
											white_kings.getSprite().setPosition({ -1000.0f,-1000.0f });
											white_kings.setPosition({ -1000.0f, -1000.0f });
										}
									}
								}
								selected_piece = nullptr;
							}
							if (white_kings.getSprite().getPosition() == sf::Vector2f(- 1000.0f, -1000.0f ))
							{
								window->clear();
								window->close();
								std::cout << "Black Wins" << std::endl;
							}
							else if (black_kings.getSprite().getPosition() == sf::Vector2f(-1000.0f, -1000.0f))
							{
								window->clear();
								window->close();
								std::cout << "White Wins" << std::endl;
							}
						}
					}
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
		window->draw(white_queens[0].getSprite());
		window->draw(white_kings.getSprite());
		window->draw(black_queens[0].getSprite());
		window->draw(black_kings.getSprite());

		window->display();
	}

	delete window;
	return 0;
}