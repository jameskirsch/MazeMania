#include "GridManager.h"

namespace MazeManiaLogic {

	GridManager::GridManager() : m_Grid(new Grid) { m_NodeCursor = std::make_shared<Node>(); }

	//Get a Single Node by Id
	Node& GridManager::GetNodeId(int id) {		
		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [&id](Node& n) {
		return n.GetId() == id; });
		return *node;
	}

	//Get a Single Node by Position
	Node& GridManager::GetNodeByLocation(float x, float y, int lyr) {
		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [x, y, lyr](Node& n) {
		return n.GetVertex().position.x == x && n.GetVertex().position.y == y && n.GetLayerId() == lyr; });			
		return *node;
	}

	//Looks at a single Node, then Returns a Collection if it's adjacent neighbors
	std::vector<Node>& GridManager::GetNodeNeighbors(Node& node, float tileSize, int lyr) {	
		
		std::vector<Node> *nodes = new std::vector<Node>();

		if (&node != nullptr) {
			auto& northNode = GetNodeByLocation(node.GetVertex().position.x, node.GetVertex().position.y - tileSize, lyr);
			auto& eastNode = GetNodeByLocation(node.GetVertex().position.x + tileSize, node.GetVertex().position.y, lyr);
			auto& southNode = GetNodeByLocation(node.GetVertex().position.x, node.GetVertex().position.y + tileSize, lyr);
			auto& westNode = GetNodeByLocation(node.GetVertex().position.x - tileSize, node.GetVertex().position.y, lyr);

			nodes->push_back(northNode);
			nodes->push_back(eastNode);
			nodes->push_back(southNode);
			nodes->push_back(westNode);

			return *nodes;
		}
	
		return *nodes;
	}
}
