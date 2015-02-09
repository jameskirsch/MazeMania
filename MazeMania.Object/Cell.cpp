#include "Cell.h"

namespace MazeManiaObject {

	//Initialize
	Cell::Cell() :
		m_Vertex(new sf::Vertex()),
		m_LayerId(0)
	{
		m_IsOccupied = false;
	}
}
