#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"


class Move;
class PiecePosition;
struct Position;

class Piece {
private:
	sf::Sprite pieceSprite;
	int x;
	int y;
	bool team;//True for white, False for black.
	char pieceType; //Piece type
	//R for rook.
	//A for knight.
	//B for bishop.
	//Q for queen.
	//K for king.
	//P for pawn.
	bool isPieceMoved;
	static bool isWhiteKingInDanger; //Checking whether white king is in check
	static bool isBlackKingInDanger; //Checking whether black king is in check
public:
	Piece(bool _team, int _x, int _y, sf::Texture& tex,char type);

	sf::Sprite getSprite()const;
	bool getTeam()const;
	char getPieceType()const;
	bool getIsPieceMoved()const;
	Position getPiecePosition()const;

	void setPieceType(char type);
	void setSpriteTexture(sf::Texture& tex);
	void setPosition(int x, int y);
	void setPosition(sf::Vector2f);
	void pieceMoved();
};

void getMoves(std::vector <Move>& Moves,const std::vector <PiecePosition>& pos, const std::vector<Piece*>& pieces, bool turn );
void pawnMove(std::vector <Move>& Moves, const std::vector <PiecePosition>& pos, bool turn,const Piece* piece);


