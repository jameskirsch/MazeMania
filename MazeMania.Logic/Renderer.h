#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

#define EXPORT __declspec(dllexport)

//Forward Declaration
class Game;

namespace MazeManiaLogic {

	class Renderer {

	public:
		EXPORT Renderer(Game *ptr);

		EXPORT bool Run();

		Game *m_Game;

	};
}
#endif

