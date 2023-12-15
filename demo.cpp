#include <iostream>
#include <map>
#include "demo.h"

#include "demos/helloworld.h"

using namespace std;

namespace Demo {
    typedef struct nameCompare {
        bool operator() (const char* a, const char* b) const {
            return strcmp(a, b) < 0;
        }
    }nameCompare_t;

    map<const char*, IDemo*, nameCompare_t> demos;

    void AddDemo(IDemo* demo) {
        if (demo == NULL) {
            cerr << "[ERROR] demo is nil!\n";
            return;
        }

        if (demos.find(demo->Name()) != demos.end()) {
            cerr << "[ERROR] demo " << demo->Name() << " is existed!\n";
            return;
        }

        demos[demo->Name()] = demo;
    }

    void Initialize() {
        AddDemo(new HelloWorld());
    }

    void Shutdown() {
        for (map<const char*, IDemo*>::iterator it = demos.begin(); it != demos.end(); it++) {
            delete it->second;
        }

        demos.clear();
    }

    IDemo* Find(const char* name) {
        map<const char*, IDemo*>::iterator itDemo = demos.find(name);
        if (itDemo != demos.end()) {
            return itDemo->second;
        }

        return NULL;
    }

    void Run(IDemo* demo) {
        demo->Initialize();
        demo->Run();
        demo->Shutdown();
    }
}