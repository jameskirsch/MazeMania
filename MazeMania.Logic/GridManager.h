#ifndef GRID_MANAGER_H
#define GRID_MANAGER_H

#define EXPORT __declspec(dllexport)

#include <cassert>
#include <SFML\Graphics.hpp>
#include "Node.h"
#include "Grid.h"

using namespace MazeManiaObject;

namespace MazeManiaLogic {

	//Handle Node Behavior
	class GridManager {

	public:
		EXPORT GridManager();
		EXPORT ~GridManager();

		//Set Grid
		EXPORT inline void SetGrid(Grid& grid) { *m_Grid = grid; }

		//Get Single Node by Id
		EXPORT Node& GetNodeId(int id);

		//Get Single Node by Position
		EXPORT Node& GetNodeByLocation(float x, float y, int lyr);

		//Get Vertex Array
		EXPORT inline sf::VertexArray& GetVertexArray() { return m_Grid->GetVerts(); }

		//Get Node Neighbors ( select a node by position
		//EXPORT std::vector<std::shared_ptr<Node>>& GetNodeNeighbors(float x, float y, int lyr, float tileSize);

	private:
		Grid *m_Grid;	
	};
}
#endif

