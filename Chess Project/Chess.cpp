#include <SFML/Graphics.hpp>
#include "Chess.h"
#include "Pieces.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

void placePieces(vector <Piece*> &Pieces) {

	
	//Placing white pawns.
	for (int i = 0; i < 8; i++){
		Pieces.push_back(new Pawn(true, i, 6));
	}

	//Placing black pawns.
	for (int i = 0; i < 8; i++) {
		Pieces.push_back(new Pawn(false, i, 1));
	}

	//Placing white rooks.
	Pieces.push_back(new Rook(true, 0, 7));
	Pieces.push_back(new Rook(true, 7, 7));

	//Placing black rooks.
	Pieces.push_back(new Rook(false, 0, 0));
	Pieces.push_back(new Rook(false, 7, 0));

	//Placing white knights.
	Pieces.push_back(new Knight(true, 1, 7));
	Pieces.push_back(new Knight(true, 6, 7));

	//Placing black knights.
	Pieces.push_back(new Knight(false, 1, 0));
	Pieces.push_back(new Knight(false, 6, 0));

	//Placing white bishops.
	Pieces.push_back(new Bishop(true, 2, 7));
	Pieces.push_back(new Bishop(true, 5, 7));

	//Placing black bishops.
	Pieces.push_back(new Bishop(false, 2, 0));
	Pieces.push_back(new Bishop(false, 5, 0));

	//Placing kings.
	Pieces.push_back(new King(true, 4, 7));
	Pieces.push_back(new King(false, 4, 0));

	//Placing queens.
	Pieces.push_back(new Queen(true, 3, 7));
	Pieces.push_back(new Queen(false, 3, 0));

}
 
void drawPieces(const vector <Piece*>& Pieces, RenderWindow &window) {
	for (int i = 0; i < Pieces.size(); i++){
		window.draw(Pieces[i]->getSprite());
	}
}


void calculatePosition(int& pX, int& pY) {
	int xCount = -1, yCount = -1;
	while (pX) {
		pX -= 128;
		xCount++;
	}
	while (pY) {
		pY -= 128;
		yCount++;
	}

}
void Game::run() {

	bool turn = true; // True for white false for black.
	vector <Piece*> Pieces;
	placePieces(Pieces);

	RenderWindow window(VideoMode(1024, 1024), "Chess", Style::Close); 
	
	
	Texture boardTexture;
	Sprite boardSprite;

	boardTexture.loadFromFile("Textures/boardTexture.png");
	boardSprite.setTexture(boardTexture);


	Event event;

	while (window.isOpen()) {
		

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
 		}
		/*
		if (event.MouseButtonPressed) {

			if (event.mouseButton.button == Mouse::Button::Right) {
				int pX, pY;
				pX = event.mouseButton.x;
				pY = event.mouseButton.y;
				cout << "X: " << pX << " Y: " << pY << endl;
				calculatePosition(pX, pY);
				rec.setPosition(Vector2f(pX*128, pY*128));

			}
		}
		*/

		window.draw(boardSprite);

		drawPieces(Pieces, window);
		window.display();
	}

}