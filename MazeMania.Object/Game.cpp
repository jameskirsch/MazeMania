#include "Game.h"

namespace MazeManiaObject {

	//Game ctor, and Components
	Game::Game(std::string name, UINT32 id, UINT32 videoModeWidth, 
		UINT32 videoModeHeight, UINT32 bitsPerPixel) :
		m_Window(new sf::RenderWindow(sf::VideoMode(videoModeWidth, videoModeHeight, bitsPerPixel), name)),
		m_Event(new sf::Event)
	{		
		//Provides Information about the Game
		this->m_Id = id;
		this->m_Name = name;
	}

	//Handles Running the Game With the Primary Game Loop
	bool Game::RunGame(bool isRunning) {

		//The Main Game Loop
		while (isRunning) {
			
			//Run Game Events
			if (!this->Events()) isRunning = false;

			//Run Game Logic
			this->Logic();

			//Run Game Rendering
			this->Render();
		}

		return false;
	}

	//Game Events, Clicks, Buttons, etc
	bool Game::Events() {

		//Events
		while (m_Window->pollEvent(*m_Event)) {
			if (m_Event->type == sf::Event::Closed)
				return false;
		}

		return true;
	}

	//Game Logic, AI, etc
	void Game::Logic() {
		m_Window->clear();
	}

	//Drawing to Screen
	void Game::Render() {
		m_Window->display();
	}
}

//HAS maps
//HAS entities
//HAS events
//HAS graphics
//HAS players
