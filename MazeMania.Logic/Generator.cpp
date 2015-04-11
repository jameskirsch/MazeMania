#include "Generator.h"

namespace MazeManiaLogic {

	
	Generator::Generator(Session& session, GridManager& gridMgr) :
		m_Session(new Session()),
		m_GridMgr(new GridManager()),
		m_CurrentNode(nullptr)
	{ 	
		m_Session = &session;
		m_GridMgr = &gridMgr;
		srand(time(0));
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
			m_CurrentNode = &m_GridMgr->GetNodeByLocation(nodes, map.GetShape().getPosition().x , map.GetShape().getPosition().y, 1);
		}

		m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Black);
		
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

		auto endNode = m_GridMgr->GetNodeByLocation(nodes, map.GetShape().getPosition().x + map.GetShape().getSize().x - tileSize, map.GetShape().getPosition().y, 1);
		endNode.GetTile().GetShape().setFillColor(sf::Color::Red);
		
		if (m_CurrentNode->GetId() != endNode.GetId() && m_CurrentNode->GetLayerId() == 1) {

			auto x = m_CurrentNode->GetVertex().position.x;
			auto y = m_CurrentNode->GetVertex().position.y;
			auto lyr = m_CurrentNode->GetLayerId();

			auto& node = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr](Node& n) { return 
				n.GetVertex().position.x == x && 
				n.GetVertex().position.y == y &&
				n.GetLayerId() == lyr; 
			});

			//Current Node's Neighbors
			//auto& neighbors = this->m_GridMgr->GetNodeNeighbors(nodes, *m_CurrentNode, tileSize, 1);
			//std::vector<Node> *tNodes = new std::vector<Node>();

			auto& northNode = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr, tileSize, &node](Node& n) { return
				n.GetVertex().position.x == node->GetVertex().position.x &&
				n.GetVertex().position.y == node->GetVertex().position.y - tileSize &&
				n.GetLayerId() == node->GetLayerId();
			});

			auto& eastNode = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr, tileSize, &node](Node& n) { return
				n.GetVertex().position.x == node->GetVertex().position.x + tileSize &&
				n.GetVertex().position.y == y &&
				n.GetLayerId() == node->GetLayerId();
			});

			auto& southNode = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr, tileSize, &node](Node& n) { return
				n.GetVertex().position.x == x  &&
				n.GetVertex().position.y == node->GetVertex().position.y + tileSize &&
				n.GetLayerId() == node->GetLayerId();
			});

			auto& westNode = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr, tileSize, &node](Node& n) { return
				n.GetVertex().position.x == node->GetVertex().position.x - tileSize  &&
				n.GetVertex().position.y == y &&
				n.GetLayerId() == node->GetLayerId();
			});

			

			//Directions ( 1 - 4 )
			
			auto randDir = rand() % 4;
			//Directions direction;

			/*switch (randDir) {
			case 1: direction = North; break;
			case 2: direction = East; break;
			case 3: direction = South; break;
			case 4: direction = West; break;
			};*/

			//auto status = northNode->GetBoundaryStatus();
			if (m_CurrentNode->GetVisitedStatus() == false) {

				switch (randDir) {

				case 0:

					if (northNode->GetBoundaryStatus() == false && northNode->GetVisitedStatus() == false) {
						auto northN = new Node(*northNode);
						m_CurrentNode->SetVisited(true);
						m_CurrentNode = northN;
						m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					}

					break;
				case 1:
					if (eastNode->GetBoundaryStatus() == false && eastNode->GetVisitedStatus() == false) {
						auto eastN = new Node(*eastNode);
						m_CurrentNode->SetVisited(true);
						m_CurrentNode = eastN;
						m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					}
					break;
				case 2:
					if (southNode->GetBoundaryStatus() == false && southNode->GetVisitedStatus() == false) {
						auto southN = new Node(*southNode);
						m_CurrentNode->SetVisited(true);
						m_CurrentNode = southN;
						m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					}

					break;
				case 3:
					if (westNode->GetBoundaryStatus() == false && westNode->GetVisitedStatus() == false) {
						auto westN = new Node(*westNode);
						m_CurrentNode->SetVisited(true);
						m_CurrentNode = westN;
						m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					}
					break;

				default:
					break;
				}
			}
		}		
	}
}
