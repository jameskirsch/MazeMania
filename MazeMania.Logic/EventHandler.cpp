#include "Game.h"
#include "EventHandler.h"

namespace MazeManiaLogic {

	EventHandler::EventHandler(Game &pGame) :
		m_Game(&pGame),
		m_Event(new sf::Event())
	{
	}

	//Checks for Any Events That Occur in Game
	bool EventHandler::RunEvents() {

		//Event Loop
		while ( m_Game->GetRenderWindow().pollEvent(*m_Event)) {
			if (this->m_Event->type == sf::Event::Closed)
				return false;
		}

		return true;
	}
	
}
