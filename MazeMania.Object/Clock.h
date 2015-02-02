#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "SFML\System.hpp"
#include <memory>

namespace MazeManiaObject {

	class Clock : sf::Clock {

	public:
		EXPORT Clock();
		EXPORT double GetTime();

	private:

		std::unique_ptr<sf::Time> m_Time;
	};
}
#endif
