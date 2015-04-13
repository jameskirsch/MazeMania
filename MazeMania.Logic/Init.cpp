#include "Init.h"

//Current goal: implement depth first search, for maze generation, using a recursive backtracker

namespace MazeManiaLogic {

	//Initialize all Game Features
	//Methods this big are terrible practice
	bool Game::Init() {
		
		//TO DO: Make these values inputs
		int layerSize = 1;
		float tileSize = 8;
		int numTiles = 4;
		
		//Assigned to local references and make initializations
		auto& gridMgr = m_GridMgr;
		auto& level = m_Session->GetLevel();
		auto& grid = m_Session->GetLevel().GetMap().GetGrid();
		auto& map = m_Session->GetLevel().GetMap();
		auto& mapRect = map.GetShape();
		auto& tiles = m_Session->GetLevel().GetMap().GetTiles();
		auto& layers = m_Session->GetLevel().GetMap().GetGrid().GetLayers();
		auto& verts = m_Session->GetLevel().GetMap().GetGrid().GetVerts();
		auto& nodes = grid.GetNodes();
		
		gridMgr->SetGrid(grid);
		gridMgr->SetTileSize(tileSize);
		grid.SetLayers(layerSize);
		
		//Set the Level, initialize tiles
		sf::Vector2u screenSize = GetRenderWindow().getSize();

		mapRect.setSize(sf::Vector2f( screenSize.x / 2.f, screenSize.y / 2.f));
		mapRect.setFillColor(sf::Color::Black);
		mapRect.setPosition(((screenSize.x / 2) - (mapRect.getSize().x / 2)),
			(screenSize.y / 2) - (mapRect.getSize().y / 2));
							
		//Populate the Grid with Cells, Per Layer. TODO: Figure out why 1.5 is needed, add ID.
		int id = 1;
		nodes.reserve((map.GetShape().getSize().x / tileSize * layerSize));
		verts.resize((map.GetShape().getSize().x / tileSize)  * layerSize);
		
		for (auto& lyr : layers) {

			//Coordinates
			float x = mapRect.getPosition().x;
			float y = mapRect.getPosition().y;

			//Check if the current position for each vertex is in bounds, and create a new one until map is full.
			while (x < mapRect.getSize().x *1.5 && y < mapRect.getSize().y * 1.5) {
				
				//Create Boundary Nodes on North
				if (y == mapRect.getPosition().y) {
					Node* tempNode = new Node();
					tempNode->SetId(id);
					tempNode->SetLayerId(lyr);
					tempNode->SetBoundaryNode(true);
					tempNode->GetVertex().position.x = x;
					tempNode->GetVertex().position.y = y - tileSize;
					tempNode->GetVertex().color = sf::Color::Red;
					grid.GetNodes().push_back(*tempNode);
					grid.GetVerts().append(tempNode->GetVertex());
					verts.append(tempNode->GetVertex());
					id += 1;			
				}

				//Create Boundary Nodes on West
				if (x == mapRect.getPosition().x) {
					Node* tempNode = new Node();
					tempNode->SetId(id);
					tempNode->SetLayerId(lyr);
					tempNode->SetBoundaryNode(true);
					tempNode->GetVertex().position.x = x - tileSize;
					tempNode->GetVertex().position.y = y;
					tempNode->GetVertex().color = sf::Color::Red;
					grid.GetNodes().push_back(*tempNode);
					grid.GetVerts().append(tempNode->GetVertex());
					verts.append(tempNode->GetVertex());
					id += 1;
				}

				//Create Boundary Nodes East
				if (x == (mapRect.getSize().x * 1.5) - tileSize) {
					Node* tempNode = new Node();
					tempNode->SetId(id);
					tempNode->SetLayerId(lyr);
					tempNode->SetBoundaryNode(true);
					tempNode->GetVertex().position.x = x + tileSize;
					tempNode->GetVertex().position.y = y;
					tempNode->GetVertex().color = sf::Color::Red;
					grid.GetNodes().push_back(*tempNode);
					grid.GetVerts().append(tempNode->GetVertex());
					verts.append(tempNode->GetVertex());
					id += 1;
				}

				//Create Boundary Nodes South
				if (y == (mapRect.getSize().y * 1.5) - tileSize) {
					Node* tempNode = new Node();
					tempNode->SetId(id);
					tempNode->SetLayerId(lyr);
					tempNode->SetBoundaryNode(true);
					tempNode->GetVertex().position.x = x;
					tempNode->GetVertex().position.y = y + tileSize;
					tempNode->GetVertex().color = sf::Color::Red;
					grid.GetNodes().push_back(*tempNode);
					grid.GetVerts().append(tempNode->GetVertex());
					verts.append(tempNode->GetVertex());
					id += 1;
				}

				//Create a Node that is unoccupied within the map
				Node* tempNode = new Node();
				tempNode->SetId(id);
				tempNode->SetLayerId(lyr);
				tempNode->GetVertex().position.x = x;
				tempNode->GetVertex().position.y = y;
				tempNode->GetVertex().color = sf::Color::White;
				grid.GetNodes().push_back(*tempNode);
				grid.GetVerts().append(tempNode->GetVertex());
				verts.append(tempNode->GetVertex());
				
				x += tileSize;
				id += 1;

				if (x >= mapRect.getSize().x * 1.5 ) {
					x = mapRect.getPosition().x;
					y += tileSize;					
				}			
			}
		}

		//Information about the loading.
		std::cout << "Map Size: " << "X: " << mapRect.getSize().x << " Y: " << mapRect.getSize().y << std::endl;
		std::cout << "Tile Size: " << tileSize << std::endl;
		std::cout << "Map Position: " << "X: " << mapRect.getPosition().x << " Y: " << mapRect.getPosition().y << std::endl;
		std::cout << "Layers Size: " << layers.size() << std::endl;
		std::cout << "Total Vertices: " << grid.GetVerts().getVertexCount() << std::endl;
		std::cout << "Vertices Per Layer: " << grid.GetVerts().getVertexCount() / layers.size() << std::endl;
		
		return true;
	}
}