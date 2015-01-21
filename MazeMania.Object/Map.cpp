#include "Map.h"

namespace MazeManiaObject {

	Map::Map( int id, float size_X, float size_Y ) {
		this->m_Id = id;
		this->setSize( sf::Vector2f(size_X, size_Y) );
	}
}
