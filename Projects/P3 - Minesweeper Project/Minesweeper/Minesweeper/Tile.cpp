#include "Tile.h"
#include "TextureManager.h"
Tile::Tile()
{
	adjacentTiles.reserve(3);
	hasMine = 0;		// 0 = no mine, 1 = mine
	hasFlag = 0;		// 0 = no flag, 1 = flag
	isRevealed = 0;		// 0 = unrevealed, 1 = revealed
	number = 0;
	setTexture(TextureManager::GetTexture("tile_hidden"));
}
void Tile::calculateTileNumber()
{

	for (unsigned int i = 0; i < adjacentTiles.size(); i++)
	{
		if (adjacentTiles[i]->getHasMine() == 1)
			number++;
	}
}
int Tile::reveal()
{
	/*
	Returns -1 if bomb on this tile
	Returns 1 if tile is either empty or neighboring bomb
	Returns 0 if square was flagged, i.e. do nothing
	*/
	if (hasFlag == 0)
	{	
		isRevealed = 1;
		if (hasMine == 1)
			
			return -1;
		else
			return 1;

	}
	else
		return 0;
}
vector<Tile*>& Tile::getAdjacentTiles()
{
	return adjacentTiles;
}
bool Tile::getHasMine()
{
	return hasMine;
}
bool Tile::getHasFlag()
{
	return hasFlag;
}
bool Tile::getIsRevealed()
{
	return isRevealed;
}
int Tile::getNumber()
{
	return number;
}
void Tile::setAdjacentTiles(vector<Tile*>& adjTiles)
{
	adjacentTiles = adjTiles;
}
void Tile::setHasMine(bool m)
{
	hasMine = m;
}
void Tile::setHasFlag(bool f)
{
	hasFlag = f;
}
void Tile::setIsRevealed(bool r)
{
	isRevealed = r;
}
void Tile::setNumber(int n)
{
	number = n;
}