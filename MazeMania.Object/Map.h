#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "SFML\Graphics.hpp"

namespace MazeManiaObject {

	class Map : public sf::RectangleShape {

	public:
		EXPORT Map(int id, float size_X, float size_Y);
		EXPORT Map() {}

	private:
		int m_Id;
	};
}
#endif

