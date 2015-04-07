#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Session.h"
#include "GridManager.h"

using namespace MazeManiaObject;

namespace MazeManiaLogic {

	//The purpose of this class is to Generate a Maze on the Grid
	class Generator {

	public:
		//EXPORT Generator();
		EXPORT Generator(Session& session, GridManager& gridMgr);
		EXPORT void GenerateMaze(float tileSize);

		//EXPORT inline void SetSession(Session* session) { m_Session = *session; }
		//EXPORT inline void SetGridMgr(GridManager* gridMgr) { m_GridMgr = *gridMgr; }
		/*EXPORT inline Session& GetSession() { return m_Session; }
		EXPORT inline GridManager& GetGridMgr() { return m_GridMgr; }*/

	private:
		Session* m_Session;
		GridManager* m_GridMgr;
		Node* m_CurrentNode;
	};
}

#endif

