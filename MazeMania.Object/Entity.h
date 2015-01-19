#include <iostream>
using namespace std;

//#ifndef EXPORTING_OBJ
#define EXPORT_TO_DLL __declspec(dllexport)
//#else
//#define EXPORT_TO_DLL __declspec(dllimport) extern
//#endif

namespace MazeManiaObject {

	class EXPORT_TO_DLL Entity {

	public:
		void SetId(int id);	
		void SetName();

		int GetId();
		string test(string name);
		
	protected:
		int m_Id;
	};
}








