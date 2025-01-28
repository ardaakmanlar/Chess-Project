#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;


class Piece {
private:
	Sprite pieceSprite;
	int x;
	int y;
	bool team;
public:
	Piece(bool _team, int _x, int _y);

	Sprite getSprite()const;
	bool getTeam()const;

	void setSpriteTexture(Texture& tex);
};