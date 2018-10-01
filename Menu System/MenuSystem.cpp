#include "MenuSystem.h"


using namespace std;

template<class T>
MenuSystem<T>::MenuSystem()
{
}

template<class T>
MenuSystem<T>::~MenuSystem()
{
}

//struct menuItem
//{
//	string name;
//	bool is_subMenu;
//	string subMenuPath;
//};

template<class T>
void MenuSystem<T>::LoadMenuItem(string fileName)
{
	string filePath = "../Resources/" + fileName;
	ifstream mnuIn;
	mnuIn.open(filePath, ios::in);

	if (!mnuIn)
		cout << "Unable to open file: " << fileName << endl;
	else
	{
		cout << "File opened successfully!" << endl;
	}

}
