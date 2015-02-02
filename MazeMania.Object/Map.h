#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "SFML\Graphics.hpp"

namespace MazeManiaObject {

	class Map : public sf::RectangleShape {

	public:
		EXPORT Map();

	private:
	};
}
#endif

