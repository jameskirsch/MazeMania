#include "Grid.h"

namespace MazeManiaObject {

	//Initialize memory
	Grid::Grid() :
		m_Layers(new std::vector<int>),
		m_Vertices(new sf::VertexArray()),
		m_Nodes(new std::vector<Node>),
		m_BoundaryNodes(new std::vector<Node>())
	{	
	}

	//Free memory
	Grid::~Grid() {
		//delete m_Layers;
	}

	//Populates Layers based on Input
	void Grid::SetLayers(int numLayers) {

		//Clear out the container
		m_Layers->empty();
		
		//Push Layers into container by Id
		for (int i = 1; i <= numLayers; i++) {
			m_Layers->push_back(i);			
		}		
	}

}