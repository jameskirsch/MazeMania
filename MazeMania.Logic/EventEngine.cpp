#include "EventEngine.h"

namespace MazeManiaLogic {

	EventEngine::EventEngine() :
		m_Event(new sf::Event())
	{
	}

	bool EventEngine::runEvents(sf::RenderWindow &pWindow) {

		//Events
		while (pWindow.pollEvent(*m_Event)) {
			if (m_Event->type == sf::Event::Closed)
				return false;
		}

		return true;
	}
	
}
