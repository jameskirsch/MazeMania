#include "Game.h"
#include "EventHandler.h" //Forward Declartion
#include "Logic.h" //Forward Declartion
#include "Renderer.h" //Forward Declartion

namespace MazeManiaLogic {

	//Game ctor, and Components
	Game::Game(std::string name, uint32_t id, uint32_t vWidth,
		UINT32 vHeight, uint32_t bpp) :

		m_Clock(new Clock()),
		m_Window(new sf::RenderWindow(sf::VideoMode(vWidth, vHeight, bpp), name)),
		m_Repository(new Repository()),
		m_EventHandler(new EventHandler(*this)),
		m_Logic(new Logic(*this)),
		m_Renderer(new Renderer(*this)),
		m_LevelCollection(new std::vector<Level>)
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
		while (m_Window->isOpen() && isRunning) {

			//Run Game Events
			if (!this->m_EventHandler->RunEvents()) isRunning = false;

			//Run Game Logic
			this->m_Logic->Run();

			//Run Game Rendering
			this->m_Renderer->Run();
		}
	}
}


