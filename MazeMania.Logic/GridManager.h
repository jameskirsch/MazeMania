#ifndef GRID_MANAGER_H
#define GRID_MANAGER_H

#define EXPORT __declspec(dllexport)

#include <cassert>
#include <SFML\Graphics.hpp>
#include "Node.h"
#include "Grid.h"
#include <stack>

using namespace MazeManiaObject;

namespace MazeManiaLogic {

	//Handle Node Behavior
	class GridManager {

	public:
		EXPORT GridManager();

		//Set Grid
		EXPORT inline void SetGrid(Grid& grid) { *m_Grid = grid; }

		//Get Single Node by Id
		EXPORT Node& GetNodeId(int id);

		//Get Single Node by Position
		EXPORT Node& GetNodeByLocation(std::vector<Node>& nodeCollection, float x, float y, int lyr);

		//Create a new node on Grid
		//EXPORT void CreateNode()

		//Get Vertex Array
		EXPORT inline sf::VertexArray& GetVertexArray() { return m_Grid->GetVerts(); }

		//Get Node Neighbors ( select a node by position
		EXPORT std::vector<Node> GetNodeNeighbors(std::vector<Node>& nodes, Node& node, float tileSize, int lyr);

		//Creates Boundary Nodes around the existing Grid
		EXPORT void SetBoundaryNodes(float mapSizeX, float mapSizeY, std::vector<Node>& nodes);

	private:
		Grid *m_Grid;
		std::shared_ptr<Node> m_NodeCursor;
	};
}
#endif

