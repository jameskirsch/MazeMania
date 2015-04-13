#include "Generator.h"

namespace MazeManiaLogic {


	Generator::Generator(Session& session, GridManager& gridMgr) :
		m_Session(new Session()),
		m_GridMgr(new GridManager()),
		m_CurrentNode(nullptr)
	{
		m_Session = &session;
		m_GridMgr = &gridMgr;
		srand(time(0)); //Seed RNG
	}

	//Will use the Grid to Generate a Maze
	void Generator::GenerateMaze(float tileSize) {

		auto& map = m_Session->GetLevel().GetMap();
		auto& grid = m_Session->GetLevel().GetMap().GetGrid();
		auto& nodes = m_Session->GetLevel().GetMap().GetGrid().GetNodes();
		auto& mapRect = map.GetShape();
		auto& tiles = map.GetTiles();

		//Starting Node
		if (m_CurrentNode == nullptr) {
			m_CurrentNode = &m_GridMgr->GetNodeByLocation(nodes, map.GetShape().getPosition().x + (tileSize), map.GetShape().getPosition().y + (tileSize), 1);
			std::make_unique<Node>(static_cast<Node>(*m_CurrentNode));
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
			std::cout << "Number of Tiles: " << tiles.size() << std::endl;
		}

		//Ending Node - Will complete when reached ( currently )
		auto endNode = m_GridMgr->GetNodeByLocation(nodes, map.GetShape().getPosition().x + map.GetShape().getSize().x - (tileSize * 2),
			map.GetShape().getPosition().y + tileSize, 1
		);

		endNode.GetTile().GetShape().setFillColor(sf::Color::Red);

		//Conditions for the Generation to Complete
		if (m_CurrentNode->GetId() != endNode.GetId() && m_CurrentNode->GetLayerId() == 1) {

			//Set Starting Node to Visited
			if (m_CurrentNode->GetVertex().position.x == map.GetShape().getPosition().x + (tileSize) &&
				m_CurrentNode->GetVertex().position.y == map.GetShape().getPosition().y + (tileSize)) {
				m_CurrentNode->SetVisited(true);
			}

			//Update Tile Color for Path of Maze
			m_CurrentNode->GetTile().GetShape().setFillColor(sf::Color::Black);

			auto x = m_CurrentNode->GetVertex().position.x;
			auto y = m_CurrentNode->GetVertex().position.y;
			auto lyr = m_CurrentNode->GetLayerId();

			//Get the Current Node from the collection
			auto& node = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr](Node& n) { return
				n.GetVertex().position.x == x &&
				n.GetVertex().position.y == y &&
				n.GetLayerId() == lyr;
			});

			//Neighboring nodes relative to the Current Node were looking at.
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

			//Handles special cases, such as finding a visited/unvisited path 2 nodes ahead
			auto& northOfNorth = std::find_if(nodes.begin(), nodes.end(), [&northNode, tileSize](Node& n) { return
				n.GetVertex().position.x == northNode->GetVertex().position.x &&
				n.GetVertex().position.y == northNode->GetVertex().position.y - tileSize &&
				n.GetLayerId() == northNode->GetLayerId();
			});

			auto& eastOfEast = std::find_if(nodes.begin(), nodes.end(), [&eastNode, tileSize](Node& n) { return
				n.GetVertex().position.x == eastNode->GetVertex().position.x + tileSize &&
				n.GetVertex().position.y == eastNode->GetVertex().position.y  &&
				n.GetLayerId() == eastNode->GetLayerId();
			});

			auto& southOfSouth = std::find_if(nodes.begin(), nodes.end(), [&southNode, tileSize](Node& n) { return
				n.GetVertex().position.x == southNode->GetVertex().position.x &&
				n.GetVertex().position.y == southNode->GetVertex().position.y + tileSize &&
				n.GetLayerId() == southNode->GetLayerId();
			});

			auto& westOfWest = std::find_if(nodes.begin(), nodes.end(), [&westNode, tileSize](Node& n) { return
				n.GetVertex().position.x == westNode->GetVertex().position.x - tileSize &&
				n.GetVertex().position.y == westNode->GetVertex().position.y &&
				n.GetLayerId() == westNode->GetLayerId();
			});

			//Pick a Random Direction of North/East/South/West, and Assign the Current Node to that Node, Marks it as Visited
			//Directions ( 0 - 3 )
			auto randDir = rand() % 4;

			switch (randDir) {
			case 0:
				if (northNode->GetBoundaryStatus() == false && northNode->GetVisitedStatus() == false && northOfNorth->GetBoundaryStatus() == false
					&& northOfNorth->GetVisitedStatus() == false) {
					northNode->SetVisited(true);
					northNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					auto northN = new Node(*northNode);
					std::make_unique<Node>(static_cast<Node>(*northN));
					m_CurrentNode = northN;

				} break;
			case 1:
				if (eastNode->GetBoundaryStatus() == false && eastNode->GetVisitedStatus() == false && eastOfEast->GetBoundaryStatus() == false
					&& eastOfEast->GetVisitedStatus() == false) {
					eastNode->SetVisited(true);
					eastNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					auto eastN = new Node(*eastNode);
					std::make_unique<Node>(static_cast<Node>(*eastN));
					m_CurrentNode = eastN;
				}
				break;
			case 2:
				if (southNode->GetBoundaryStatus() == false && southNode->GetVisitedStatus() == false && southOfSouth->GetBoundaryStatus() == false
					&& southOfSouth->GetVisitedStatus() == false) {
					southNode->SetVisited(true);
					southNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					auto southN = new Node(*southNode);
					std::make_unique<Node>(static_cast<Node>(*southN));
					m_CurrentNode = southN;
				}

				break;
			case 3:
				if (westNode->GetBoundaryStatus() == false && westNode->GetVisitedStatus() == false && westOfWest->GetBoundaryStatus() == false
					&& westOfWest->GetVisitedStatus() == false) {
					westNode->SetVisited(true);
					westNode->GetTile().GetShape().setFillColor(sf::Color::Red);
					auto westN = new Node(*westNode);
					std::make_unique<Node>(static_cast<Node>(*westN));
					m_CurrentNode = westN;
				}
				break;

			default:
				break;
			}
		}
	}

	void Generator::m_Recurse(Node& node) {
		//to do: Implement
	}

}
