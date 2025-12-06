#include "input_manager.h"

void InputManager::HandleInputEvent(SDL_Event& inputEvent) {
    if(inputEvent.type == SDL_EVENT_KEY_DOWN){
        if(keyDownEvents.find(inputEvent.key.key) != keyDownEvents.end()){
            keyDownEvents[inputEvent.key.key].Invoke();
        }
    }
    else if(inputEvent.type == SDL_EVENT_KEY_UP){

    }
}

void InputManager::AddKeyDownListener(SDL_Keycode key, std::function<void()> callback) {
    keyDownEvents[key].AddListener(callback);
}