// The Cell Class:
// - Is-a Collection of 2D vectors, representing points X, Y. Also Represents an Occupied Space. ( initialized to False )
// - Belongs to the Grid Class. The Grid Has-a Collection of Cells.

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <SFML\Graphics.hpp>

namespace MazeManiaObject {

	class Cell : sf::Vector2f {

	public:
		EXPORT Cell();
		
		//Set Cell to Occupied
		EXPORT inline void SetIsOccupied(bool set) { m_IsOccupied = set; }
		
		//Get Current Status of Cell
		EXPORT inline bool GetIsOccupied() { return m_IsOccupied; }

	private:
		bool m_IsOccupied;
	};
}
#endif

