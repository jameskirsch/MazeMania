// James Kirsch - MazeMania Project

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

//Main will run the Game Loop
void main(){

	//Testing a Commit
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML window");
	

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
}

