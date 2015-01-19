#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "Entity.h"

namespace MazeManiaObject {
	
	void Entity::SetId(int id) {
		this->m_Id = id;
	}

	int Entity::GetId() {
		return this->m_Id;
	}

	string Entity::test(string name) {
		return name;
	}
}
#endif







