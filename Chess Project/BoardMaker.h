#pragma once
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Position.h"

void LoadTextures(sf::Texture Textures[]);


void placePieces(std::vector <Piece*>& Pieces, sf::Texture Textures[], std::vector <PiecePosition>& piecePosisions);



void drawPieces(const std::vector <Piece*>& Pieces, sf::RenderWindow& window);


void calculatePosition(float& pX, float& pY);


void placeSelectedSquare(sf::RectangleShape& selectedSquare, float pX, float pY);

void removeSelectedSquare(sf::RectangleShape& selectedSquare);

void playMove( Move& move,  std::vector <PiecePosition>& positions);

void reverseTurn(bool& turn);