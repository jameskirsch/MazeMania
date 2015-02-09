// The Cell Class:
// - Has-a vertex. Also Represents an Occupied Space. ( initialized to False )
// - Belongs to the Grid Class. The Grid Has-a Collection of Cells.

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <SFML\Graphics.hpp>
#include <memory>

namespace MazeManiaObject {

	class Cell {

	public:
		EXPORT Cell();
		
		//Set Cell to Occupied
		EXPORT inline void SetIsOccupied(bool set) { m_IsOccupied = set; }
		
		//Get Current Status of Cell
		EXPORT inline bool GetIsOccupied() { return m_IsOccupied; }

		//Return Cell's Vertex
		EXPORT inline sf::Vertex& GetVertex() { return *m_Vertex; }

	private:
		bool m_IsOccupied;
		sf::Vertex *m_Vertex;
	};
}
#endif

