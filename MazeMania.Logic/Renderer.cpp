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
			m_Game->GetRenderWindow().draw(static_cast<sf::RectangleShape>(i.GetMap().GetShape()));

			//Draw Tiles on the Map
			for (auto&i : i.GetMap().GetTileCollection())
				m_Game->GetRenderWindow().draw(static_cast<sf::RectangleShape>(i.GetShape()));
		}

		m_Game->GetRenderWindow().display();
			
		return true;
	}

}
