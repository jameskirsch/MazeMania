#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Session.h"

using namespace MazeManiaObject;

namespace MazeManiaLogic {

	//The purpose of this class is to Generate a Maze on the Grid
	class Generator {

	public:
		EXPORT Generator(Session& session);
		EXPORT void GenerateMaze(float tileSize);

	private:
		Session& m_Session;
	};
}

#endif

