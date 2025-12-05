#pragma once
#include <SDL3/SDL.h>
#include "../input/input_manager.h"

class SDLEventManager{
public:
    SDLEventManager();

    void HandleSDLEvents();
    void SetInputManager(InputManager* im);
private:
    SDL_Event sdlEvent;

    InputManager* inputManager{ nullptr };
};
