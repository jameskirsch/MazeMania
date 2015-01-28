#include "RenderEngine.h"


namespace MazeManiaLogic {

	RenderEngine::RenderEngine()
	{
	}
	
	bool RenderEngine::runRendering(sf::RenderWindow &pWindow) {

		pWindow.display();

		return true;
	}
}
