#include "Init.h"

//Current goal: implement depth first search, for maze generation, using a recursive backtracker

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {
		
		//TO DO: Make these values inputs
		int layerSize = 8;
		float tileSize = 32;
		int numTiles = 0;
		
		//Assigned to local references and make initializations
		GridManager gridMgr;
		auto& level = m_Session->GetLevel();
		auto& grid = m_Session->GetLevel().GetMap().GetGrid();
		auto& map = m_Session->GetLevel().GetMap();
		auto& mapRect = map.GetShape();
		auto& tiles = m_Session->GetLevel().GetMap().GetTiles();
		auto& layers = m_Session->GetLevel().GetMap().GetGrid().GetLayers();
		auto& verts = m_Session->GetLevel().GetMap().GetGrid().GetVerts();
		auto& nodes = grid.GetNodes();
		
		gridMgr.SetGrid(grid);	
		grid.SetLayers(layerSize);

		//Set the Level, initialize tiles
		sf::Vector2u screenSize = GetRenderWindow().getSize();

		mapRect.setSize(sf::Vector2f( screenSize.x / 2, screenSize.y / 2));
		mapRect.setFillColor(sf::Color::Black);
		mapRect.setPosition(((screenSize.x / 2) - (mapRect.getSize().x / 2)),
			(screenSize.y / 2) - (mapRect.getSize().y / 2));
							
		//Populate the Grid with Cells, Per Layer. TODO: Figure out why 1.5 is needed, add ID.
		int id = 1;
		for (auto& lyr : layers) {

			float x = mapRect.getPosition().x;
			float y = mapRect.getPosition().y;

			//Check if the current position for each vertex is in bounds, and create a new one until map is full.
			while (x < mapRect.getSize().x *1.5 && y < mapRect.getSize().y * 1.5) {
				
				Node tempNode;
				tempNode.SetId(id);
				tempNode.SetLayerId(lyr);
				tempNode.GetVertex().position.x = x;
				tempNode.GetVertex().position.y = y;
				tempNode.GetVertex().color.White;

				grid.GetVerts().append(tempNode.GetVertex());
				grid.GetNodes().push_back(tempNode);

				x += tileSize;
				id += 1;

				if (x >= mapRect.getSize().x * 1.5 ) {
					x = mapRect.getPosition().x;
					y += tileSize;					
				}			
			}
		}

		//Lay Down Tiles Across Level
		float tTileWidth = 0, tTileHeight = 0;

		map.GetTiles().resize(numTiles * 2);
		

		for (auto &tile : tiles) {

			tile.GetShape().setSize(sf::Vector2f(tileSize,tileSize));
			tile.GetShape().setFillColor(sf::Color::Red);
			tile.GetShape().setPosition(mapRect.getPosition().x + tTileWidth, mapRect.getPosition().y + tTileHeight);
			tTileWidth += tile.GetShape().getSize().x;
		}

		//Information about the loading.
		std::cout << "Map Size: " << "X: " << mapRect.getSize().x << " Y: " << mapRect.getSize().y << std::endl;
		std::cout << "Tile Size: " << tileSize << std::endl;
		std::cout << "Map Position: " << "X: " << mapRect.getPosition().x << " Y: " << mapRect.getPosition().y << std::endl;
		std::cout << "Layers Size: " << layers.size() << std::endl;
		std::cout << "Total Vertices: " << grid.GetVerts().getVertexCount() << std::endl;
		std::cout << "Vertices Per Layer: " << grid.GetVerts().getVertexCount() / layers.size() << std::endl;
		std::cout << "Total Tiles: " << tiles.size() << std::endl;

		auto& n = gridMgr.GetNode(map.GetShape().getPosition().x, map.GetShape().getPosition().y, 5);
		std::cout << "Node Location: " << "X " << n.GetVertex().position.x << " Y: " << n.GetVertex().position.y << std::endl;

		auto& nn = gridMgr.GetNodeNeighbors(0,0,1,tileSize);

		for each (Node item in nn) {
			std::cout << "Node Neighbor Id: " << item.GetId() << std::endl;
			std::cout << "Node Neighbor Position: XY " << item.GetVertex().position.x << " " << item.GetVertex().position.y << std::endl;
			std::cout << "Node Neighbor is Occupied " << item.GetIsOccupied() << std::endl;
			std::cout << "Node Neighbor is a Boundary" << item.GetBoundaryStatus() << std::endl;
		}
		
		return true;
	}
}