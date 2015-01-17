#pragma once

#include "Entity.h"

//Use to export definitions into Lib
//__declspec(dllexport)

namespace MazeManiaObject
{
	void Entity::SetId(int id)
	{
		this->m_Id = id;
	}

	int Entity::GetId()
	{
		return this->m_Id;
	}
}








