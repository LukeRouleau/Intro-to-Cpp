#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
#include "Board.h"
using namespace std;

int main()
{
	//==========Initialize Board==========
	bool isDebugMode = 0;
	int gameState = 0;
	Board board;
	sf::Sprite mine;
	sf::Sprite revealedTile;
	sf::Sprite unrevealedTile;
	sf::Sprite flag;
	sf::Sprite number1;
	sf::Sprite number2;
	sf::Sprite number3;
	sf::Sprite number4;
	sf::Sprite number5;
	sf::Sprite number6;
	sf::Sprite number7;
	sf::Sprite number8;
	sf::Sprite debug;
	sf::Sprite test_1;
	sf::Sprite test_2;
	sf::Sprite test_3;
	sf::Sprite face_happy;
	sf::Sprite face_lose;
	sf::Sprite face_win;
	sf::Sprite d0;
	sf::Sprite d1;
	sf::Sprite d2;
	sf::Sprite d3;
	sf::Sprite d4;
	sf::Sprite d5;
	sf::Sprite d6;
	sf::Sprite d7;
	sf::Sprite d8;
	sf::Sprite d9;
	sf::Sprite negative;

	mine.setTexture(TextureManager::GetTexture("mine"));
	revealedTile.setTexture(TextureManager::GetTexture("tile_revealed"));
	unrevealedTile.setTexture(TextureManager::GetTexture("tile_hidden"));
	flag.setTexture(TextureManager::GetTexture("flag"));
	number1.setTexture(TextureManager::GetTexture("number_1"));
	number2.setTexture(TextureManager::GetTexture("number_2"));
	number3.setTexture(TextureManager::GetTexture("number_3"));
	number4.setTexture(TextureManager::GetTexture("number_4"));
	number5.setTexture(TextureManager::GetTexture("number_5"));
	number6.setTexture(TextureManager::GetTexture("number_6"));
	number7.setTexture(TextureManager::GetTexture("number_7"));
	number8.setTexture(TextureManager::GetTexture("number_8"));
	debug.setTexture(TextureManager::GetTexture("debug"));
	test_1.setTexture(TextureManager::GetTexture("test_1"));
	test_2.setTexture(TextureManager::GetTexture("test_2"));
	test_3.setTexture(TextureManager::GetTexture("test_3"));
	face_happy.setTexture(TextureManager::GetTexture("face_happy"));
	face_lose.setTexture(TextureManager::GetTexture("face_lose"));
	face_win.setTexture(TextureManager::GetTexture("face_win"));
	d0.setTexture(TextureManager::GetTexture("digits"));
	d1.setTexture(TextureManager::GetTexture("digits"));
	d2.setTexture(TextureManager::GetTexture("digits"));
	d3.setTexture(TextureManager::GetTexture("digits"));
	d4.setTexture(TextureManager::GetTexture("digits"));
	d5.setTexture(TextureManager::GetTexture("digits"));
	d6.setTexture(TextureManager::GetTexture("digits"));
	d7.setTexture(TextureManager::GetTexture("digits"));
	d8.setTexture(TextureManager::GetTexture("digits"));
	d9.setTexture(TextureManager::GetTexture("digits"));
	negative.setTexture(TextureManager::GetTexture("digits"));

	d0.setTextureRect(sf::IntRect(0, 0, 21, 32));
	d1.setTextureRect(sf::IntRect(22, 0, 21, 32));
	d2.setTextureRect(sf::IntRect(43, 0, 21, 32));
	d3.setTextureRect(sf::IntRect(64, 0, 21, 32));
	d4.setTextureRect(sf::IntRect(85, 0, 21, 32));
	d5.setTextureRect(sf::IntRect(106, 0, 21, 32));
	d6.setTextureRect(sf::IntRect(127, 0, 21, 32));
	d7.setTextureRect(sf::IntRect(148, 0, 21, 32));
	d8.setTextureRect(sf::IntRect(169, 0, 21, 32));
	d9.setTextureRect(sf::IntRect(190, 0, 21, 32));
	negative.setTextureRect(sf::IntRect(211, 0, 21, 32));
	face_happy.setOrigin((face_happy.getGlobalBounds().width / 2.0f), 0.0f);
	face_lose.setOrigin((face_happy.getGlobalBounds().width / 2.0f), 0.0f);
	face_win.setOrigin((face_happy.getGlobalBounds().width / 2.0f), 0.0f);
	debug.setOrigin((debug.getGlobalBounds().width / 2.0f), 0.0f);
	test_1.setOrigin((test_1.getGlobalBounds().width / 2.0f), 0.0f);
	test_2.setOrigin((test_2.getGlobalBounds().width / 2.0f), 0.0f);
	test_3.setOrigin((test_3.getGlobalBounds().width / 2.0f), 0.0f);

	map<int, sf::Sprite> tileNumbers;
	tileNumbers[1] = number1;
	tileNumbers[2] = number2;
	tileNumbers[3] = number3;
	tileNumbers[4] = number4;
	tileNumbers[5] = number5;
	tileNumbers[6] = number6;
	tileNumbers[7] = number7;
	tileNumbers[8] = number8;

	map<int, sf::Sprite> digitNumbers;
	digitNumbers[0] = d0;
	digitNumbers[1] = d1;
	digitNumbers[2] = d2;
	digitNumbers[3] = d3;
	digitNumbers[4] = d4;
	digitNumbers[5] = d5;
	digitNumbers[6] = d6;
	digitNumbers[7] = d7;
	digitNumbers[8] = d8;
	digitNumbers[9] = d9;
	digitNumbers[10] = negative;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);
	while (window.isOpen())
	{
		//==========Input==========
		int xClickCoor = 0;
		int yClickCoor = 0;
		int clickRow = 0;
		int clickCol = 0;
		sf::Event event;
		while (window.pollEvent(event))	
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				xClickCoor = event.mouseButton.x;
				yClickCoor = event.mouseButton.y;
				clickRow = yClickCoor / unrevealedTile.getGlobalBounds().height;
				clickCol = xClickCoor / unrevealedTile.getGlobalBounds().width;
				if (clickCol > 24)	//Safeguard
					clickCol = 24;
				if (event.mouseButton.button == sf::Mouse::Left)
				{					
					//Clicking below board
					if (clickRow >= 16)
					{
						int lowerBound = (unrevealedTile.getGlobalBounds().height * 16) + face_happy.getGlobalBounds().height;
						if (yClickCoor < lowerBound && yClickCoor)
						{
							auto facePos = face_happy.getPosition();
							auto debugPos = debug.getPosition();
							auto test1Pos = test_1.getPosition();
							auto test2Pos = test_2.getPosition();
							auto test3Pos = test_3.getPosition();
							float xAdjust = face_happy.getGlobalBounds().width / 2.0f;
							//Face
							if (xClickCoor > (facePos.x - xAdjust) && xClickCoor < (facePos.x + xAdjust))
							{
								gameState = 0;
								board.ChangeBoard(0);
							}
							//Debug
							else if (xClickCoor > (debugPos.x - xAdjust) && xClickCoor < (debugPos.x + xAdjust))
							{
								if (isDebugMode)
									isDebugMode = 0;
								else
									isDebugMode = 1;
							}
							//Test1
							else if (xClickCoor > (test1Pos.x - xAdjust) && xClickCoor < (test1Pos.x + xAdjust))
							{
								gameState = 0;
								board.ChangeBoard(1);
							}
							//Test2
							else if (xClickCoor > (test2Pos.x - xAdjust) && xClickCoor < (test2Pos.x + xAdjust))
							{
								gameState = 0;
								board.ChangeBoard(2);
							}
							//Test3
							else if (xClickCoor > (test3Pos.x - xAdjust) && xClickCoor < (test3Pos.x + xAdjust))
							{
								gameState = 0;
								board.ChangeBoard(3);
							}	
						}
					}

					//Clicking on board
					else if (clickRow < 16)
					{
						if (gameState == -1)
							break;
						if (gameState == 1)
							break;
						gameState = board.leftClicked(clickRow, clickCol);
						if (board.CheckWin() == 1)
						{
							gameState = 1;
						}
					}
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					if (clickRow < 16)
					{
						if (gameState == -1)
							break;
						if (gameState == 1)
							break;
						board.rightClicked(clickRow, clickCol);
					}
				}
			}
		}
		//==========Update==========
		window.clear(sf::Color(255, 255, 255, 255));

		//==========Drawing==========
		float xPos = 0;
		float yPos = 0;
		for (int i = 0; i < 16; i++)	//main drawing loop
		{
			for (int j = 0; j < 25; j++)
			{
				if (board.getIsRevealed(i, j) == 0)
				{
					xPos = (float)revealedTile.getGlobalBounds().width * j;
					yPos = (float)revealedTile.getGlobalBounds().height * i;
					unrevealedTile.setPosition(xPos, yPos);
					window.draw(unrevealedTile);
					if (isDebugMode == 1)
					{
						if (board.getHasMine(i, j) == 1)
						{
							mine.setPosition(xPos, yPos);
							window.draw(mine);
						}
					}
					// Flagged
					if (board.getHasFlag(i, j) == 1)
					{
						flag.setPosition(xPos, yPos);
						window.draw(flag);
					}

					if (board.CheckWin() == 1)
					{
						flag.setPosition(xPos, yPos);
						window.draw(flag);
					}
				}
				// Yes
				else if (board.getIsRevealed(i, j) == 1)
				{
					xPos = (float)revealedTile.getGlobalBounds().width * j;
					yPos = (float)revealedTile.getGlobalBounds().height * i;
					revealedTile.setPosition(xPos, yPos);
					window.draw(revealedTile);
					// mine
					if (board.getHasMine(i, j) == 1)
					{
						mine.setPosition(xPos, yPos);
						window.draw(mine);
					}
					// number
					else
					{
						int tileNum = board.getTileNumber(i, j);
						tileNumbers[tileNum].setPosition(xPos, yPos);
						window.draw(tileNumbers[tileNum]);
					}
				}
			}
		}
		xPos = 0;
		yPos = unrevealedTile.getGlobalBounds().height * 16.0f;
		//Mine Counter
		int firstDigit = abs(board.getMineCount()) % 10;
		int secondDigit = abs(board.getMineCount()) / 10;
		int thirdDigit = abs(board.getMineCount()) / 100;
		if (board.getMineCount() < 0)
		{
			digitNumbers[10].setPosition(xPos, yPos);
			window.draw(digitNumbers[10]);
		}
		else
		{
			digitNumbers[thirdDigit].setPosition(xPos, yPos);
			window.draw(digitNumbers[thirdDigit]);
		}
		xPos = (float)digitNumbers[firstDigit].getGlobalBounds().width;
		digitNumbers[secondDigit].setPosition(xPos, yPos);
		window.draw(digitNumbers[secondDigit]);
		xPos *= 2;
		digitNumbers[firstDigit].setPosition(xPos, yPos);
		window.draw(digitNumbers[firstDigit]);

		//Face
		xPos = ((unrevealedTile.getGlobalBounds().width * 25) / 2.0f);
		if (gameState != -1)
		{
			if (board.CheckWin())
			{
				face_win.setPosition(xPos, yPos);
				window.draw(face_win);
			}
			else
			{
				face_happy.setPosition(xPos, yPos);
				window.draw(face_happy);
			}
		}
		else
		{
			face_lose.setPosition(xPos, yPos);
			window.draw(face_lose);
		}

		xPos += debug.getGlobalBounds().width * 2;
		debug.setPosition(xPos, yPos);
		window.draw(debug);

		xPos += test_1.getGlobalBounds().width;
		test_1.setPosition(xPos, yPos);
		window.draw(test_1);

		xPos += test_2.getGlobalBounds().width;
		test_2.setPosition(xPos, yPos);
		window.draw(test_2);
		
		xPos += test_3.getGlobalBounds().width;
		test_3.setPosition(xPos, yPos);
		window.draw(test_3);

		window.display();
	}
	return 0;
}

