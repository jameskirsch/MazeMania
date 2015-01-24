#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

#define EXPORT __declspec(dllexport)

#include "../MazeMania.Object/MazeMania.Object.h"

using namespace MazeManiaObject;
using namespace MazeManiaData;

namespace MazeManiaLogic {

	//The Load Class is meant to load up maps and initialize settings for the game
	class Load {

		public:
			EXPORT Load(Repository &repository);
			EXPORT Load();

		private:

	};

}
#endif

