#include "Node.h"

namespace MazeManiaObject {

	//Initialize
	Node::Node() :
		m_Vertex(new sf::Vertex()),
		m_LayerId(0)
	{
		m_IsOccupied = false;
		m_IsBoundary = false;
	}
}
