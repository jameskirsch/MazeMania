#ifndef LOGIC_ENGINE_H_INCLUDED
#define LOGIC_ENGINE_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

namespace MazeManiaLogic {

	class LogicEngine {

	public:
		LogicEngine();

		bool runLogic(sf::RenderWindow &pWindow);

	};
}
#endif

