#include "app.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

unsigned char  hash[] = {
	208,34,231,213,32,248,233,56,161,78,24,140,71,48,140,254,245,255,247,247,40,
	185,248,251,245,28,124,204,204,76,36,1,107,28,234,163,202,224,245,128,167,204,
	9,92,217,54,239,174,173,102,193,189,190,121,100,108,167,44,43,77,180,204,8,81,
	70,223,11,38,24,254,210,210,177,32,81,195,243,125,8,169,112,32,97,53,195,13,
	203,9,47,104,125,117,114,124,165,203,181,235,193,206,70,180,174,0,167,181,41,
	164,30,116,127,198,245,146,87,224,149,206,57,4,192,210,65,210,129,240,178,105,
	228,108,245,148,140,40,35,195,38,58,65,207,215,253,65,85,208,76,62,3,237,55,89,
	232,50,217,64,244,157,199,121,252,90,17,212,203,149,152,140,187,234,177,73,174,
	193,100,192,143,97,53,145,135,19,103,13,90,135,151,199,91,239,247,33,39,145,
	101,120,99,3,186,86,99,41,237,203,111,79,220,135,158,42,30,154,120,67,87,167,
	135,176,183,191,253,115,184,21,233,58,129,233,142,39,128,211,118,137,139,255,
	114,20,218,113,154,27,127,246,250,1,8,198,250,209,92,222,173,21,88,102,219
};

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
                float val = GenerateNoise(x, y);
                std::cout << val << std::endl;
                if(val > 0){
                    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
                    SDL_RenderDebugTextFormat(mainRenderer, tilesize*x, tilesize*y, "#");
                }
                //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x, tilesize*y, "%i", TestNoise(x, y));
            }
        }
        
        SDL_RenderPresent(mainRenderer); // Render the screen
    }
}

std::vector<float> Application::GetGradient(int x, int y){
    //Redo this later for better gradient gen
    int tmp = hash[(hash[y % 256] + x) % 256];

    //technically this is not gonna work proiperly but im just gonna sin and cos this, problem is it goes up to 256 which is not a full 360
    return {(float)std::sin(tmp), (float)std::cos(tmp)};
}

float Application::GenerateNoise(float x, float y){
    int x0 = (int)x;
    int y0 = (int)y;
    int x1 = x0++;
    int y1 = y1++;

    float wx = x - (float)x0;
    float wy = y - (float)y0;

    float topLeft = DotGridGradient(x0, y0, x, y);
    float topRight = DotGridGradient(x1, y0, x, y);
    float bottomLeft = DotGridGradient(x0, y1, x, y);
    float bottomRight = DotGridGradient(x1, y1, x, y);

    float top = Interpolate(topLeft, topRight, wx);
    float bottom = Interpolate(bottomLeft, bottomRight, wx);
    float average = Interpolate(top, bottom, wy);

    return average;
}

float Application::DotGridGradient(int gx, int gy, float x, float y){
    std::vector<float> gradient = GetGradient(gx, gy);

    float dx = x - (float)gx;
    float dy = y - (float)gy;

    return (dx * gradient[0] + dy * gradient[1]);
}

float Application::Interpolate(float a, float b, float w){
    return a + w * (b - a);
}