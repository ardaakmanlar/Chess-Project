#include "Position.h"

bool Move::operator==(const Move& other) {
	if (&other == this)
		return true;
	if (other.curentPos.x == curentPos.x) {
		if (other.curentPos.y == curentPos.y) {
			if (other.nextPos.x == nextPos.x) {
				if (other.nextPos.y == nextPos.y) {
					return true;
				}
			}
		}
	}
	return false;
}

bool PiecePosition::operator==(const PiecePosition& other)const {
	if (this == &other)
		return true;

	if (pos.x == other.pos.x) {
		if (pos.y == other.pos.y) {
			return true;
		}
	}
	
	return false;
}

bool isPositionEmpty(const std::vector<PiecePosition>& positions, const PiecePosition& pos) {
	for (int i = 0; i < positions.size(); i++){
		if (pos == positions[i]) {
			return false;
		}
	}
	return true;
}

bool isValidMove( std::vector<Move>& moves,  Move& pMove) {
	for (int i = 0; i < moves.size(); i++){
		if (pMove == moves[i]) {
			return true;
		}
	}
	return false;
}

bool Position::operator==(const Position& other) {
	if (this == &other)
		return true;
	if (x == other.x) {
		if (y == other.y) {
			return true;
		}
	}
	return false;
}

bool isSquareHasEnemy(const std::vector<PiecePosition>& positions, const PiecePosition& pos, bool team) {
	for (int i = 0; i < positions.size(); i++) {
		if(positions[i].ptr->getTeam() == team){
			if (pos == positions[i])
				return true;
		}
	}
	return false;
}

Piece* isDestinationHasPiece(const std::vector<PiecePosition>& positions,const Position& nextPos) {
	PiecePosition pos;
	pos.pos.x = nextPos.x;
	pos.pos.y = nextPos.y;
	pos.ptr = nullptr;
	for (int i = 0; i < positions.size(); i++) {
		if (pos == positions[i]) {
			return positions[i].ptr;
		}
	}
	return nullptr;
}