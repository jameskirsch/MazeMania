#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include <ctime>
#include <ratio>
#include <chrono>
#include <memory>

namespace MazeManiaLogic {

	class Clock {

	public:
		Clock();

		double GetTime();

	private:

		std::chrono::high_resolution_clock m_Clock;
	};
}
#endif

