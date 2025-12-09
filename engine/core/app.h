#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <memory>
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

    // Maybe add a getter but for now this works
    static Application* Instance;

    RenderManager& GetRenderManager();
    PhysicsManager& GetPhysicsManager();
    InputManager& GetInputManager();

protected:
    bool quit{ false };

    int kScreenWidth{ 1280 };
    int kScreenHeight{ 720 };

    // Later make this into a unique ptr maybe too? for now keeping it like this but i dont think we need raw ptr
    SDL_Window* mainWindow{ nullptr };
    std::unique_ptr<RenderManager> renderManager{ nullptr };
    std::unique_ptr<PhysicsManager> physicsManager{ nullptr };
    std::unique_ptr<InputManager> inputManager{ nullptr };
    std::unique_ptr<SDLEventManager> sdlEventManager{ nullptr };

    // Adding for later use
    std::vector<std::unique_ptr<GameObject>> mGameObjects;
};