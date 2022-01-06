#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;

class Tile : sf::Sprite
{
	vector<Tile*> adjacentTiles;
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
	int number;
public:
	Tile();
	void calculateTileNumber();
	int reveal();
	vector<Tile*>& getAdjacentTiles();
	bool getHasMine();
	bool getHasFlag();
	bool getIsRevealed();
	int getNumber();
	void setAdjacentTiles(vector<Tile*>& adjTiles);
	void setHasMine(bool m);
	void setHasFlag(bool f);
	void setIsRevealed(bool r);
	void setNumber(int n);
};

