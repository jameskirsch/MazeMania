#ifndef EVENT_HANDLER_H_INCLUDED
#define EVENT_HANDLER_H_INCLUDED

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <memory>

namespace MazeManiaLogic {

	class Game; //Used for Forward Declartion

	class EventHandler {

	public:
		EventHandler(Game &pGame);

		bool RunEvents();

	private:
		Game *m_Game;
		std::unique_ptr<sf::Event> m_Event;
	};
}
#endif
