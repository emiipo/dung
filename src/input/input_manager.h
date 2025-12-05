#pragma once
#include <SDL3/SDL.h>

class InputManager {
public:
    void HandleInputEvent(SDL_Event& inputEvent);
};