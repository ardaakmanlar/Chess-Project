#include <SFML/Graphics.hpp>
#include "Chess.h"
#include "Piece.h"
#include "BoardMaker.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

void Game::run() {

	bool turn = true; // Bool variable for tracking who will play white or black. True for white, false for black.
	bool isMovesCalculated = false; 

	//Vectors for tracking pieces.
	vector <Piece*> Pieces;
	vector <PiecePosition> piecePosisions;
	Texture textures[12];
	LoadTextures(textures);
	placePieces(Pieces, textures, piecePosisions);


	vector <Move> Moves; //Avaliable moves in that turn.
	Move playerMove;


	//Variables for rendaring board and pieces.
	RenderWindow window(VideoMode(1024, 1024), "Chess", Style::Close);
	Texture boardTexture;
	Sprite boardSprite;

	boardTexture.loadFromFile("Textures/boardTexture.png");
	boardSprite.setTexture(boardTexture);


	//Variables for square selection.
	bool squareSelected = false;
	RectangleShape selectedSqure({ 0.f,0.f });
	selectedSqure.setFillColor(Color(96,96,96));
	Vector2f selectedPosition;
	float pX, pY; // pX and pY for holding mouse position.
	bool mouseHeld = false; // Variable for holding mouse is wheter holding or not.

	Event event; 




	while (window.isOpen()) {


		if (!isMovesCalculated) {
			getMoves(Moves, piecePosisions, Pieces, turn);
			isMovesCalculated = true;
			cout << "Total Moves: " << Moves.size() << endl;
			for (const auto& move : Moves) {
				cout << "From (" << move.curentPos.x << ", " << move.curentPos.y << ")"
					<< " to (" << move.nextPos.x << ", " << move.nextPos.y << ")" << endl;
			}
		}


		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		//Getting mouse input but we are making sure that mouse input is taken just once.
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			if (!mouseHeld) { //If already had mouse input don't do anything.
				mouseHeld = true; // Mouse is held.
			}
		}

		if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
			if (mouseHeld) { //If mouse had input before do it now.
				mouseHeld = false; // Mouse is no longer held.

				if (!squareSelected) {
					squareSelected = true;
					pX = event.mouseButton.x;
					pY = event.mouseButton.y;
					placeSelectedSquare(selectedSqure, pX, pY);

					calculatePosition(pX, pY);
					playerMove.curentPos.x = (int)(pX);
					playerMove.curentPos.y = (int)(pY);


				}
				else{
					
					squareSelected = false;
					removeSelectedSquare(selectedSqure);
					pX = event.mouseButton.x;
					pY = event.mouseButton.y;
					calculatePosition(pX, pY);
					playerMove.nextPos.x = (int)(pX);
					playerMove.nextPos.y = (int)(pY);
					
					if (isValidMove(Moves, playerMove)) {
						playMove(playerMove, piecePosisions, Pieces, textures);
						reverseTurn(turn);
						isMovesCalculated = false;
						Moves.clear();
					}


				}
			}
		}

		//Update
		window.draw(boardSprite);
		window.draw(selectedSqure);
		drawPieces(Pieces, window);
		
		window.display();
	}
}