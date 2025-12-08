#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "../rendering/render_manager.h"
#include "../input/input_manager.h"
#include "SDL_event_manager.h"
#include "../components/transform.h"


class Application {
public:
    Application();
    ~Application();

    virtual void Start() {};
    virtual void Update() {};

    void Run();
    void Quit();

protected:
    bool quit{ false };

    int kScreenWidth{ 640 };
    int kScreenHeight{ 480 };

    SDL_Window* mainWindow{ nullptr };
    RenderManager* renderManager{ nullptr };
    InputManager* inputManager{ nullptr };
    SDLEventManager* sdlEventManager{ nullptr };
};