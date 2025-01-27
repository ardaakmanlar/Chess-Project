#include "Pieces.h"

Pawn::Pawn(bool team, int x, int y) :Piece(team, x, y) {
	Texture temp;
	if (team)
		temp.loadFromFile("Textures/white-pawn.png");
	else
		temp.loadFromFile("Textures/black-pawn.png");
	setPieceTexture(temp);
	setSpriteTexture();
}

Bishop::Bishop(bool team, int x, int y) :Piece(team, x, y) {
	Texture temp;
	if (team)
		temp.loadFromFile("Textures/white-bishop.png");
	else
		temp.loadFromFile("Textures/black-bishop.png");
	setPieceTexture(temp);
	setSpriteTexture();
}


Rook::Rook(bool team, int x, int y) :Piece(team, x, y) {
	Texture temp;
	if (team)
		temp.loadFromFile("Textures/white-bishop.png");
	else
		temp.loadFromFile("Textures/black-bishop.png");
	setPieceTexture(temp);
	setSpriteTexture();
}


Queen::Queen(bool team, int x, int y) :Piece(team, x, y) {
	Texture temp;
	if (team)
		temp.loadFromFile("Textures/white-queen.png");
	else
		temp.loadFromFile("Textures/black-queen.png");
	setPieceTexture(temp);
	setSpriteTexture();
}


Knight::Knight(bool team, int x, int y) :Piece(team, x, y) {
	Texture temp;
	if (team)
		temp.loadFromFile("Textures/white-knight.png");
	else
		temp.loadFromFile("Textures/black-knight.png");
	setPieceTexture(temp);
	setSpriteTexture();
}


King::King(bool team, int x, int y) :Piece(team, x, y) {
	Texture temp;
	if (team)
		temp.loadFromFile("Textures/white-king.png");
	else
		temp.loadFromFile("Textures/black-king.png");
	setPieceTexture(temp);
	setSpriteTexture();
}
