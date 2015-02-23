#include "Game.h"
#include "EventHandler.h" //Forward Declaration
#include "LogicHandler.h" //Forward Declaration
#include "Renderer.h" //Forward Declaration

namespace MazeManiaLogic {

	//Game ctor, and Components
	Game::Game(std::string name, uint32_t id, uint32_t vWidth,
		UINT32 vHeight, uint32_t bpp) :

		m_Clock(new Clock()),
		m_Window(new sf::RenderWindow(sf::VideoMode(vWidth, vHeight, bpp), name)),
		m_Repository(new Repository()),
		m_EventHandler(new EventHandler(*this)),
		m_LogicHandler(new LogicHandler(*this)),
		m_Renderer(new Renderer(*this)),
		m_Session(new Session()),
		m_GridMgr(new GridManager())
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
			this->m_LogicHandler->Run();

			//Run Game Rendering 
			this->m_Renderer->Run();
		}
	}
}


