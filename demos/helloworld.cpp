#include <iostream>
#include "helloworld.h"

using namespace std;

namespace Demo {
	int HelloWorld::Run() {
		cout << "[DEMO] hello world!" << endl;
		return 0;
	}
}