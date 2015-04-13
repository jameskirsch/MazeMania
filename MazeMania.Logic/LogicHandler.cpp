#include "LogicHandler.h"
#include "Game.h"

namespace MazeManiaLogic {

	LogicHandler::LogicHandler(Game &pGame) :
		m_Game(&pGame),
		m_HasGenerator(false)
	{

	}

	bool LogicHandler::Run(Generator& generator) {
	
		generator.GenerateMaze(m_Game->GetGridMgr().GetTileSize());
		
		return true;
	}
}
