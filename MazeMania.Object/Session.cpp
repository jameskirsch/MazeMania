#include "Session.h"

namespace MazeManiaObject {

	//Initialize
	Session::Session() :
		m_Level(new Level()),
		m_Players(new std::vector<Player>())
	{
	}

}
