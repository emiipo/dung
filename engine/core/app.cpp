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

    physicsManager = new PhysicsManager();
    inputManager = new InputManager();
    sdlEventManager = new SDLEventManager();
    sdlEventManager->SetInputManager(inputManager);
    sdlEventManager->onQuitEvent.AddListener([this]() {this->Quit();});

    renderManager = new RenderManager(mainWindow, true);
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