#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <memory>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Entity.h"

namespace MazeManiaObject {

	class Tile : Entity {

	public:
		Tile();

	private:
		int m_TileTypeId;
		std::unique_ptr<sf::RectangleShape> m_RectShape;
	};
}
#endif

