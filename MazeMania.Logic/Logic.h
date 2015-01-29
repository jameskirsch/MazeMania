#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

namespace MazeManiaLogic {

	class Logic {

	public:
		Logic();

		bool Run(sf::RenderWindow &pWindow);

	};
}
#endif

