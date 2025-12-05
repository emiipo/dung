#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "../rendering/render_manager.h"


class Application {
public:
    Application();
    ~Application();

    void Run();

private:
    int kScreenWidth{ 640 };
    int kScreenHeight{ 480 };

    SDL_Window* mainWindow{ nullptr };
    RenderManager* renderManager{ nullptr };
};