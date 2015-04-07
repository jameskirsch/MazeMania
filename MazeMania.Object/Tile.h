#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <memory>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Entity.h"
//#include "Node.h"

namespace MazeManiaObject {

	class Tile : Entity {

	public:
		EXPORT Tile();
		EXPORT inline sf::RectangleShape& GetShape() { return *m_Shape; }
		//EXPORT inline std::shared_ptr<Node>& GetNode() { return m_Node; }
		//EXPORT inline void SetNode(Node& node) { *m_Node = node; }

	private:
		int m_TileTypeId;
		sf::RectangleShape *m_Shape;
		//std::shared_ptr<Node> m_Node;
	};
}
#endif

