#include "app.h"
#include "../rendering/camera.h"
#include "../components/world_object.h"
#include "../util/common.h"
#include <iostream>

Application::Application() {
    SDL_Init(SDL_INIT_VIDEO);

    mainWindow = SDL_CreateWindow("dung", kScreenWidth, kScreenHeight, 0);
    if (mainWindow == nullptr) {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    physicsManager = std::make_unique<PhysicsManager>();
    inputManager = std::make_unique<InputManager>();
    sdlEventManager = std::make_unique<SDLEventManager>();
    renderManager = std::make_unique<RenderManager>(mainWindow, true);

    sdlEventManager->SetInputManager(inputManager.get());
    sdlEventManager->onQuitEvent.AddListener([this]() {this->Quit();});
}

Application::~Application() {
    SDL_DestroyWindow(mainWindow);
    mainWindow = nullptr;
    SDL_Quit();
}

void Application::Run(){
    Start();

    //Main loop
    while (!quit) {
        sdlEventManager->HandleSDLEvents();
        physicsManager->HandlePhysics(); // This one is super vague but just main entry point, probably would want to put it in its own loop
        Update();
        renderManager->Render();
    }
}

void Application::Quit(){
    quit = true;
}