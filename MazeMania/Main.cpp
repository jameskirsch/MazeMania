#include <iostream>
#include <..\MazeMania.Object\MazeMania.Object.h>

//SFML Libs
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

//Project Libs

#include "MazeMania.Data.h"
#include "MazeMania.Object.h"
#include "MazeMania.Logic.h"

using namespace std;
using namespace MazeManiaData;
//using namespace MazeManiaObject;
using namespace MazeManiaLogic;

// MazeMania by James Kirsch
void main()
{
	///*int x = 6;
	//Entity myEntityOne;
	//myEntityOne.SetId(x);*/
	
	Entity myEnt;
	myEnt.SetId(4);

	int response;
	std::cout << "Test" << std::endl;
	std::cout << "Entity Id" << myEnt.GetId() << std::endl;
	std::cin >> response; std::cout << std::endl;
}

