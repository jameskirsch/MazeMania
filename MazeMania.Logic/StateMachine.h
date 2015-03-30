#ifndef STATE_MACHINE_H_INCLUDED
#define STATE_MACHINE_H_INCLUDED


#include <string>
#include <algorithm>
#include <map>

namespace MazeManiaLogic {

	class GameState {
	
	public: 
		GameState();
	
	private:
		bool m_IsCurrent;
	};

	class StateMachine {

	public:
		StateMachine();
		
	private:
	
	};
}
#endif

