#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <string>

namespace MazeManiaObject {

	class __declspec(dllexport) Entity {

	Entity::Entity(int id, std::string name);

	public:
		inline void SetId(int id) { this->m_Id = id; }
		inline void SetName(std::string name) { this->m_Name = name; }
		inline int GetId() const { return this->m_Id; }
		inline std::string GetName() const { return this->m_Name; }

	protected:
		std::string m_Name;
		int m_Id;
	};
}
#endif






