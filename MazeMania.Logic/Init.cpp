#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {

		//TO DO: Make this value an input
		int numMaps = 7;
		
		//Size the Map Container based on input and Set Map Properties
		m_Map->resize(numMaps);
		float x = 0.f, y = 0.f; // Map Position
		std::for_each(GetMapCollection().begin(), GetMapCollection().end(),[&x, &y](Map& m) { 
			m.setSize(sf::Vector2f(50.f, 50.f)),
			m.setFillColor(sf::Color::Red),
			m.setPosition( x, y),
			x += 50.f, y += 50;
		});

		return true;
	}
}