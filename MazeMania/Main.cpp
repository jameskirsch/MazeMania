// James Kirsch - MazeMania Project
// This represents a somewhat generic 2D game engine, used to create a Maze Game
// Using the SFLM library

#include <iostream>

//SFML Libs
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//DLLs
#include <MazeMania.Data.h>
#include <MazeMania.Object.h>
#include <MazeMania.Logic.h>

using namespace MazeManiaData;
using namespace MazeManiaObject;
using namespace MazeManiaLogic;

const int GAME_ID = 1;
int SCREEN_WIDTH = 200;
int SCREEN_HEIGHT = 200;
const std::string GAME_NAME = "MazeMania";

//Main will run the Game Loop
void main() {

	Game game(GAME_NAME, GAME_ID, 800, 600, 32);
	std::cout << "GameId: " << game.GetId() << " " << "Game Name " << game.GetName() << std::endl;

	Map map(1, 10, 50);
	sf::Vector2f size = map.getSize();
	std::cout << "Size of Map X: " << size.x << "Size of Map Y: " << size.y << std::endl;

	game.RunGame(true);	
}

