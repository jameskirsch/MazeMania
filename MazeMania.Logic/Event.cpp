//This implements all events that take place within the Game Object
#include "Event.h"

namespace MazeManiaLogic {

	//Game Events, Clicks, Buttons, etc
	bool Game::Events() {

		//Events
		while (m_Window->pollEvent(*m_Event)) {
			if (m_Event->type == sf::Event::Closed)
				return false;
		}

		return true;
	}
}