#include "Renderer.h"
#include "Game.h"

namespace MazeManiaLogic {

	Renderer::Renderer(Game &pGame) :
		m_Game(&pGame)
	{

	}
	
	bool Renderer::Run() {

		m_Game->GetRenderWindow().display();

		return true;
	}

}
