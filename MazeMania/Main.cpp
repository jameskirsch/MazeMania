// James Kirsch - MazeMania Project

#include <iostream>

//SFML Libs
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

//DLLs
#include <MazeMania.Data.h>
#include <MazeMania.Object.h>
#include <MazeMania.Logic.h>

//using namespace MazeManiaData;
using namespace MazeManiaObject;
//using namespace MazeManiaLogic;


void main()
{	
	Entity myEnt;
	myEnt.SetId(4);

	int response;
	std::cout << "Test" << std::endl;
	std::cout << "Entity Id" << myEnt.GetId() << std::endl;
	std::cin >> response; std::cout << std::endl;
}

