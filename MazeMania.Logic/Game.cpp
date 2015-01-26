#include "Game.h"

namespace MazeManiaLogic {

	//Game ctor, and Components
	Game::Game(std::string name, uint32_t id, uint32_t vWidth,
		UINT32 vHeight, uint32_t bpp) :

		m_Window(new sf::RenderWindow(sf::VideoMode(vWidth, vHeight, bpp), name)),
		m_Event(new sf::Event),
		m_Repository(new Repository())
	{
		//Provides Information about the Game
		this->m_Id = id;
		this->m_Name = name;
	}

	//Handles Running the Game With the Primary Game Loop
	void Game::RunGame() {

		bool isRunning;
		//Run Init, if anything should fail, catch the exception here.
		this->Init() == true ? isRunning = true : isRunning = false;

		//The Main Game Loop
		while (isRunning) {

			//Run Game Events
			if (!this->Events()) isRunning = false;

			//Run Game Logic
			this->Logic();

			//Run Game Rendering
			this->Render();
		}
	}
}
