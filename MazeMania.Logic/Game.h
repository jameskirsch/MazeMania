// The Game Class:
// - This Contains everything a Game World will have. 
// - Has-a : Session, Window, Repository, EventHandler, LogicHandler, Renderer, Clock
// - Contains a Game Loop, in which Events, Logic, and Rendering are broken up into separate Modules.

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef unsigned int UINT32;

#include "StateMachine.h"
#include <algorithm>
#include <list>
#include <MazeMania.Object.h>
#include <MazeMania.Data.h>
#include "Session.h"
#include "GridManager.h"
#include "EventHandler.h"
#include "LogicHandler.h"
#include "Renderer.h"
#include "Generator.h"
#include <iostream>
#include <memory>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#define EXPORT __declspec(dllexport)

using namespace MazeManiaObject;
using namespace MazeManiaData;

namespace MazeManiaLogic {

	// Handles everything a typical Game World would handle. ex: events, game logic, 
	class Game {

	public:
		EXPORT Game(std::string name, UINT32 id, UINT32 vWidth, 
			UINT32 vHeight, UINT32 bpp);

		EXPORT inline int GetId() const { return this->m_Id; }
		EXPORT inline std::string GetName() const { return this->m_Name; }

		//Run Games
		EXPORT void RunGame();

		//Initialize any Game Features, such as Player Settings, Maps, etc.
		bool Init();

		EXPORT inline sf::RenderWindow& GetRenderWindow() { return *m_Window; }
		EXPORT inline Clock& GetClock() { return *m_Clock; }
		EXPORT inline Repository&  GetRepository() { return *m_Repository; }
		
		//Returns a Collection of Game Maps
		EXPORT inline Session& GetSession() { return *m_Session; }

		//Get Grid Mgr
		EXPORT inline GridManager& GetGridMgr() { return *m_GridMgr; }
	
	protected:
		int m_Id;
		std::string m_Name;

	private:
		std::unique_ptr<Clock> m_Clock;
		std::unique_ptr<sf::RenderWindow> m_Window;
		std::unique_ptr<Repository> m_Repository;
		std::unique_ptr<EventHandler> m_EventHandler;
		std::unique_ptr<LogicHandler> m_LogicHandler;
		std::unique_ptr<Renderer> m_Renderer;
		std::unique_ptr<Session> m_Session;
		std::unique_ptr<GridManager> m_GridMgr;
	};
}
#endif