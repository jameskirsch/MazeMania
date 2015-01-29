#include "Game.h"

namespace MazeManiaLogic {

	//Game ctor, and Components
	Game::Game(std::string name, uint32_t id, uint32_t vWidth,
		UINT32 vHeight, uint32_t bpp) :

		m_Clock(new Clock()),
		m_Window(new sf::RenderWindow(sf::VideoMode(vWidth, vHeight, bpp), name)),
		m_Repository(new Repository()),
		m_EventEngine(new EventEngine()),
		m_Logic(new Logic()),
		m_Renderer(new Renderer(this)),
		m_Map(new std::vector<Map>())
	{
		//Provides Information about the Game
		this->m_Id = id;
		this->m_Name = name;
	}

	//Handles Running the Game With the Primary Game Loop
	void Game::RunGame() {

		bool isRunning;
		//Run Init, if anything should fail, catch the exception here.
		this->Init(*m_Map) == true ? isRunning = true : isRunning = false;

		//The Main Game Loop
		while (isRunning) {

			//Run Game Events
			if (!this->m_EventEngine->RunEvents(*m_Window)) isRunning = false;

			//Run Game Logic
			this->m_Logic->Run(*m_Window);

			//Run Game Rendering
			this->m_Renderer->Run();
		}
	}
}
