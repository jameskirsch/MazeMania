#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {

		//TO DO: Make this value an input
		int numLevels = 6;
		m_LevelCollection->resize(numLevels); //Sizes container based on Number of Levels
		std::cout << "Size: " << m_LevelCollection->size() << std::endl; //Check how many levels
		
		//Look inside Level Collection and Setup each Level's Map. Keeps Map Centered and Relative to Screen
		sf::Vector2u screenSize = GetRenderWindow().getSize();

		std::for_each(GetLevelCollection().begin(), GetLevelCollection().end(), [&screenSize](Level& lvl) {
			lvl.GetMap().setSize(sf::Vector2f(400.f, 400.f)),
				lvl.GetMap().setFillColor(sf::Color::Black),
				lvl.GetMap().setPosition(
				((screenSize.x / 2) - (lvl.GetMap().getSize().x / 2)),
				(screenSize.y / 2) - (lvl.GetMap().getSize().y / 2));
		});

		return true;
	}
}