#include "Logic.h"
#include "Game.h"

namespace MazeManiaLogic {

	Logic::Logic(Game &pGame) :
		m_Game(&pGame)
	{
	}

	bool Logic::Run() {
		
		m_Game->GetRenderWindow().clear();
				
		return true;
	}
}
