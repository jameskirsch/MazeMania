#include "Map.h"

namespace MazeManiaObject {

	//Initialize
	Map::Map() :
		m_Shape(new sf::RectangleShape()),
		m_Tiles(new std::vector<Tile>()),
		m_Grid(new Grid())
	{
	}                                       
}
