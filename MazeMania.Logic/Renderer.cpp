#include "Renderer.h"
#include "Game.h"
#include <algorithm>
#include <iostream>

namespace MazeManiaLogic {

	Renderer::Renderer(Game &pGame) :
		m_Game(&pGame)
	{

	}
	
	bool Renderer::Run() {

		m_Game->GetRenderWindow().clear(sf::Color::Green);
		
		//Draws Maps that are in the Levels TO DO: encapsulate these
		for (auto &i : m_Game->GetLevelCollection()){
			Map tMap = i.GetMap();
			m_Game->GetRenderWindow().draw(tMap);
		}

		m_Game->GetRenderWindow().display();
			
		return true;
	}

}
