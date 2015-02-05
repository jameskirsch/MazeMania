#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Entity.h"
#include "Tile.h"
#include <memory>
#include <vector>

#define EXPORT __declspec(dllexport)

#include "SFML\Graphics.hpp"

namespace MazeManiaObject {

	class Map : Entity {

	public:
		EXPORT Map();
		EXPORT inline sf::RectangleShape& GetShape() { return *m_Shape; }
		EXPORT inline std::vector<Tile>& GetTiles() { return *m_Tiles; }

	private:
		std::unique_ptr<sf::RectangleShape> m_Shape;
		std::vector<Tile> *m_Tiles;

	};
}
#endif

