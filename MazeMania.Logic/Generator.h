#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Session.h"
#include "GridManager.h"

using namespace MazeManiaObject;

namespace MazeManiaLogic {

	//The purpose of this class is to Generate a Maze on the Grid
	class Generator {

	public:
		EXPORT Generator(Session& session, GridManager& gridMgr);
		EXPORT void GenerateMaze(float tileSize);

	private:
		Session& m_Session;
		GridManager& m_GridMgr;
	};
}

#endif

