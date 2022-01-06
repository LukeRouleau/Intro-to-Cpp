#include "Board.h"

Board::Board()
{
	mineCount = 0;
	mineTotal = 0;
	// 1. create the vector of tiles (no bombs, unrevealed, unflagged)
	boardTiles.reserve(16);
	for (unsigned int i = 0; i < boardTiles.capacity(); i++)
	{
		vector<Tile> row;
		for (unsigned int j = 0; j < 25; j++)
		{
			Tile tile;
			row.push_back(tile);
		}
		boardTiles.push_back(row);
	}

		// a) for each tile, set its vector of adjacentTiles
	for (int i = 0; i < (int)boardTiles.size(); i++)
	{
		for (int j = 0; j < (int)boardTiles[i].size(); j++)
		{
			vector<Tile*> adjTiles;
			for (int u = (i - 1); u <= (i + 1); u++)
			{
				if (u >= 0 && u < 16)
				{
					for (int v = (j - 1); v <= (j + 1); v++)
					{
						if (u == i && v == j)
							continue;
						else if (v >= 0 && v < 25)
							adjTiles.push_back(&boardTiles[u][v]);
					}
				}
			}
			boardTiles[i][j].setAdjacentTiles(adjTiles);
		}
	}
	// 2. assign the tiles bombs randomly (increment mine count)
	AssignMinesRandom();

	// 3. set tile "number" variable for the number of neighboring mines
	SetTileNumbers();
}

Board::Board(string filename)
{
	mineCount = 0;
	// 1. create the vector of tiles (no bombs, unrevealed, unflagged)
	boardTiles.reserve(16);
	for (unsigned int i = 0; i < boardTiles.capacity(); i++)
	{
		vector<Tile> row;
		for (int j = 0; j < 25; j++)
		{
			Tile tile;
			row.push_back(tile);
		}
		boardTiles.push_back(row);
	}

	// a) for each tile, set its vector of adjacentTiles
	for (int i = 0; i < (int)boardTiles.size(); i++)
	{
		for (int j = 0; j < (int)boardTiles[i].size(); j++)
		{
			vector<Tile*> adjTiles;
			for (int u = (i - 1); u <= (i + 1); u++)
			{
				if (u >= 0 && u < 16)
				{
					for (int v = (j - 1); v <= (j + 1); v++)
					{
						if (u == i && v == j)
							continue;
						else if (v >= 0 && v < 25)
							adjTiles.push_back(&boardTiles[u][v]);
					}
				}
			}
			boardTiles[i][j].setAdjacentTiles(adjTiles);
		}
	}
	// 2. read in a board file and assign mines accordingly
	AssignMinesFromFile(filename);
	// 3. set tile "number" variable for the number of neighboring mines
	SetTileNumbers();

}
int Board::leftClicked(int row, int col)
{
	int result = boardTiles[row][col].reveal();
	if (result == -1)
	{
		RevealAll();
		return -1;
	}
		
	else if (result == 1)
	{
		if (boardTiles[row][col].getNumber() == 0)	// No cluster reveal
		{
			boardTiles[row][col].setIsRevealed(0);
			ClusterReveal(row, col);
		}
	}
	return 0;
}

bool Board::getIsRevealed(int row, int col)
{
	return boardTiles[row][col].getIsRevealed();
}

bool Board::getHasFlag(int row, int col)
{
	return boardTiles[row][col].getHasFlag();
}

bool Board::getHasMine(int row, int col)
{
	return boardTiles[row][col].getHasMine();
}

bool Board::CheckWin()
{
	int clearedTileNum = 0;
	for (unsigned int i = 0; i < boardTiles.size(); i++)
	{
		for (unsigned int j = 0; j < boardTiles[i].size(); j++)
		{
			if (boardTiles[i][j].getHasMine() == 1 && boardTiles[i][j].getIsRevealed() == 1)
				return 0;
			if (boardTiles[i][j].getHasMine() == 0 && boardTiles[i][j].getIsRevealed() == 1)
				clearedTileNum++;
		}
	}
	if (clearedTileNum == (400 - mineTotal))
		return 1;
	else
		return 0;
}

int Board::getTileNumber(int row, int col)
{
	return boardTiles[row][col].getNumber();
}

int Board::getMineCount()
{
	return mineCount;
}

