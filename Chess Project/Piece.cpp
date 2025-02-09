#include "Piece.h"

Piece::Piece(bool _team, int _x, int _y) : team(_team), x(_x), y(_y) {
	pieceSprite.setPosition(_x * 128, _y * 128);
}


Sprite Piece::getSprite()const { return pieceSprite; }
bool Piece::getTeam()const { return team; }

void Piece::setSpriteTexture(Texture &tex) {
	pieceSprite.setTexture(tex);
}

void Piece::setPosition(int x, int y) {
	pieceSprite.setPosition(x*128, y*128);
}

void Piece::setPosition(Vector2f mousePos) {
	pieceSprite.setPosition(mousePos);
}