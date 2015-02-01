#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

namespace MazeManiaLogic {

	class Game;

	class Logic {

	public:
		Logic(Game &pGame);

		bool Run();

	private:
		Game *m_Game;

	};
}
#endif

