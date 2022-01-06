#pragma once
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "Tile.h"
using std::string;
using std::vector;

class Board
{
	int mineCount;
	int mineTotal;
	vector<vector<Tile>> boardTiles;
public:
	Board();
	Board(string filename);
	bool getIsRevealed(int row, int col);
	bool getHasFlag(int row, int col);
	bool getHasMine(int row, int col);
	bool CheckWin();
	int getTileNumber(int row, int col);
	int getMineCount();
	int leftClicked(int row, int col);
	void rightClicked(int row, int col);
	void RevealAll();
	void SetTileNumbers();
	void ChangeBoard(int number);
	void NeighborReveal(int row, int col);
	void ClusterReveal(int row, int col);	
	void AssignMinesRandom();
	void AssignMinesFromFile(string filename);
	void ClearBoard();
};

