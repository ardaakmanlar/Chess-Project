#include <SFML/Graphics.hpp>
#include "Chess.h"
#include "Pieces.h"
#include "BoardMaker.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

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
	Texture textures[12];
	LoadTextures(textures);
	placePieces(Pieces,textures);

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