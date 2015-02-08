// The Level Class:
// - Is-a Entity
// - Has-a Map
// - Will Return a Map ( by Reference )
// - Purpose: Used by the Session Class. Session Has-a Level. Each Level is unique. 

#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "Entity.h"
#include "Map.h"
#include <memory>
#include <vector>

namespace MazeManiaObject {

	class Level : Entity {
	
	public:
		EXPORT Level();
		
		EXPORT inline Map& GetMap() { return *m_Map; }

		//Clean Memory from Map TODO: Find out where/if when to call this
		EXPORT inline void Free() { delete m_Map; }

	private:
		Map *m_Map;
	};
}
#endif

