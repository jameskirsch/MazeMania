#include "Cell.h"

namespace MazeManiaObject {

	//Initialize
	Cell::Cell() :
		m_Vertex(new sf::Vertex())
	{
		m_IsOccupied = false;
	}
}
