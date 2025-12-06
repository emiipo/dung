#pragma once
#include <SDL3/SDL.h>
#include "../input/input_manager.h"
#include "../events/event.h"

class SDLEventManager{
public:
    Event onQuitEvent;

    SDLEventManager();

    void HandleSDLEvents();
    void SetInputManager(InputManager* im);
private:
    SDL_Event sdlEvent;

    InputManager* inputManager{ nullptr };
};
