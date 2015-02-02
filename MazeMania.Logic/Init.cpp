#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {

		//TO DO: Make this value an input
		int numMaps = 1;
		
		//Size the Map Container based on input and Set Map Properties
		this->m_LevelCollection->resize(numMaps);
		float x = 0.f, y = 0.f; // Map Position
		std::for_each(GetLevelCollection().begin(), GetLevelCollection().end(),[&x, &y](Level& lvl) { 
			lvl.GetMap().setSize(sf::Vector2f(300.f, 300.f)),
			lvl.GetMap().setFillColor(sf::Color::Black),
			lvl.GetMap().setPosition( x, y),
			x += 50.f, y += 50;
		});

		return true;
	}
}