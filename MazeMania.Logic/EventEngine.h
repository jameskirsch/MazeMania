#ifndef EVENT_ENGINE_H_INCLUDED
#define EVENT_ENGINE_H_INCLUDED

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <memory>

namespace MazeManiaLogic {

	class EventEngine {

	public:
		EventEngine();

		bool RunEvents(sf::RenderWindow &pWindow);

	private:

		std::unique_ptr<sf::Event> m_Event;
	};
}
#endif
