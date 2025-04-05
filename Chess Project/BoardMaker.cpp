#include "BoardMaker.h"
#include <iostream>

using namespace std;
using namespace sf;


void LoadTextures(Texture Textures[]) {
	Textures[0].loadFromFile("Textures/white-pawn.png");
	Textures[1].loadFromFile("Textures/black-pawn.png");
	Textures[2].loadFromFile("Textures/white-bishop.png");
	Textures[3].loadFromFile("Textures/black-bishop.png");
	Textures[4].loadFromFile("Textures/white-knight.png");
	Textures[5].loadFromFile("Textures/black-knight.png");
	Textures[6].loadFromFile("Textures/white-rook.png");
	Textures[7].loadFromFile("Textures/black-rook.png");
	Textures[8].loadFromFile("Textures/white-queen.png");
	Textures[9].loadFromFile("Textures/black-queen.png");
	Textures[10].loadFromFile("Textures/white-king.png");
	Textures[11].loadFromFile("Textures/black-king.png");
}

void placePieces(vector <Piece*>& Pieces, Texture Textures[], vector <PiecePosition>& piecePosisions) {
	PiecePosition temp_pos;

	//Placing white pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Piece(true, i, 6, Textures[0], 'P'));
		temp_pos.pos.x = i;
		temp_pos.pos.y = 6;
		temp_pos.ptr = Pieces[Pieces.size() - 1];
		piecePosisions.push_back(temp_pos);
	}

	//Placing black pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Piece(false, i, 1, Textures[1], 'P'));
		temp_pos.pos.x = i;
		temp_pos.pos.y = 1;
		temp_pos.ptr = Pieces[Pieces.size() - 1];
		piecePosisions.push_back(temp_pos);
	}

	//Placing white rooks.
	Pieces.push_back(new Piece(true, 0, 7, Textures[6], 'R'));
	temp_pos.pos.x = 0;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(true, 7, 7, Textures[6], 'R'));
	temp_pos.pos.x = 7;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing black rooks.
	Pieces.push_back(new Piece(false, 0, 0, Textures[7], 'R'));
	temp_pos.pos.x = 0;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(false, 7, 0, Textures[7], 'R'));
	temp_pos.pos.x = 7;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing white knights.
	Pieces.push_back(new Piece(true, 1, 7, Textures[4], 'A'));
	temp_pos.pos.x = 1;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(true, 6, 7, Textures[4], 'A'));
	temp_pos.pos.x = 1;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing black knights.
	Pieces.push_back(new Piece(false, 1, 0, Textures[5], 'A'));
	temp_pos.pos.x = 1;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(false, 6, 0, Textures[5], 'A'));
	temp_pos.pos.x = 6;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing white bishops.
	Pieces.push_back(new Piece(true, 2, 7, Textures[2], 'B'));
	temp_pos.pos.x = 2;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(true, 5, 7, Textures[2], 'B'));
	temp_pos.pos.x = 5;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing black bishops.
	Pieces.push_back(new Piece(false, 2, 0, Textures[3], 'B'));
	temp_pos.pos.x = 2;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(false, 5, 0, Textures[3], 'B'));
	temp_pos.pos.x = 5;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing kings.
	Pieces.push_back(new Piece(true, 4, 7, Textures[10], 'K'));
	temp_pos.pos.x = 4;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(false, 4, 0, Textures[11], 'K'));
	temp_pos.pos.x = 4;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

	//Placing queens.
	Pieces.push_back(new Piece(true, 3, 7, Textures[8], 'Q'));
	temp_pos.pos.x = 3;
	temp_pos.pos.y = 7;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);
	Pieces.push_back(new Piece(false, 3, 0, Textures[9], 'Q'));
	temp_pos.pos.x = 3;
	temp_pos.pos.y = 0;
	temp_pos.ptr = Pieces[Pieces.size() - 1];
	piecePosisions.push_back(temp_pos);

}


void drawPieces(const vector <Piece*>& Pieces, RenderWindow& window) {
	for (int i = 0; i < Pieces.size(); i++) {
		window.draw(Pieces[i]->getSprite());
	}
}

void calculatePosition(float& pX, float& pY) {
	int calX, calY;

	pX /= 128;
	pY /= 128;

}




void placeSelectedSquare(RectangleShape& selectedSquare, float pX, float pY) { //Selecting square for a move.
	//Calculating exact square for selected square.
	int x = pX / 128, y = pY / 128;
	selectedSquare.setPosition(x * 128, y * 128);
	//Seting size to square size so we can see the square.
	selectedSquare.setSize({ 128,128 });
}

void removeSelectedSquare(RectangleShape& selectedSquare) { //Removing square selection 
	selectedSquare.setSize({ 0,0 });
}


void playMove(Move& move, std::vector <PiecePosition>& positions,std::vector <Piece*> Pieces, Texture Textures[]) {
	Piece* enemyPiece = isDestinationHasPiece(positions, move.nextPos);
	Piece* thisPiece = isDestinationHasPiece(positions, move.nextPos);
	int enemyPieceIndex = findPieceIndex(Pieces, enemyPiece);
	int thisPieceIndex = findPieceIndex(Pieces, enemyPiece);
	if (enemyPiece != nullptr) {
		if (enemyPieceIndex == -1) {
			cerr << "Invalid piece index. ";
			return;
		}
		Pieces[enemyPieceIndex]->setPosition(-1, -1);
	}
	int i;
	for (i = 0; i < positions.size(); i++) {
		if (move.curentPos == positions[i].pos) {
			break;
		}
	}
	if (!positions[i].ptr->getIsPieceMoved()) {
		positions[i].ptr->pieceMoved();
	}

	if (Pieces[thisPieceIndex]->getPieceType() == 'P') {
		if (Pieces[thisPieceIndex]->getTeam()) {
			if (move.nextPos.y == 0) {
				cout << "BABABOY";
				Pieces[thisPieceIndex]->setPieceType('Q');
				Pieces[thisPieceIndex]->setSpriteTexture(Textures[8]);
			}
		}
		else {
			if (move.nextPos.y == 7) {
				Pieces[thisPieceIndex]->setPieceType('Q');
			}
		}
	}
	positions[i].ptr->setPosition(move.nextPos.x, move.nextPos.y);
	positions[i].pos.x = move.nextPos.x;
	positions[i].pos.y = move.nextPos.y;

}


void reverseTurn(bool& turn) {
	if (turn) {
		turn = false;
		return;
	}
	turn = true;
}

int findPieceIndex(std::vector <Piece*> Pieces, Piece* piece) {
	int count = 0;
	for (int i = 0; i < Pieces.size(); i++)	{
		if (piece == Pieces[i]) {
			return count;
		}
		count++;
	}
	return 0;
}