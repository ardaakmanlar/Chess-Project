#pragma once
#include "Piece.h"
#include <vector>
class Piece;

class Position {
public:
	int x;
	int y;
	bool operator==(const Position& other);
};

class Move {
public:
	Position curentPos;
	Position nextPos;
	bool operator==(const Move& other);
};

class PiecePosition {
public:
	Position pos;
	Piece* ptr;
	bool operator==(const PiecePosition& other)const;
};


bool isPositionEmpty(const std::vector<PiecePosition>& positions,const PiecePosition& pos); 
bool isValidMove( std::vector<Move>& moves,  Move& pMove);
bool isSquareHasEnemy(const std::vector<PiecePosition>& positions, const PiecePosition& pos, bool team);
Piece* isDestinationHasPiece(const std::vector<PiecePosition>& positions, const Position& nextPos);