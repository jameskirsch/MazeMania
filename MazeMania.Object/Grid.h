// The Grid Class:
// ---------------
// - is a Collection of Cells from the Cell Class.
// - is used by the Map Class. Map Has-a Grid. The Grid defines a dynamic collection of 2D vectors within the Grid ( by each Cell )
// - Each Cell in the Grid is an X, Y coordinate. Also with with a status of being occupied or not.
// - Has-a collection of Layers, that can be expanded dynamically.
// - Can Set the Number of Layers, and Return those Layers to work with

#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
#include "Cell.h"

namespace MazeManiaObject {

	class Grid : std::vector<Cell> {

	public:
		EXPORT Grid();
		EXPORT ~Grid();

		//Set the Number of Layers needed on the Grid ( Dynamic )
		EXPORT inline void SetLayers(int numLayers);

		//Returns the Number of Layers currently stored in the Grid ( 3 Layers by default )
		EXPORT inline std::vector<int>& GetLayers() { return *m_Layers; }

	private:
		std::vector<int> *m_Layers;
	};
}
#endif

