#include "BoardMaker.h"


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

void placePieces(vector <Piece*>& Pieces, Texture Textures[]) {


	//Placing white pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Pawn(true, i, 6, Textures[0]));
	}

	//Placing black pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Pawn(false, i, 1, Textures[1]));
	}

	//Placing white rooks.
	Pieces.push_back(new Rook(true, 0, 7, Textures[6]));
	Pieces.push_back(new Rook(true, 7, 7, Textures[6]));

	//Placing black rooks.
	Pieces.push_back(new Rook(false, 0, 0, Textures[7]));
	Pieces.push_back(new Rook(false, 7, 0, Textures[7]));

	//Placing white knights.
	Pieces.push_back(new Knight(true, 1, 7, Textures[4]));
	Pieces.push_back(new Knight(true, 6, 7, Textures[4]));

	//Placing black knights.
	Pieces.push_back(new Knight(false, 1, 0, Textures[5]));
	Pieces.push_back(new Knight(false, 6, 0, Textures[5]));

	//Placing white bishops.
	Pieces.push_back(new Bishop(true, 2, 7, Textures[2]));
	Pieces.push_back(new Bishop(true, 5, 7, Textures[2]));

	//Placing black bishops.
	Pieces.push_back(new Bishop(false, 2, 0, Textures[3]));
	Pieces.push_back(new Bishop(false, 5, 0, Textures[3]));

	//Placing kings.
	Pieces.push_back(new King(true, 4, 7, Textures[10]));
	Pieces.push_back(new King(false, 4, 0, Textures[11]));

	//Placing queens.
	Pieces.push_back(new Queen(true, 3, 7, Textures[8]));
	Pieces.push_back(new Queen(false, 3, 0, Textures[9]));

}

void drawPieces(const vector <Piece*>& Pieces, RenderWindow& window) {
	for (int i = 0; i < Pieces.size(); i++) {
		window.draw(Pieces[i]->getSprite());
	}
}

