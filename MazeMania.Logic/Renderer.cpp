//#include "Renderer.h"
#include "Game.h"
#include "Renderer.h"

namespace MazeManiaLogic {

	Renderer::Renderer(Game *ptr)	
	{
		this->m_Game = ptr;
	}
	
	//DI ?
	bool Renderer::Run() {

		//this->m_Game->GetRenderWindow().display();

		return true;
	}
}
