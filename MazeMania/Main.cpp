// James Kirsch - MazeMania Project
// This represents a somewhat generic 2D game engine, used to create a Maze Game
// Using the SFLM library

#include <iostream>
#include <MazeMania.Logic.h>

using namespace MazeManiaLogic;

int GAME_ID = 1;
int SCREEN_WIDTH = 200;
int SCREEN_HEIGHT = 200;
std::string GAME_NAME = "MazeMania";

//Simply Create a Game, with Name, Id, Window Height, Window Width, and Bits Per Pixel.
void main() {

	Game game(GAME_NAME, GAME_ID, 800, 600, 32);
	std::cout << "GameId: " << game.GetId() << std::endl << "Game Name: " << game.GetName() << std::endl;

	game.RunGame(true);
}

