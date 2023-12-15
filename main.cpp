#include <iostream>
#include <map>
#include "demo.h"
 
using namespace std;
using namespace Demo;

static const char* defaultDemoName = "helloworld";

IDemo * Parse(int argc, char **argv) {
    const char *demoName = defaultDemoName;
    if (argc > 1) {
        demoName = argv[1];
    }

    IDemo *demo = Find(demoName);
    if (demo != NULL) {
        return demo;
    }
    else {
        cerr << "[ERROR] invalid demo name `" << demoName << "`, use default demo `" << defaultDemoName << "`\n";
    }

    return Find(defaultDemoName);
}

int main(int argc, char **argv) {
    Initialize();
    Run(Parse(argc, argv));
    Shutdown();

    return 0;
}
