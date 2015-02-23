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
		auto& n = gridMgr.GetNodeByLocation(map.GetShape().getPosition().x, map.GetShape().getPosition().y, 1);
		
		
		//n.ChangeColor(sf::Color::Red);
		/*n.GetVertex().position.x = 260;
		n.GetVertex().position.y = 300;
		std::cout << n.GetVertex().position.x << std::endl;*/

		return true;
	}
}
