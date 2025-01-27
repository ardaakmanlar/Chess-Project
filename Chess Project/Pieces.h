#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(bool team, int x, int y);
};

class Bishop : public Piece {
public:
	Bishop(bool team, int x, int y);

};

class King : public Piece {
public:
	King(bool team, int x, int y);
};


class Queen : public Piece {
public:
	Queen(bool team, int x, int y);
};

class Rook : public Piece {
public:
	Rook(bool team, int x, int y);

};

class Knight : public Piece {
public:
	Knight(bool team, int x, int y);
};



