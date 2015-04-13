// James Kirsch - MazeMania Project
// Using the SFML library

#include <iostream>
#include <MazeMania.Logic.h>
#include <MazeMania.Data.h>

using namespace MazeManiaLogic;
using namespace MazeManiaData;

int GAME_ID = 1;
std::string GAME_NAME = "MazeMania - Authored by James Kirsch";

//Simply Create a Game, with Name, Id, Window Height, Window Width, and Bits Per Pixel.
void main(int argc, char *argv[]) {
	
	Game game(GAME_NAME, GAME_ID, 1024, 768, 32);
	std::cout << "Game Name: " << game.GetName() << std::endl; std::cout << "GameId: " << game.GetId() << std::endl;

	game.RunGame();
}

