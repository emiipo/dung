#pragma once
#include <SDL3/SDL.h>
#include <functional>
#include <unordered_map>
#include <list>
#include "../events/event.h"

// TODO: When events are remade make sure this follows as we cant remove as of now

class InputManager {
public:
    void HandleInputEvent(SDL_Event& inputEvent);
    void AddKeyDownListener(SDL_Keycode key, std::function<void()> callback);

private:
    std::unordered_map<SDL_Keycode, Event> keyDownEvents;
};