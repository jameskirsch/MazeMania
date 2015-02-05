#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {
		
		//TO DO: Make this value an input
		int numTiles = 10;
		
		
		//Set the Level, initialize tiles
		sf::Vector2u screenSize = GetRenderWindow().getSize();
		m_Session->GetLevel().GetMap().GetTiles().resize(numTiles * 2);
		m_Session->GetLevel().GetMap().GetShape().setSize(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));
		m_Session->GetLevel().GetMap().GetShape().setFillColor(sf::Color::Black);
		m_Session->GetLevel().GetMap().GetShape().setPosition
		(((screenSize.x / 2) - (m_Session->GetLevel().GetMap().GetShape().getSize().x / 2)),
		(screenSize.y / 2) - (m_Session->GetLevel().GetMap().GetShape().getSize().y / 2));

	
		//Lay Down Tiles Across Level
		float tTileWidth = 0, tTileHeight = 0;

		for (auto &tile : m_Session->GetLevel().GetMap().GetTiles()) {

			tile.GetShape().setSize(sf::Vector2f(16.0f, 16.0f));
			tile.GetShape().setFillColor(sf::Color::Red);
			tile.GetShape().setPosition(
				m_Session->GetLevel().GetMap().GetShape().getPosition().x + tTileWidth,
				m_Session->GetLevel().GetMap().GetShape().getPosition().y + tTileHeight);

			tTileWidth += tile.GetShape().getSize().x;
		}
		
		return true;
	}
}