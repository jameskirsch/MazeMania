

#pragma once

namespace MazeManiaObject
{
	class __declspec(dllexport) Entity{

	public:

		void SetId(int id);
		
		int GetId();

	protected:

		int m_Id;
	};
}






