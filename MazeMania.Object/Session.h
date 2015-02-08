// The Session Class:
// - Is-a Entity
// - Has-a Level
// - Has-a Collection of Players
// - Is used by the Game Class. Game Class Has-a Session.
// - Purpose: Gather Player Information before Level Generation.

#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include "Level.h"
#include "Entity.h"
#include "Player.h"

#define EXPORT __declspec(dllexport)

namespace MazeManiaObject {

	class Session : Entity {
	
	public:
		EXPORT Session();

		EXPORT inline Level& GetLevel() { return *m_Level; }
		EXPORT inline std::vector<Player>& GetPlayers() { return *m_Players; }
		
	private:
		std::unique_ptr<Level> m_Level;
		std::unique_ptr<std::vector<Player>> m_Players;	
	};
}
#endif

