#include "LogicHandler.h"
#include "Game.h"

namespace MazeManiaLogic {

	LogicHandler::LogicHandler(Game &pGame) :
		m_Game(&pGame)
	{
	}

	bool LogicHandler::Run() {

		auto& map = m_Game->GetSession().GetLevel().GetMap();
		auto& verts = map.GetGrid().GetVerts();
		auto& gridMgr = m_Game->GetGridMgr();
		
		return true;
	}
}
