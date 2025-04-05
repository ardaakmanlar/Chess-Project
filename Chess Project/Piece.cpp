#include "Piece.h"

using namespace sf;
using namespace std;

bool Piece::isWhiteKingInDanger = false;
bool Piece::isBlackKingInDanger = false;

Piece::Piece(bool _team, int _x, int _y, Texture& tex,char type) : team(_team), x(_x), y(_y),pieceType(type) {
	isPieceMoved = false;
	pieceSprite.setPosition(_x * 128, _y * 128);
	pieceSprite.setTexture(tex);

}


Sprite Piece::getSprite()const { return pieceSprite; }
bool Piece::getTeam()const { return team; }
char Piece::getPieceType()const { return pieceType; }
bool Piece::getIsPieceMoved()const { return isPieceMoved; }
Position Piece::getPiecePosition()const {
	Position piecePos;
	piecePos.x = x;
	piecePos.y = y;
	return piecePos;
}

void Piece::pieceMoved() {
	isPieceMoved = true;
}

void Piece::setSpriteTexture(Texture& tex) {
	pieceSprite.setTexture(tex);
}

void Piece::setPosition(int x, int y) {
	pieceSprite.setPosition(x * 128, y * 128);
	this->x = x;
	this->y = y;
}

void Piece::setPosition(Vector2f mousePos) {
	pieceSprite.setPosition(mousePos);
}

void Piece::setPieceType(char type) {
	pieceType = type;
}

void pawnMove(std::vector <Move>& Moves, const std::vector <PiecePosition>& pos, bool turn, const Piece* piece) {

	if (piece->getTeam() != turn) {
		return;
	}
	Position piecePos = piece->getPiecePosition();
	Position nextPos;
	Move move;
	move.curentPos.x = piecePos.x;
	move.curentPos.y = piecePos.y;


	if (turn) {
		PiecePosition  temp;
		temp.ptr = nullptr;
		
		
		
		//Check for diagonals for enemy pieces.
		temp.pos.x = piecePos.x - 1;
		temp.pos.y = piecePos.y - 1;
		if (isSquareHasEnemy(pos, temp, false)) {
			move.nextPos.x = temp.pos.x;
			move.nextPos.y = temp.pos.y;
			Moves.push_back(move);
		}

		temp.pos.x = piecePos.x + 1;
		temp.pos.y = piecePos.y - 1;

		if (isSquareHasEnemy(pos, temp, false)) {
			move.nextPos.x = temp.pos.x;
			move.nextPos.y = temp.pos.y;
			Moves.push_back(move);
		}
		

		//Check for just 1 square move
		temp.pos.x = piecePos.x;
		temp.pos.y = piecePos.y - 1;
		if (!isPositionEmpty(pos, temp)) {
			return;
		}
		move.nextPos.x = piecePos.x;
		move.nextPos.y = piecePos.y - 1;;
		Moves.push_back(move);

		// If this is the first move of the pawn check for 2 square move
		if (!piece->getIsPieceMoved()) {
			temp.pos.y = piecePos.y - 2;
			if (!isPositionEmpty(pos, temp)) {
				return;
			}
			move.nextPos.x = piecePos.x;
			move.nextPos.y = piecePos.y - 2;
			Moves.push_back(move);
		}
		
	}
	else{
		PiecePosition  temp;
		temp.pos.x = piecePos.x;
		temp.pos.y = piecePos.y + 1;
		temp.ptr = nullptr;
		if (!isPositionEmpty(pos, temp)) {
			return;
		}
		move.nextPos.x = piecePos.x;
		move.nextPos.y = piecePos.y + 1;;
		Moves.push_back(move);
		if (!piece->getIsPieceMoved()) {
			temp.pos.y = piecePos.y + 2;
			if (!isPositionEmpty(pos, temp)) {
				return;
			}
			move.nextPos.x = piecePos.x;
			move.nextPos.y = piecePos.y + 2;
			Moves.push_back(move);
		}
	}
}



void getMoves(vector <Move>& Moves,const  vector <PiecePosition>& pos,const std::vector<Piece*>& pieces, bool turn) {
	for (int i = 0; i < pieces.size(); i++){
		switch (pieces[i]->getPieceType()){
		case 'P':
			if(pieces[i]->getPiecePosition().x != -1)
				pawnMove(Moves, pos, turn, pieces[i]);
			break;
		default:
			break;
		}
	}
}

