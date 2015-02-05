#include "Map.h"

namespace MazeManiaObject {

	Map::Map() :
		m_Shape(new sf::RectangleShape()),
		m_Tiles(new std::vector<Tile>())
	{
	}
}
