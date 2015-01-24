#include "Game.h"

namespace MazeManiaLogic {

	//Game ctor, and Components
	Game::Game(std::string name, uint32_t id, uint32_t videoModeWidth,
		UINT32 videoModeHeight, uint32_t bitsPerPixel) :

		m_Window(new sf::RenderWindow(sf::VideoMode(videoModeWidth, videoModeHeight, bitsPerPixel), name)),
		m_Event(new sf::Event),
		m_Player(new Player()),
		m_Load(new Load())
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
