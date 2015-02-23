#include "Node.h"

namespace MazeManiaObject {

	//Initialize
	Node::Node() :
		m_LayerId(0)
	{
		m_Vertex = std::make_shared<sf::Vertex>();
		m_IsOccupied = false;
		m_IsBoundary = false;
	}
}
