#ifndef __DEMO_H__
#define __DEMO_H__

namespace Demo {
	class IDemo {
	public:
		virtual ~IDemo() {}
		
		virtual const char *	Name() = 0;
		virtual int				Initialize() = 0;
		virtual int				Run() = 0;
		virtual int				Shutdown() = 0;
	};

	void Initialize();
	void Shutdown();
	void Run(IDemo* demo);
	IDemo* Find(const char* name);
}

#endif