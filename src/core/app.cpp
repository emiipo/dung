#include "app.h"
#include <iostream>
#include <cstdlib>

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

    //Main loop
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        const int tilesize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Set render draw color to black
        SDL_RenderClear(mainRenderer); // Clear the renderer

        SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);  /* white, full alpha */
        for(int x = 0; x < kScreenWidth/tilesize; x++){
            for(int y = 0; y < kScreenHeight/tilesize; y++){
                int val = rand() % 101;
                if(val > 91){
                    SDL_RenderDebugText(mainRenderer, tilesize*x, tilesize*y, "#");
                }
                else if (val > 50){
                    SDL_RenderDebugText(mainRenderer, tilesize*x, tilesize*y, ".");
                }
            }
        }
        
        SDL_RenderPresent(mainRenderer); // Render the screen
    }
}