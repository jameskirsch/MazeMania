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
	Node& GridManager::GetNodeByLocation(std::vector<Node>& nodes, float x, float y, int lyr) {
		auto& node = std::find_if(nodes.begin(), nodes.end(), [x, y, lyr](Node& n) {
		return n.GetVertex().position.x == x && n.GetVertex().position.y == y && n.GetLayerId() == lyr; });			
		return *node;
	}

	//Looks at a single Node, then Returns a Collection if it's adjacent neighbors
	std::vector<Node> GridManager::GetNodeNeighbors(std::vector<Node>& nodes, Node& node, float tileSize, int lyr) {	
		
		std::vector<Node> *tNodes = new std::vector<Node>();

		if (&node != nullptr) {

			auto& northNode = GetNodeByLocation(nodes, node.GetVertex().position.x, node.GetVertex().position.y - tileSize, lyr);
			auto& eastNode = GetNodeByLocation(nodes, node.GetVertex().position.x + tileSize, node.GetVertex().position.y, lyr);
			auto& southNode = GetNodeByLocation(nodes, node.GetVertex().position.x, node.GetVertex().position.y + tileSize, lyr);
			auto& westNode = GetNodeByLocation(nodes, node.GetVertex().position.x - tileSize, node.GetVertex().position.y, lyr);

			tNodes->push_back(northNode);
			tNodes->push_back(eastNode);
			tNodes->push_back(southNode);
			tNodes->push_back(westNode);

			return *tNodes;
		}
	
		return *tNodes;
	}
}
