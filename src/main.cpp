#include <SDL3/SDL.h>
#include <iostream>
#include <exception>
#include "core/app.h"

int main(int argc, char* argv[]) {
    try {
        Application app;
        app.Run();
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}