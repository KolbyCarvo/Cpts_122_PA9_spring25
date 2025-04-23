#include "piece.h"
#include <iostream>

piece::piece(PieceColor color, PieceType type, sf::Texture& texture, float scale)
    : color(color), type(type), boardPosition(-1, -1) // Initialize with invalid position
{
    setTexture(texture);
    setScale(scale, scale);

    // Set origin to center of the sprite for better positioning
    sf::FloatRect bounds = getLocalBounds();
    setOrigin(bounds.width / 2, bounds.height / 2);
}

// Sets the board position and calculates pixel position
void piece::setBoardPosition(int row, int col, const sf::Vector2f& tileSize)
{
    // Validate input
    if (row < 0 || row > 7 || col < 0 || col > 7) {
        std::cerr << "Warning: Invalid board position (" << row << ", " << col << ")\n";
        return;
    }

    // Store board coordinates
    boardPosition.x = col;
    boardPosition.y = row;

    // Calculate pixel position (center of the tile)
    float pixelX = col * tileSize.x + tileSize.x / 2;
    float pixelY = row * tileSize.y + tileSize.y / 2;

    setPosition(pixelX, pixelY);
}

// Getter for piece color
PieceColor piece::getColor() const
{
    return color;
}

// Getter for piece type
PieceType piece::getType() const
{
    return type;
}

// Getter for board position
sf::Vector2i piece::getBoardPosition() const
{
    return boardPosition;
}