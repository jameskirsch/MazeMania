#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef unsigned int UINT32;

#include <MazeMania.Object.h>
#include <MazeMania.Data.h>
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

		//Called 
		EXPORT void RunGame();

		//Initialize any Game Features, such as Player Settings, Maps, etc.
		bool Init();

		//Handle All Game Input and Events
		bool Events();

		//Handle Game Logic, Such as AI, Object Interactions, etc.
		void Logic();

		//Handle Drawing Graphics to the Screen & Display
		void Render();

	protected:
		int m_Id;
		std::string m_Name;

	private:
		std::unique_ptr<sf::RenderWindow> m_Window;
		std::unique_ptr<sf::Event> m_Event;
		std::unique_ptr<Repository> m_Repository;
		std::vector<Player> m_Player;
		std::vector<Map> m_Map;		
	};
}
#endif