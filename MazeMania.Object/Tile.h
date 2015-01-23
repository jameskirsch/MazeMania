#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Entity.h"

namespace MazeManiaObject {

	class Tile : public sf::RectangleShape, public Entity {

	public:
		Tile();


	private:
		int m_TileId;

	};
}
#endif

