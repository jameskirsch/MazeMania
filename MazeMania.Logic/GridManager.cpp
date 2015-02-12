#include "GridManager.h"

namespace MazeManiaLogic {

	GridManager::GridManager() :
		m_Grid(new Grid())
	{
	}

	GridManager::~GridManager() {
		delete m_Grid;
	}

	//Get a Single Node by Id
	Node& GridManager::GetNode(int id) {

		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [&id](Node& n) { return n.GetId() == id; });
		return *node;
	}

	//Get a Single Node by Position If Node Does not Exist, create one as a boundary
	Node& GridManager::GetNode(float x, float y, int lyr) {

		Node *boundaryNode;
		auto& newNode = *boundaryNode;

		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [&x, &y, &lyr](Node& n) {
			return n.GetVertex().position.x == x && n.GetVertex().position.y && n.GetLayerId() == lyr; }); {
				if (&node != NULL){
					return *node;
				}
				else {
					newNode.SetIsOccupied(true);
					newNode.SetBoundaryNode(true);
					return newNode;
				}
			}
	}
	
	//Grab a collection of Neighbors around the targeted Node. North, East, South, and West Neighbors.
	//Recognizes Boundaries
	std::vector<Node>& GridManager::GetNodeNeighbors(float x, float y, int lyr, float tileSize) {

		std::vector<Node> neighborCollection;

		Node* northNode;
		Node* eastNode;
		Node* southNode;
		Node* westNode;
		Node boundaryNode;

		//Get Initial Node
		//auto& nd = GetNode(x, y, lyr);

		//Get Each North, East, South, West Neighbors of the Initial Node.
		for each (Node node in m_Grid->GetNodes()) {
			auto& northNode = GetNode(node.GetVertex().position.x, node.GetVertex().position.y + tileSize, lyr);
			auto& eastNode = GetNode(node.GetVertex().position.x + tileSize, node.GetVertex().position.y, lyr);
			auto& southNode = GetNode(node.GetVertex().position.x, node.GetVertex().position.y - tileSize, lyr);
			auto& westNode = GetNode(node.GetVertex().position.x - tileSize, node.GetVertex().position.y, lyr);

			neighborCollection.push_back(northNode);
			neighborCollection.push_back(eastNode);
			neighborCollection.push_back(southNode);
			neighborCollection.push_back(westNode);
		}
	
		return neighborCollection;
	}
}
