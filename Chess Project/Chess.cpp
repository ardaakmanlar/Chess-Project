#include <SFML/Graphics.hpp>
#include "Chess.h"
#include "Pieces.h"
#include "BoardMaker.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>



using namespace std;
using namespace sf;



void Game::run() {
	/*
	* WIP
	Move test, test1;
	test.curentPos.x = 0;
	test.curentPos.y = 0;

	test.nextPos.x = 1;
	test.nextPos.y = 1;
	*/



	bool turn = true; // True for white false for black.
	vector <Piece*> Pieces;
	vector <Position> piecePosisions;
	Texture textures[12];
	LoadTextures(textures);
	placePieces(Pieces, textures, piecePosisions);

	RenderWindow window(VideoMode(1024, 1024), "Chess", Style::Close);


	Texture boardTexture;
	Sprite boardSprite;


	bool squareSelected = false;
	RectangleShape selectedSqure({ 0.f,0.f });
	selectedSqure.setFillColor(Color(96,96,96));
	Vector2f selectedPosition;

	boardTexture.loadFromFile("Textures/boardTexture.png");
	boardSprite.setTexture(boardTexture);


	Event event;
	float pX, pY; // pX and pY for holding mouse position.
	bool mouseHeld = false; // Variable for holding mouse is wheter holding or not.

	while (window.isOpen()) {


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
					/*WIP
					calculatePosition(pX, pY);
					test1.curentPos.x = (int)(pX);
					test1.curentPos.y = (int)(pY);
					cout << "Current pos: " << test1.curentPos.x << " " << test1.curentPos.y << endl;
					*/

				}
				else{
					
					squareSelected = false;
					removeSelectedSquare(selectedSqure);
					/*	WIP
					pX = event.mouseButton.x;
					pY = event.mouseButton.y;
					calculatePosition(pX, pY);
					test1.nextPos.x = (int)(pX);
					test1.nextPos.y = (int)(pY);
					cout << "Next pos: " << test1.nextPos.x << " " << test1.nextPos.y << endl;
					if (test == test1) {
						Pieces[1]->setPosition(pX, pY);
					}
					*/
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