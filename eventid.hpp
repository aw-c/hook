#define MaxHooks 5
#define AutoCheck

typedef void (*func)();

namespace hook
{
	void Add(const char* name, func callback);
	void Run(const char* name);

	struct HInfo
	{
		int LINum;
		const char* name;
		func* callback;
		HInfo(const char* _name, func* _callback);
		~HInfo();
	};
}
