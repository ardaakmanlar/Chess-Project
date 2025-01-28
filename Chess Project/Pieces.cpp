#include "Pieces.h"

Pawn::Pawn(bool team, int x, int y,Texture& tex):Piece(team, x, y) {
	setSpriteTexture(tex);
}

Bishop::Bishop(bool team, int x, int y, Texture& tex) :Piece(team, x, y) {
	setSpriteTexture(tex);
}


Rook::Rook(bool team, int x, int y, Texture& tex) :Piece(team, x, y) {
	setSpriteTexture(tex);
}


Queen::Queen(bool team, int x, int y, Texture& tex) :Piece(team, x, y) {
	setSpriteTexture(tex);
}


Knight::Knight(bool team, int x, int y, Texture& tex) :Piece(team, x, y) {
	setSpriteTexture(tex);
}


King::King(bool team, int x, int y, Texture& tex) :Piece(team, x, y) {
	setSpriteTexture(tex);
}