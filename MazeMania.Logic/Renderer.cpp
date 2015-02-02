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
		

		/*std::for_each(m_Game->GetMapCollection().begin(), m_Game->GetMapCollection().end(), [](Map& m) {
		
		});*/

		for each (Map var in m_Game->GetMapCollection()) {
			m_Game->GetRenderWindow().draw(var);
		}

		m_Game->GetRenderWindow().display();
			
		return true;
	}

}
