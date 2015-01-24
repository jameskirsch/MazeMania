#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "Entity.h"
#include <string>

namespace MazeManiaObject {

	class Player : Entity {
	
	public:
		EXPORT Player();
		EXPORT Player(int id);

		inline void SetId(int id) { this->m_Id = id; }
		inline int GetId() const { return m_Id; }
	};
}
#endif
