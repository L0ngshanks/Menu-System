#pragma once
#include "DynArray.h"

template<class T>
class MenuSystem :
	protected DynArray<T>
{
public:
	MenuSystem();
	~MenuSystem();
};

