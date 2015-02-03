#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {

		//TO DO: Make this value an input
		int numLevels = 6;
		int numTiles = 10;
		m_LevelCollection->resize(numLevels); //Sizes container based on Number of Levels
		std::cout << "Size: " << m_LevelCollection->size() << std::endl; //Check how many levels
		
		//Look inside Level Collection and Setup each Level's Map. Keeps Map Centered and Relative to Screen
		sf::Vector2u screenSize = GetRenderWindow().getSize();

		std::for_each(GetLevelCollection().begin(), GetLevelCollection().end(), [&screenSize, &numTiles](Level& lvl) {
			
				lvl.GetMap().GetTileCollection().resize(numTiles * 2),
				lvl.GetMap().GetShape().setSize(sf::Vector2f(400.f, 400.f)),
				lvl.GetMap().GetShape().setFillColor(sf::Color::Black),
				lvl.GetMap().GetShape().setPosition(
				((screenSize.x / 2) - (lvl.GetMap().GetShape().getSize().x / 2)),
				(screenSize.y / 2) - (lvl.GetMap().GetShape().getSize().y / 2));
		});

		//Lay Down Tiles Across Map
		for (auto &lvl : GetLevelCollection()) {

			float tTileWidth = 0, tTileHeight = 0;

			for (auto &tile : lvl.GetMap().GetTileCollection()) {

				tile.GetShape().setSize(sf::Vector2f(20.f, 20.f));
				tile.GetShape().setFillColor(sf::Color::Red);
				tile.GetShape().setPosition(
					lvl.GetMap().GetShape().getPosition().x + tTileWidth, 
					lvl.GetMap().GetShape().getPosition().y + tTileHeight);

				tTileWidth += 20;
				tTileHeight += 20;
			}
		}

		return true;
	}
}