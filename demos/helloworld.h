#ifndef __HELLO_WORLD__
#define __HELLO_WORLD__

#include "../demo.h"

namespace Demo {
	class HelloWorld : public IDemo {
	public:
		inline const char*	Name() { return "helloworld"; }
		inline int			Initialize() { return 0; }
		int					Run();
		inline int			Shutdown() { return 0; }
	};
}

#endif
