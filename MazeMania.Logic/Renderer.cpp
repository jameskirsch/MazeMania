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

		sf::Vector2f xy;

		m_Game->GetRenderWindow().clear(sf::Color::White);
		
		for (auto &i : m_Game->GetLevelCollection()){
			Map tMap = i.GetMap();
			m_Game->GetRenderWindow().draw(tMap);
		}

		m_Game->GetRenderWindow().display();
			
		return true;
	}

}
