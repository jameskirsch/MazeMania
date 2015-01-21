#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef unsigned int UINT32;

#include <string>
#include <memory>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

namespace MazeManiaObject {
	
	// Handles everything a typical Game World would handle.
	// Has events, game logic, 
	class __declspec(dllexport) Game {
	
	public:
		Game(std::string name, UINT32 id, UINT32 videoModeWidth, UINT32 videoModeHeight, UINT32 bitsPerPixel);

		inline int GetId() const { return this->m_Id; }
		inline std::string GetName() const { return this->m_Name; }

		bool RunGame(bool isRunning);
		bool Events();
		void Logic();
		void Render();

	protected:
		int m_Id;
		std::string m_Name;

	private:
		std::unique_ptr<sf::RenderWindow> m_Window;
		std::unique_ptr<sf::Event> m_Event;
	};
}
#endif