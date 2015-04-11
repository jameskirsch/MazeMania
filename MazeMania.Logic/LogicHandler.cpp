#include "LogicHandler.h"
#include "Game.h"

namespace MazeManiaLogic {

	LogicHandler::LogicHandler(Game &pGame) :
		m_Game(&pGame),
		m_HasGenerator(false)
	{

	}

	bool LogicHandler::Run(Generator& generator) {

		//auto& generator = m_GeneratorPtr;

		//if (m_HasGenerator == false) {
		//	m_GeneratorPtr = new Generator(m_Game->GetSession(), m_Game->GetGridMgr());
		//	//generator = *m_GeneratorPtr;
		//	m_HasGenerator = true;	
		//}
		
		generator.GenerateMaze(m_Game->GetGridMgr().GetTileSize());
		
		return true;
	}
}
