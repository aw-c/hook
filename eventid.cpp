#include "eventid.hpp"

int LIHook;
hook::HInfo* _Hooks[MaxHooks];

void hook::Add(const char* name,func callback)
{
	_Hooks[LIHook] = new hook::HInfo(name, &callback);
	LIHook++;
}

void hook::Run(const char* name)
{
	for (int i = 0; i < MaxHooks; i++)
	{
		HInfo* cHook = _Hooks[i];

		#ifdef AutoCheck
		if (cHook)
		#endif
			(*cHook->callback)();

			
	}
}

hook::HInfo::HInfo(const char* _name, func* _callback)
{
	name = _name;
	callback = _callback;
	LINum = LIHook;
}

hook::HInfo::~HInfo()
{
	_Hooks[LINum] = nullptr;
}