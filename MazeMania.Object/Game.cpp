#include "Game.h"

namespace MazeManiaObject {

	Game::Game(std::string name, int id, int x, int y)
		: m_VideoMode(x, y),
		m_Window( m_VideoMode, name),
		m_Event()
	{		
		this->m_Id = id;
		this->m_Name = name;
	}

	bool Game::RunGame(bool isRunning) {

		while (isRunning) {
			
			//Events
			while (m_Window.pollEvent(m_Event)) {
				if (m_Event.type == sf::Event::Closed)
					isRunning = false;
			}

			//Logic
			m_Window.clear();

			//Render
			m_Window.display();
		}

		return false;
	}
}

//HAS maps
//HAS entities
//HAS events
//HAS graphics
//HAS players
