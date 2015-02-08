#include "Init.h"

//Current goal: implement depth first search, for maze generation, using a recursive backtracker

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {
		

		//TO DO: Make this value an input
		int numTiles = 10;

		//Psuedo

		//Dice up the board with viable offset points.
		//Store an array of offsets, with a flag condition

		m_Session->GetLevel().GetMap().GetGrid().SetLayers(3);
		auto gridPtr = m_Session->GetLevel().GetMap().GetGrid();
		std::cout << "Grid Size: " << gridPtr.GetLayers().size() << std::endl;

		// plot the points on the current map level

	

	


		
		//Randomly select a 16x16 tile on map, mark it as visited
		// So Each tile needs to remember the location it is placed.
		// Make a tile that randomly selects an offset divisible by 16x16, within boundaries
		// Mark this offset on the levels map as a taken spot. ( Taken by what layer level ? 1, 2, or 3 )

		//While all cells in layer 2 are empty
		// Make an inital cell location
		// Call generate Maze
			
		//Set the Level, initialize tiles
		sf::Vector2u screenSize = GetRenderWindow().getSize();
		m_Session->GetLevel().GetMap().GetTiles().resize(numTiles * 2);
		m_Session->GetLevel().GetMap().GetShape().setSize(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));
		m_Session->GetLevel().GetMap().GetShape().setFillColor(sf::Color::Black);
		m_Session->GetLevel().GetMap().GetShape().setPosition
		(((screenSize.x / 2) - (m_Session->GetLevel().GetMap().GetShape().getSize().x / 2)),
		(screenSize.y / 2) - (m_Session->GetLevel().GetMap().GetShape().getSize().y / 2));




		//Make a Temp Vector. ( testing for laying down vectors into the map, and grid layers
		sf::Vector2f tempVector;
		tempVector.x = m_Session->GetLevel().GetMap().GetShape().getPosition().x;
		tempVector.y = m_Session->GetLevel().GetMap().GetShape().getPosition().y;

		while (tempVector.x < m_Session->GetLevel().GetMap().GetShape().getSize().x 
			&& tempVector.y < m_Session->GetLevel().GetMap().GetShape().getSize().y) {

			tempVector.x += 16;

			std::cout << "Temp Vec X: " << tempVector.x << std::endl;

			if (tempVector.x > m_Session->GetLevel().GetMap().GetShape().getSize().x) {
				tempVector.y -= 16;
				std::cout << "Temp Vec Y: " << tempVector.y << std::endl;
				//tempVector.x = m_Session->GetLevel().GetMap().GetShape().getPosition().x;
			}
		}


		//Lay Down Tiles Across Level
		float tTileWidth = 0, tTileHeight = 0;

		for (auto &tile : m_Session->GetLevel().GetMap().GetTiles()) {

			tile.GetShape().setSize(sf::Vector2f(16.0f, 16.0f));
			tile.GetShape().setFillColor(sf::Color::Red);
			tile.GetShape().setPosition(
				m_Session->GetLevel().GetMap().GetShape().getPosition().x + tTileWidth,
				m_Session->GetLevel().GetMap().GetShape().getPosition().y + tTileHeight);

			tTileWidth += tile.GetShape().getSize().x;
		}
		
		return true;
	}
}