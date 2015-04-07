#include "Generator.h"

namespace MazeManiaLogic {

	
	Generator::Generator(Session& session, GridManager& gridMgr) :
		m_Session(new Session()),
		m_GridMgr(new GridManager()),
		m_CurrentNode(nullptr)
	{ 	
		m_Session = &session;
		m_GridMgr = &gridMgr;
	}

	//Will use the Grid to Generate a Maze
	void Generator::GenerateMaze(float tileSize) {

		//Directions ( these map to the Index of the Neighbors collection )
		enum Directions {
			North = 0,
			East = 1,
			South = 2,
			West = 3
		};

		auto& map = m_Session->GetLevel().GetMap();
		auto& grid = m_Session->GetLevel().GetMap().GetGrid();
		auto& nodes = m_Session->GetLevel().GetMap().GetGrid().GetNodes();
		auto& mapRect = map.GetShape();
		auto& tiles = map.GetTiles();

		// Maze Algorithm ( create tiles on first layer of grid )

		if (m_CurrentNode == nullptr) {
			m_CurrentNode = new Node();
			m_CurrentNode = &m_GridMgr->GetNodeByLocation(nodes, 256, 192, 1);
		}
		
		if (tiles.size() == 0) {
			for (auto& node : nodes) {

				if (node.GetIsOccupied() == false && node.GetBoundaryStatus() == false && node.GetLayerId() == 1) {
					std::unique_ptr<Tile> tile(new Tile);
					tile->GetShape().setSize(sf::Vector2f(tileSize, tileSize));
					tile->GetShape().setFillColor(sf::Color::Blue);
					tile->GetShape().setPosition(node.GetVertex().position.x, node.GetVertex().position.y);
					map.GetTiles().push_back(*tile);
					node.SetTile(*tile);
					node.SetIsOccupied(true);
				}
			}
		}

		auto& endNode = m_GridMgr->GetNodeByLocation(nodes, 256, 192 + (tileSize * 6), 1);
		
		if (m_CurrentNode->GetId() != endNode.GetId() && m_CurrentNode->GetLayerId() == 1) {

			//Current Node's Neighbors
			auto& neighbors = m_GridMgr->GetNodeNeighbors(nodes, *m_CurrentNode, tileSize, 1);

			//Directions ( 1 - 4 )
			auto randDir = rand() % 4;
			Directions direction;

			switch (randDir) {
			case 1: direction = North; break;
			case 2: direction = East; break;
			case 3: direction = South; break;
			case 4: direction = West; break;
			};

			switch (direction) {

			case North:
				if (neighbors[direction].GetBoundaryStatus() == false && neighbors[direction].GetVisitedStatus() == false) {
					m_CurrentNode->SetVisited(true);
					*m_CurrentNode = neighbors[direction];
					m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Black);
				}

				break;
			case East:
				if (neighbors[direction].GetBoundaryStatus() == false && neighbors[direction].GetVisitedStatus() == false) {
					m_CurrentNode->SetVisited(true);
					*m_CurrentNode = neighbors[direction];
					m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Black);
				}
				break;
			case South:
				if (neighbors[direction].GetBoundaryStatus() == false && neighbors[direction].GetVisitedStatus() == false) {
					m_CurrentNode->SetVisited(true);
					*m_CurrentNode = neighbors[direction];
					m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Black);
				}

				break;
			case West:
				if (neighbors[direction].GetBoundaryStatus() == false && neighbors[direction].GetVisitedStatus() == false) {
					m_CurrentNode->SetVisited(true);
					*m_CurrentNode = neighbors[direction];
					m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Black);
				}
				break;

			default:
				break;
			}

			//neighbors.clear();

		}		
	}
}
