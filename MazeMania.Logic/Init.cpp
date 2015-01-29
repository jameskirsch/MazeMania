#include "Init.h"

namespace MazeManiaLogic {

	//Initialize all Game Features
	bool Game::Init(std::vector<Map> &pMap) {

		Map map;
		Map map2;

		sf::Vector2f xy;

		//Assign Maps into m_Map
		//... need to iterate Map Data coming from Repo
		pMap.push_back(map);
		pMap.push_back(map2);

		std::cout << "Size Of Map Container: " << pMap.size() << std::endl;

		//Look at each Map Obj in the Vector and Construct it
		for each (Map obj in pMap) {

			obj.setSize(sf::Vector2f(100.f, 100.f));
			xy = obj.getSize();
			std::cout << "X " << xy.x << " " << "Y " << xy.y << std::endl;
		}

		return true;
	}
}