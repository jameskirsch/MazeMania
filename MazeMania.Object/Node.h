// The Node Class:
// - Has-a vertex. Also Represents an Occupied Space. ( initialized to False )
// - Belongs to the Grid Class. The Grid Has-a Collection of Cells.

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <SFML\Graphics.hpp>
#include <memory>
#include "Entity.h"

namespace MazeManiaObject {

	class Node : public Entity {

	public:
		EXPORT Node();
		
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

		//Set as a Boundary Node
		EXPORT inline void SetBoundaryNode(bool boundary) { m_IsBoundary = boundary; }

		//Get Boundary Status
		EXPORT inline bool GetBoundaryStatus() { return m_IsBoundary; }

	private:
		bool m_IsOccupied;
		bool m_IsBoundary;
		int m_LayerId;
		sf::Vertex *m_Vertex;
	};
}
#endif

