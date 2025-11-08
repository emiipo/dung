#include "app.h"
#include <iostream>

Application::Application() {
    SDL_Init(SDL_INIT_VIDEO);

    mainWindow = SDL_CreateWindow("dung", kScreenWidth, kScreenHeight, 0);
    if (mainWindow == nullptr) {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    mainRenderer = SDL_CreateRenderer(mainWindow, NULL);
    if (mainRenderer == nullptr) {
        SDL_Log("SSDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(mainWindow);
        mainWindow = nullptr;
        SDL_Quit();
        return;
    }
}

Application::~Application() {
    SDL_DestroyRenderer(mainRenderer);
    mainRenderer = nullptr;
    SDL_DestroyWindow(mainWindow);
    mainWindow = nullptr;
    SDL_Quit();
}

void Application::Run(){
    //Final exit code
    int exitCode{ 0 };

    bool quit = false;
    SDL_Event e;
    SDL_zero(e);

    // Define a rectangle - still keeping for now but remove soon, just for debug
    SDL_FRect square {270, 190, 100, 100};

    //Main loop
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(mainRenderer); // Clear the renderer

        SDL_SetRenderDrawColor(mainRenderer, 255, 192, 203, 255); // Set render draw color to green
        SDL_RenderFillRect(mainRenderer, &square); // Render the rectangle
        
        SDL_RenderPresent(mainRenderer); // Render the screen
    }
}