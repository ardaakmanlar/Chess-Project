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

void placePieces(vector <Piece*>& Pieces, Texture Textures[], vector <Position> piecePosisions) {
	Position temp;
	
	//Placing white pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Pawn(true, i, 6, Textures[0]));
		temp.x = i;
		temp.y = 6;
		piecePosisions.push_back(temp);
	}

	//Placing black pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Pawn(false, i, 1, Textures[1]));
		temp.x = i;
		temp.y = 1;
		piecePosisions.push_back(temp);
	}

	//Placing white rooks.
	Pieces.push_back(new Rook(true, 0, 7, Textures[6]));
	temp.x = 0;
	temp.y = 7;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Rook(true, 7, 7, Textures[6]));
	temp.x = 7;
	temp.y = 7;
	piecePosisions.push_back(temp);

	//Placing black rooks.
	Pieces.push_back(new Rook(false, 0, 0, Textures[7]));
	temp.x = 0;
	temp.y = 0;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Rook(false, 7, 0, Textures[7]));
	temp.x = 7;
	temp.y = 0;
	piecePosisions.push_back(temp);

	//Placing white knights.
	Pieces.push_back(new Knight(true, 1, 7, Textures[4]));
	temp.x = 1;
	temp.y = 7;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Knight(true, 6, 7, Textures[4]));
	temp.x = 6;
	temp.y = 7;
	piecePosisions.push_back(temp);

	//Placing black knights.
	Pieces.push_back(new Knight(false, 1, 0, Textures[5]));
	temp.x = 1;
	temp.y = 0;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Knight(false, 6, 0, Textures[5]));
	temp.x = 6;
	temp.y = 0;
	piecePosisions.push_back(temp);

	//Placing white bishops.
	Pieces.push_back(new Bishop(true, 2, 7, Textures[2]));
	temp.x = 2;
	temp.y = 7;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Bishop(true, 5, 7, Textures[2]));
	temp.x = 5;
	temp.y = 7;
	piecePosisions.push_back(temp);

	//Placing black bishops.
	Pieces.push_back(new Bishop(false, 2, 0, Textures[3]));
	temp.x = 2;
	temp.y = 0;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Bishop(false, 5, 0, Textures[3]));
	temp.x = 5;
	temp.y = 0;
	piecePosisions.push_back(temp);

	//Placing kings.
	Pieces.push_back(new King(true, 4, 7, Textures[10]));
	temp.x = 4;
	temp.y = 7;
	piecePosisions.push_back(temp);
	Pieces.push_back(new King(false, 4, 0, Textures[11]));
	temp.x = 4;
	temp.y = 0;
	piecePosisions.push_back(temp);

	//Placing queens.
	Pieces.push_back(new Queen(true, 3, 7, Textures[8]));
	temp.x = 3;
	temp.y = 7;
	piecePosisions.push_back(temp);
	Pieces.push_back(new Queen(false, 3, 0, Textures[9]));
	temp.x = 3;
	temp.y = 0;
	piecePosisions.push_back(temp);

}

void drawPieces(const vector <Piece*>& Pieces, RenderWindow& window) {
	for (int i = 0; i < Pieces.size(); i++)	{
		window.draw(Pieces[i]->getSprite());
	}
}

void calculatePosition(float& pX, float& pY) {
	int calX, calY;

	pX /= 128;
	pY /= 128;

}


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

void placeSelectedSquare(RectangleShape& selectedSquare, float pX, float pY) { //Selecting square for a move.
	//Calculating exact square for selected square.
	int x = pX / 128, y = pY / 128;
	selectedSquare.setPosition(x * 128, y * 128);
	//Seting size to square size so we can see the square.
	selectedSquare.setSize({128,128});
}

void removeSelectedSquare(RectangleShape& selectedSquare) { //Removing square selection 
	selectedSquare.setSize({ 0,0 });
}
