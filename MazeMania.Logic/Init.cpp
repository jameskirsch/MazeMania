#include "Init.h"

//Current goal: implement depth first search, for maze generation, using a recursive backtracker

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {
		
		//TO DO: Make this value an input
		int numTiles = 10;
		int gridSize = numTiles;

		//Assigned to local references and make initializations
		auto& level = m_Session->GetLevel();
		auto& grid = m_Session->GetLevel().GetMap().GetGrid();
		auto& map = m_Session->GetLevel().GetMap();
		auto& mapRect = map.GetShape();
		auto& tiles = m_Session->GetLevel().GetMap().GetTiles();
		auto& layers = m_Session->GetLevel().GetMap().GetGrid().GetLayers();
		
		grid.SetLayers(4);

		//Set the Level, initialize tiles
		sf::Vector2u screenSize = GetRenderWindow().getSize();
		map.GetTiles().resize(numTiles * 2);

		mapRect.setSize(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));
		mapRect.setFillColor(sf::Color::Black);
		mapRect.setPosition(((screenSize.x / 2) - (mapRect.getSize().x / 2)),
			(screenSize.y / 2) - (mapRect.getSize().y / 2));
		
					
		//Populate the Grid with Cells, Per Layer
		float x = mapRect.getPosition().x;
		float y = mapRect.getPosition().y;

		for (auto& id : layers) {
			//TODO: Fix logic in this snippet
			while (x < mapRect.getSize().x * 1.5 && y < mapRect.getSize().y * 1.5) {
				
				Cell temp;
				temp.GetVertex().position.x = x;
				temp.GetVertex().position.y = y;
				temp.GetVertex().color.White;

				grid.GetVerts().append(temp.GetVertex());

				if (x > mapRect.getSize().x ) {
					x = mapRect.getPosition().x;
					y += 16;
				}

				x += 16;
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

		//Information about the loading.
		std::cout << "Map Size: " << "X: " << mapRect.getSize().x << " Y: " << mapRect.getSize().y << std::endl;
		std::cout << "Map Offset: " << "X: " << mapRect.getPosition().x << " Y: " << mapRect.getPosition().y << std::endl;
		std::cout << "Layers Size: " << layers.size() << std::endl;
		std::cout << "Grid Size - Cells in Grid ): " << grid.GetVerts().getVertexCount() << std::endl;
		
		return true;
	}
}