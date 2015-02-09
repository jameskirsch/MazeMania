// The Cell Class:
// - Has-a vertex. Also Represents an Occupied Space. ( initialized to False )
// - Belongs to the Grid Class. The Grid Has-a Collection of Cells.

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <SFML\Graphics.hpp>
#include <memory>
#include "Entity.h"

namespace MazeManiaObject {

	class Cell : public Entity {

	public:
		EXPORT Cell();
		
		//Set Cell to Occupied
		EXPORT inline void SetIsOccupied(bool set) { m_IsOccupied = set; }

		//Set Layer
		EXPORT inline void SetLayerId(int layerId) { m_LayerId = layerId; }
		
		//Get Current Status of Cell
		EXPORT inline bool GetIsOccupied() { return m_IsOccupied; }

		//Get Layer
		EXPORT inline int GetLayerId() { return m_LayerId; }

		//Return Cell's Vertex
		EXPORT inline sf::Vertex& GetVertex() { return *m_Vertex; }

	private:
		bool m_IsOccupied;
		int m_LayerId;
		sf::Vertex *m_Vertex;
	};
}
#endif

