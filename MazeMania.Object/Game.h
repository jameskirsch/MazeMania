#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

namespace MazeManiaObject {
	
	class __declspec(dllexport) Game {
	
	public:
		Game(std::string name, int id, int x, int y);

		inline int GetId() const { return this->m_Id; }
		inline std::string GetName() const { return this->m_Name; }

		bool RunGame(bool isRunning);

	protected:
		int m_Id;
		std::string m_Name;
		sf::RenderWindow m_Window;
		sf::VideoMode m_VideoMode;
		sf::Event m_Event;
	};
}
#endif