#include "Generator.h"

namespace MazeManiaLogic {

	Generator::Generator(Session& session, GridManager& gridMgr) : m_Session(session), m_GridMgr(gridMgr) { }

	//Will use the Grid to Generate a Maze
	void Generator::GenerateMaze(float tileSize) {

		auto& map = m_Session.GetLevel().GetMap();
		auto& grid = m_Session.GetLevel().GetMap().GetGrid();
		auto& nodes = m_Session.GetLevel().GetMap().GetGrid().GetNodes();
		auto& mapRect = map.GetShape();

		// Maze Algorithm ( create tiles on first layer of grid )
		for (auto& node : nodes) {

			if (node.GetIsOccupied() == false && node.GetBoundaryStatus() == false && node.GetLayerId() == 1) {
				std::unique_ptr<Tile> tile(new Tile);
				tile->GetShape().setSize(sf::Vector2f(tileSize, tileSize));
				tile->GetShape().setFillColor(sf::Color::Red);
				tile->GetShape().setPosition(node.GetVertex().position.x, node.GetVertex().position.y);
				tile->SetNode(node);
				map.GetTiles().push_back(*tile);
				node.SetIsOccupied(true);
			}
		}

		//256, 192 ( first Node )
		auto selectedNode = this->m_GridMgr.GetNodeByLocation(256, 192, 1);
		auto& nodeNeighbors = this->m_GridMgr.GetNodeNeighbors(selectedNode, tileSize, 1);
			
	}
}
