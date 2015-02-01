#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

#define EXPORT __declspec(dllexport)

namespace MazeManiaLogic {

	//This is needed to Resolve Circular Dependencies between Game, and Renderer ( Forward Declaration )
	class Game;

	class Renderer {

	public:
		EXPORT Renderer(Game &pGame);
		EXPORT bool Run();

	private:
		Game *m_Game;
	};
}
#endif

