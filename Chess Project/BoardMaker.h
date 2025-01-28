#pragma once
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Pieces.h"

using namespace std;
using namespace sf;


void LoadTextures(Texture Textures[]);


void placePieces(vector <Piece*>& Pieces, Texture Textures[]);



void drawPieces(const vector <Piece*>& Pieces, RenderWindow& window);