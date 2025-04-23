#include <SFML/Graphics.hpp>
#include <memory>

enum class PieceColor { WHITE, BLACK, NONE };
enum class PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, NONE };

class piece : public sf::Sprite {
public:
    piece(PieceColor color, PieceType type, sf::Texture& texture, float scale = 0.6f);

    void setBoardPosition(int row, int col, const sf::Vector2f& tileSize);

    PieceColor getColor() const;
    PieceType getType() const;
    sf::Vector2i getBoardPosition() const;

private:
    PieceColor color;
    PieceType type;
    sf::Vector2i boardPosition;
};