#include <iostream>

#include "kosSyst.h"

int getexepath(char *exepath);

int main()
{
    auto result = getexepath(kosExePath);
    if (result < 0) {
        std::clog << "Can't get module path. Exit\n";
        return 1;
    }

    std::clog << "Module path: " << kosExePath << std::endl;

    initGraph();
    kos_Main();
    deinitGraph();
}

