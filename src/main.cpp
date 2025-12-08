#include <SDL3/SDL.h>
#include <iostream>
#include <exception>
#include "dung.h"

int main(int argc, char* argv[]) {
    try {
        Dung dung;
        dung.Run();
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}