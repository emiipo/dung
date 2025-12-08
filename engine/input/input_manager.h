#pragma once
#include <SDL3/SDL.h>
#include <functional>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include "../events/event.h"

// TODO: When events are remade make sure this follows as we cant remove as of now

class InputManager {
public:
    void HandleInputEvent(SDL_Event& inputEvent);

    void CreateBinding(const std::string& bindingName, SDL_Keycode key = SDLK_UNKNOWN);
    void CreateBinding(const std::string& bindingName, const std::vector<SDL_Keycode>& keys);
    void AddKeyToBinding(const std::string& bindingName, SDL_Keycode key);
    void AddKeysToBinding(const std::string& bindingName, const std::vector<SDL_Keycode>& keys);
    void AddKeyDownListenerToBinding(const std::string& bindingName, std::function<void()> callback);
    void AddKeyUpListenerToBinding(const std::string& bindingName, std::function<void()> callback);

    void RemoveBinding(const std::string& bindingName);
    void RemoveKeyFromBinding(const std::string& bindingName, SDL_Keycode key);
    void RemoveKeysFromBinding(const std::string& bindingName, const std::vector<SDL_Keycode>& keys);
    // Later add remove listeners

    // for now this should work, but what if binding has several keys? maybe only allow one, think abt it ig
    void RebindKey(const std::string& bindingName, SDL_Keycode oldKey, SDL_Keycode newKey);

private:
    struct InputBinding{
        std::string name;
        std::vector<SDL_Keycode> keys;
        Event OnKeyDown;
        Event OnKeyUp;
    };

    std::list<std::unique_ptr<InputBinding>> mInputBindings;
    std::unordered_map<SDL_Keycode, std::list<InputBinding*>> mKeyToBindingMap;
    std::unordered_map<std::string, InputBinding*> mNameToBindingMap;
};