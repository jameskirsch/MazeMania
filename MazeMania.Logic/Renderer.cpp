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

		m_Game->GetRenderWindow().clear(sf::Color(55,55,55));
		
		//Draws Maps that are in the Levels TO DO: encapsulate these	
			m_Game->GetRenderWindow().draw(static_cast<sf::RectangleShape>
				(m_Game->GetSession().GetLevel().GetMap().GetShape()));

			//Draw Tiles on the Map
			for (auto&i : m_Game->GetSession().GetLevel().GetMap().GetTiles() ) {
				m_Game->GetRenderWindow().draw(static_cast<sf::RectangleShape>(i.GetShape()));
			}
		
		m_Game->GetRenderWindow().display();
			
		return true;
	}

}
