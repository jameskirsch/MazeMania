#ifndef LOGIC__HANDLER_H_INCLUDED
#define LOGIC__HANDLER_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "GridManager.h"
#include "Generator.h"
#include <memory>

namespace MazeManiaLogic {

	class Game;

	class LogicHandler {

	public:
		LogicHandler(Game &pGame);

		bool Run(Generator& generator);

	private:
		bool m_HasGenerator;
		Game *m_Game;
	};
}
#endif

