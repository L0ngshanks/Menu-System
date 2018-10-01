#pragma once
#include "DynArray.h"

#include <string>
#include <iostream>
#include <fstream>


template<class T>
class MenuSystem :
	protected DynArray<T>
{
private:
	//string title;
	//DynArray<menuItem> choices;
	//unsigned int currSelection;
public:
	MenuSystem();
	~MenuSystem();

	void LoadMenuItem(string fileName);
};

