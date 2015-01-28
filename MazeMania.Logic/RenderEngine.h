#ifndef RENDER_ENGINE_H_INCLUDED
#define RENDER_ENGINE_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

namespace MazeManiaLogic {

	class RenderEngine {

	public:
		RenderEngine();

		bool runRendering(sf::RenderWindow &pWindow);
	};
}
#endif