void Board::rightClicked(int row, int col)
{
	if (boardTiles[row][col].getIsRevealed() == 0)
	{
		if (boardTiles[row][col].getHasFlag() == 1)
		{
			boardTiles[row][col].setHasFlag(0);
			mineCount++;
		}
		else
		{
			boardTiles[row][col].setHasFlag(1);
			mineCount--;
		}
	}
}

void Board::RevealAll()
{
	mineCount = 0;
	for (unsigned int i = 0; i < boardTiles.size(); i++)
	{
		for (unsigned int j = 0; j < boardTiles[i].size(); j++)
		{
			boardTiles[i][j].setHasFlag(0);
			boardTiles[i][j].setIsRevealed(1);
		}
	}
}

void Board::SetTileNumbers()
{
	for (unsigned int i = 0; i < boardTiles.size(); i++)
	{
		for (unsigned int j = 0; j < boardTiles[i].size(); j++)
		{
			if (boardTiles[i][j].getHasMine() == 1)
				boardTiles[i][j].setNumber(-1);
			else
				boardTiles[i][j].calculateTileNumber();
		}
	}
}

void Board::ChangeBoard(int number)	// 0 : New Random Board, 1 : testboard1, 2 : testboard2, 3 : testboard3
{
	ClearBoard();
	if (number == 0)
	{
		AssignMinesRandom();
		SetTileNumbers();
	}
	else if (number == 1)
	{
		AssignMinesFromFile("boards/testboard1.brd");
		SetTileNumbers();
	}
	else if (number == 2)
	{
		AssignMinesFromFile("boards/testboard2.brd");
		SetTileNumbers();
	}
	else if (number == 3)
	{
		AssignMinesFromFile("boards/testboard3.brd");
		SetTileNumbers();
	}
}
void Board::NeighborReveal(int row, int col)
{
	boardTiles[row][col].setIsRevealed(1);
	if (boardTiles[row][col].getHasFlag() == 1)
		mineCount++;
	boardTiles[row][col].setHasFlag(0);
	for (int i = 0; i < boardTiles[row][col].getAdjacentTiles().size(); i++)
	{
		if (boardTiles[row][col].getAdjacentTiles()[i]->getNumber() > 0)
		{
			boardTiles[row][col].getAdjacentTiles()[i]->setIsRevealed(1);
			if (boardTiles[row][col].getAdjacentTiles()[i]->getHasFlag() == 1)
				mineCount++;
			boardTiles[row][col].getAdjacentTiles()[i]->setHasFlag(0);
		}
		
	}
}
void Board::ClusterReveal(int row, int col)
{
	if (row < 0 || row > 15 || col < 0 || col > 24)
		return;
	if (boardTiles[row][col].getNumber() == 0 && boardTiles[row][col].getIsRevealed() == 0)
	{
		NeighborReveal(row, col);
		ClusterReveal(row + 1, col);
		ClusterReveal(row - 1, col);
		ClusterReveal(row, col + 1);
		ClusterReveal(row, col - 1);
	}
	else
		return;
}
void Board::AssignMinesRandom()
{
	mineTotal = 0;
	mt19937 random_mt;
	random_mt.seed(rand());
	uniform_int_distribution<int> i_dist(0, 15);
	uniform_int_distribution<int> j_dist(0, 24);
	while (mineCount < 50)
	{
		int iCoor = i_dist(random_mt);
		int jCoor = j_dist(random_mt);
		if (boardTiles[iCoor][jCoor].getHasMine() == 1)
			continue;
		else
		{
			boardTiles[iCoor][jCoor].setHasMine(1);
			mineCount++;
			mineTotal++;
		}
	}
}
void Board::AssignMinesFromFile(string filename)
{
	mineTotal = 0;
	ifstream file(filename);
	unsigned int i = 0;
	string board_row;
	if (file.is_open())
	{
		while (getline(file, board_row))
		{
			for (unsigned int j = 0; j < board_row.length(); j++)
			{
				if (board_row[j] == '1')
				{
					boardTiles[i][j].setHasMine(1);
					mineCount++;
					mineTotal++;
				}
			}
			i++;
		}
	}
}
void Board::ClearBoard()
{
	mineCount = 0;
	for (unsigned int i = 0; i < boardTiles.size(); i++)
	{
		for (unsigned int j = 0; j < boardTiles[i].size(); j++)
		{
			boardTiles[i][j].setHasMine(0);
			boardTiles[i][j].setHasFlag(0);
			boardTiles[i][j].setIsRevealed(0);
			boardTiles[i][j].setNumber(0);
		}
	}
}