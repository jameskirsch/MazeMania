#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init() {
	
		//This should Create an amount of Maps, and push them into the container : TO DO: Fix memory issues
		int numMaps = 3;

		for (int i = 0; i <= numMaps; i++) {
			auto p = m_Map.get();
			Map* m = new Map[i];

			for (auto &i : *this->m_Map) {
				p->push_back(m[i]); // problem spot
			}
		}

		//For testing
		std::cout << "Size: " << p->size() << std::endl;

		//Set the Position of Maps on the Game World, Set Any other Map Properties, such as Color, Size, etc.
		float x = 0.f, y = 0.f;
		std::for_each(this->GetMapCollection().begin(), this->GetMapCollection().end(),[&x, &y](Map& m) { 
			m.setSize(sf::Vector2f(50.f, 50.f)),
			m.setFillColor(sf::Color::Green),
			m.setPosition( x, y),
			x += 50.f, y += 50;
		});

		//std::cout << "Size Of Map Container: " << p->size() << std::endl;

		return true;
	}
}