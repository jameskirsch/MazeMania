// The Map Class:
// - Is an Entity
// - Has-a Shape, based off of a RectangleShape Class.
// - Has-a Grid Class. The Grid represents a 3D container for 2D vectors. The Grid can be populated, and locations checked.
// - Is used by the Level Class. Level Class Has-a Map Class.

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Entity.h"
#include "Tile.h"
#include <memory>
#include <vector>
#include "Grid.h"

#define EXPORT __declspec(dllexport)

#include "SFML\Graphics.hpp"

namespace MazeManiaObject {

	class Map : Entity {

	public:
		EXPORT Map();

		//Return Shape of the Map. Contains Size, Coords, etc.
		EXPORT inline sf::RectangleShape& GetShape() { return *m_Shape; }
		
		//Return ALL tiles Loaded into the Map. Can sort by Id
		EXPORT inline std::vector<Tile>& GetTiles() { return *m_Tiles; }

		//Return the Grid, this is to be populated with Tiles per Layer.
		EXPORT inline Grid& GetGrid() { return *m_Grid; }

	private:
		std::unique_ptr<sf::RectangleShape> m_Shape;
		std::unique_ptr<std::vector<Tile>> m_Tiles;
		std::unique_ptr<Grid> m_Grid;
	};
}
#endif

