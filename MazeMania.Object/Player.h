// The Player Class:
// - Is-a Entity
// - Is used by the Session Class. Session Has-a Collection of Players.
// - Purpose: Will Store specific user information

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "Entity.h"
#include <string>

namespace MazeManiaObject {

	class Player : Entity {
	
	public:
		EXPORT Player();

		inline void SetId(int id) { this->m_Id = id; }
		inline int GetId() const { return m_Id; }
	};
}
#endif
