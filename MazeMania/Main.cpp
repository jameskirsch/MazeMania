// James Kirsch - MazeMania Project
// Using the SFLM library

#include <iostream>
#include <MazeMania.Logic.h>
#include <MazeMania.Data.h>

using namespace MazeManiaLogic;
using namespace MazeManiaData;

int GAME_ID = 1;
int SCREEN_WIDTH = 200;
int SCREEN_HEIGHT = 200;
std::string GAME_NAME = "MazeMania";

//Simply Create a Game, with Name, Id, Window Height, Window Width, and Bits Per Pixel.
void main(int argc, char *argv[]) {
	
	Game game(GAME_NAME, GAME_ID, 800, 600, 32);
	std::cout << "GameId: " << game.GetId() << std::endl << "Game Name: " << game.GetName() << std::endl;

	game.RunGame();
}

