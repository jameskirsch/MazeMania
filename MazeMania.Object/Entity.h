

#pragma once

namespace MazeManiaObject
{

	// Generic Class for many objects to inherit off of.
	class __declspec(dllexport) Entity{

	public:

		void SetId(int id);
		
		int GetId();

	protected:

		int m_Id;
	};


	/// Grid Class - Used to any Entities on Map
	class __declspec(dllexport) Grid{

	public:

		void SetId(int id);
		int GetId();

	protected:

		int m_Id;
	};
}






