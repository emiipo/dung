#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "../rendering/render_manager.h"
#include "../physics/physics_manager.h"
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

    int kScreenWidth{ 1280 };
    int kScreenHeight{ 720 };

    // Make these into unique_ptr?
    SDL_Window* mainWindow{ nullptr };
    RenderManager* renderManager{ nullptr };
    PhysicsManager* physicsManager{ nullptr };
    InputManager* inputManager{ nullptr };
    SDLEventManager* sdlEventManager{ nullptr };

    // Adding for later use
    std::vector<std::unique_ptr<GameObject>> mGameObjects;
};