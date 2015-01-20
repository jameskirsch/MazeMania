#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "SFML\Graphics.hpp"

namespace MazeManiaObject {

	class __declspec(dllexport) Map : public sf::RectangleShape {

	public:
		Map(int id, float size_X, float size_Y);

	protected:
		int m_Id;
	};
}
#endif

