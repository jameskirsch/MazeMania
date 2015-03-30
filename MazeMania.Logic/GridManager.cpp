#include "GridManager.h"

namespace MazeManiaLogic {

	GridManager::GridManager() : m_Grid(new Grid) { }

	//Get a Single Node by Id
	Node& GridManager::GetNodeId(int id) {		
		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [&id](Node& n) {
		return n.GetId() == id; });
		return *node;
	}

	//Get a Single Node by Position
	Node& GridManager::GetNodeByLocation(float x, float y, int lyr) {
		auto& node = std::find_if(m_Grid->GetNodes().begin(), m_Grid->GetNodes().end(), [x, y, lyr](Node& n) {
		return n.GetVertex().position.x == x && n.GetVertex().position.y && n.GetLayerId() == lyr; });			
		return *node;
	}

}
