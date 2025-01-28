#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(bool team, int x, int y, Texture& tex);
};

class Bishop : public Piece {
public:
	Bishop(bool team, int x, int y, Texture& tex);

};

class King : public Piece {
public:
	King(bool team, int x, int y, Texture& tex);
};


class Queen : public Piece {
public:
	Queen(bool team, int x, int y, Texture& tex);
};

class Rook : public Piece {
public:
	Rook(bool team, int x, int y, Texture& tex);

};

class Knight : public Piece {
public:
	Knight(bool team, int x, int y, Texture& tex);
};