#pragma once
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Pieces.h"

using namespace std;
using namespace sf;

struct Position{
	int x;
	int y;
};

class Move {
public:
	Position curentPos;
	Position nextPos;
	bool operator==(const Move& other);
};

void LoadTextures(Texture Textures[]);


void placePieces(vector <Piece*>& Pieces, Texture Textures[], vector <Position> piecePosisions);



void drawPieces(const vector <Piece*>& Pieces, RenderWindow& window);



void calculatePosition(float& pX, float& pY);


void placeSelectedSquare(RectangleShape& selectedSquare,float pX, float pY);

void removeSelectedSquare(RectangleShape& selectedSquare);

