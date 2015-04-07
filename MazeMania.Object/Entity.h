#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <string>

namespace MazeManiaObject {

	class Entity {

	public:
		EXPORT Entity::Entity();
		EXPORT Entity::Entity(int id);
		EXPORT Entity::Entity(int id, std::string name);
		

		inline void SetId(int id) { this->m_Id = id; }
		inline void SetName(std::string name) { this->m_Name = name; }
		EXPORT inline int GetId() { return this->m_Id; }
		EXPORT inline std::string GetName() const { return this->m_Name; }

	protected:
		std::string m_Name;
		int m_Id;
	};
}
#endif






