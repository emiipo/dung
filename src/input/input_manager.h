#pragma once
#include <SDL3/SDL.h>
#include <functional>
#include <unordered_map>
#include <list>
#include <string>
#include "../events/event.h"

// TODO: When events are remade make sure this follows as we cant remove as of now

class InputManager {
public:
    void HandleInputEvent(SDL_Event& inputEvent);
    void AddKeyDownListener(SDL_Keycode key, std::function<void()> callback);

    void CreateBinding(std::string name, SDL_Keycode key = SDLK_UNKNOWN);
    void CreateBinding(std::string name, std::list<SDL_Keycode> keys);

private:
    struct InputBinding{
        std::string name;
        std::list<SDL_Keycode> keys;
        Event OnKeyDown;
        Event OnKeyUp;
    };

    std::list<InputBinding> mInputBindings;
    std::unordered_map<SDL_Keycode, std::list<InputBinding*>> mKeyToBindingMap;
    std::unordered_map<std::string, std::list<InputBinding*>> mNameToBindingMap;
};