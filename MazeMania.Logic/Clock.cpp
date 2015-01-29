#include "Clock.h"

namespace MazeManiaLogic {

	Clock::Clock() 
		//m_Clock(new  std::chrono::high_resolution_clock())
	{
	}

	double Clock::GetTime() {
		std::chrono::high_resolution_clock::time_point  t1 = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();;
	

		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		//std::chrono::high_resolution_clock::

		return time_span.count();
	}
}