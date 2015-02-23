// The Grid Class:
// ---------------
// - Has-a vertex array.
// - is used by the Map Class. Map Has-a Grid. The Grid defines a dynamic vertex collection within the Grid ( by each Cell )
// - Each Cell in the Grid is a Vertex. Also with with a status of being occupied or not.
// - Has-a collection of Layers, that can be expanded dynamically.
// - Can Set the Number of Layers, and Return those Layers to work with

#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
#include "Node.h"

namespace MazeManiaObject {

	class Grid {

	public:
		EXPORT Grid();
		EXPORT ~Grid();

		//Set the Number of Layers needed on the Grid ( Dynamic )
		EXPORT inline void SetLayers(int numLayers);

		//Returns the Number of Layers currently stored in the Grid ( 3 Layers by default )
		EXPORT inline std::vector<int>& GetLayers() { return *m_Layers; }

		//Return The Collection of Vertices
		EXPORT inline sf::VertexArray& GetVerts() { return *m_Vertices; }

		//Get Cell Collection : Owns a 
		EXPORT inline std::vector<Node>& GetNodes() { return *m_Nodes; }

	private:
		std::vector<int> *m_Layers;
		sf::VertexArray *m_Vertices;
		std::vector<Node> *m_Nodes;
	};
}
#endif

