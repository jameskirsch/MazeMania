#include "Init.h"

//Current goal: implement depth first search, for maze generation, using a recursive backtracker

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {
		
		//TO DO: Make these values inputs
		int layerSize = 3;
		int numTiles = 10;
		
		//Assigned to local references and make initializations
		auto& level = m_Session->GetLevel();
		auto& grid = m_Session->GetLevel().GetMap().GetGrid();
		auto& map = m_Session->GetLevel().GetMap();
		auto& mapRect = map.GetShape();
		auto& tiles = m_Session->GetLevel().GetMap().GetTiles();
		auto& layers = m_Session->GetLevel().GetMap().GetGrid().GetLayers();
		
		grid.SetLayers(layerSize);

		//Set the Level, initialize tiles
		sf::Vector2u screenSize = GetRenderWindow().getSize();
		map.GetTiles().resize(numTiles * 2);

		mapRect.setSize(sf::Vector2f(screenSize.x / 2 , screenSize.y / 2));
		mapRect.setFillColor(sf::Color::Black);
		mapRect.setPosition(((screenSize.x / 2) - (mapRect.getSize().x / 2)),
			(screenSize.y / 2) - (mapRect.getSize().y / 2));
							
		//Populate the Grid with Cells, Per Layer. TODO: Figure out why 1.5 is needed 
		for (auto& i : layers) {

			float x = mapRect.getPosition().x;
			float y = mapRect.getPosition().y;

			//Check if the current position for each vertex is in bounds, and create a new one until map is full.
			while (x < mapRect.getSize().x * 1.5 && y < mapRect.getSize().y * 1.5) {
				
				Cell temp;
				temp.GetVertex().position.x = x;
				temp.GetVertex().position.y = y;
				temp.GetVertex().color.White;

				grid.GetVerts().append(temp.GetVertex());

				x += 16;

				if (x >= mapRect.getSize().x * 1.5 ) {
					x = mapRect.getPosition().x;
					y += 16;					
				}			
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
		std::cout << "Map Position: " << "X: " << mapRect.getPosition().x << " Y: " << mapRect.getPosition().y << std::endl;
		std::cout << "Layers Size: " << layers.size() << std::endl;
		std::cout << "Total Vertices: " << grid.GetVerts().getVertexCount() << std::endl;
		std::cout << "Vertices Per Layer: " << grid.GetVerts().getVertexCount() / layers.size() << std::endl;
		
		return true;
	}
}