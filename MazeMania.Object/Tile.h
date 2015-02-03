#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <memory>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Entity.h"

namespace MazeManiaObject {

	class Tile : Entity {

	public:
		EXPORT Tile();
		inline sf::RectangleShape& GetShape() { return *m_Shape; }

	private:
		int m_TileTypeId;
		sf::RectangleShape *m_Shape;
	};
}
#endif

