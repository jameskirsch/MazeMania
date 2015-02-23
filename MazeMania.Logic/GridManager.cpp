#include "GridManager.h"

namespace MazeManiaLogic {

	GridManager::GridManager() :
		m_Grid(new Grid)
	{		

	}

	GridManager::~GridManager() {
		//delete m_Grid;
	}

	//Get a Single Node by Id
	Node& GridManager::GetNodeId(int id) {

		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [&id](Node& n) {
			return n.GetId() == id; });
			return *node;
	}

	//Get a Single Node by Position
	Node& GridManager::GetNodeByLocation(float x, float y, int lyr) {

		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end() + 1, [&x, &y, &lyr](Node& n) {
			return n.GetVertex().position.x == x && n.GetVertex().position.y && n.GetLayerId() == lyr; });			
			return *node;
	}

	//Create Boundaries on Grid.
	
	//Grab a collection of Neighbors around the targeted Node. North, East, South, and West Neighbors.
	//Recognizes Boundaries
	//std::vector<std::shared_ptr<Node>>& GridManager::GetNodeNeighbors(float x, float y, int lyr, float tileSize) {

	//	std::unique_ptr<std::vector<std::shared_ptr<Node>>> neighborCollection;

	//	//Get Initial Node
	//	//auto& nd = GetNode(x, y, lyr);

	//	//Get Each North, East, South, West Neighbors of the Initial Node.
	//	for each (std::shared_ptr<Node> node in *m_Grid->GetNodes()) {
	//			
	//		auto& northNode = GetNodeLocation(node->GetVertex().position.x, node->GetVertex().position.y + tileSize, lyr);
	//		auto& eastNode = GetNodeLocation(node->GetVertex().position.x + tileSize, node->GetVertex().position.y, lyr);
	//		auto& southNode = GetNodeLocation(node->GetVertex().position.x, node->GetVertex().position.y - tileSize, lyr);
	//		auto& westNode = GetNodeLocation(node->GetVertex().position.x - tileSize, node->GetVertex().position.y, lyr);

	//		neighborCollection->push_back(northNode);
	//		neighborCollection->push_back(eastNode);
	//		neighborCollection->push_back(southNode);
	//		neighborCollection->push_back(westNode);
	//	}
	//	return *neighborCollection;
	//}
}
