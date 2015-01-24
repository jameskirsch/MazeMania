#pragma once

#include "Entity.h"

namespace MazeManiaObject {

	Entity::Entity(){}

	Entity::Entity(int id) {
		this->m_Id = id;
	}

	Entity::Entity(int id, std::string name) {
		this->m_Id = id;
		this->m_Name = name;
	}
}








