#include "input_manager.h"
#include <algorithm>

void InputManager::HandleInputEvent(SDL_Event& inputEvent) {
    if(inputEvent.type == SDL_EVENT_KEY_DOWN){
        if(mKeyToBindingMap.find(inputEvent.key.key) != mKeyToBindingMap.end()){
            for (InputBinding* binding : mKeyToBindingMap[inputEvent.key.key]){
                binding->OnKeyDown.Invoke();
            }
        }
    }
    else if(inputEvent.type == SDL_EVENT_KEY_UP){
        if(mKeyToBindingMap.find(inputEvent.key.key) != mKeyToBindingMap.end()){
            for (InputBinding* binding : mKeyToBindingMap[inputEvent.key.key]){
                binding->OnKeyUp.Invoke();
            }
        }
    }
}

void InputManager::CreateBinding(const std::string& bindingName, SDL_Keycode key) {
    if(key != SDLK_UNKNOWN){
        CreateBinding(bindingName, std::vector<SDL_Keycode> {key});
    }
    else{
        CreateBinding(bindingName, std::vector<SDL_Keycode> {});
    }
}

void InputManager::CreateBinding(const std::string& bindingName, const std::vector<SDL_Keycode>& keys) {
    if(mNameToBindingMap.find(bindingName) != mNameToBindingMap.end()){ return; }

    std::unique_ptr<InputBinding> newBinding = std::make_unique<InputBinding>();
    InputBinding* bindingPtr = newBinding.get();

    newBinding->name = bindingName;
    mNameToBindingMap[bindingName] = bindingPtr;
    //Initially was adding them here manually, but wanted to reuse code + if the vector provides several of same key i would have to do extra logic
    // to make sure there are no duplicated when the function already takes care of that.
    AddKeysToBinding(bindingName, keys);

    mInputBindings.push_back(std::move(newBinding));
}

void InputManager::AddKeyToBinding(const std::string& bindingName, SDL_Keycode key) {
    AddKeysToBinding(bindingName, {key});
}

void InputManager::AddKeysToBinding(const std::string& bindingName, const std::vector<SDL_Keycode>& keys) {
    if(mNameToBindingMap.find(bindingName) == mNameToBindingMap.end()){ return; }

    InputBinding* binding = mNameToBindingMap[bindingName];
    for(SDL_Keycode key : keys){
        if(std::find(binding->keys.begin(), binding->keys.end(), key) == binding->keys.end()){
            binding->keys.push_back(key);
            mKeyToBindingMap[key].push_back(binding);
        }
    }
}

void InputManager::AddKeyDownListenerToBinding(const std::string& bindingName, std::function<void()> callback) {
    if(mNameToBindingMap.find(bindingName) == mNameToBindingMap.end()){ return; }

    mNameToBindingMap[bindingName]->OnKeyDown.AddListener(callback);
}

void InputManager::AddKeyUpListenerToBinding(const std::string& bindingName, std::function<void()> callback) {
    if(mNameToBindingMap.find(bindingName) == mNameToBindingMap.end()){ return; }

    mNameToBindingMap[bindingName]->OnKeyUp.AddListener(callback);
}

void InputManager::RemoveBinding(const std::string& bindingName) {
    if(mNameToBindingMap.find(bindingName) == mNameToBindingMap.end()){ return; }

    InputBinding* binding = mNameToBindingMap[bindingName];
    // Not using remove function here because in this case we can just completely erase the unique_ptr
    for(SDL_Keycode key : binding->keys){
        mKeyToBindingMap[key].remove(binding);
        if(mKeyToBindingMap[key].empty()){
            mKeyToBindingMap.erase(key);
        }
    }
    mNameToBindingMap.erase(bindingName);

    mInputBindings.remove_if([binding](const std::unique_ptr<InputBinding>& bindingPtr){ return bindingPtr.get() == binding; });
}

void InputManager::RemoveKeyFromBinding(const std::string& bindingName, SDL_Keycode key) {
    RemoveKeysFromBinding(bindingName, {key});
}

void InputManager::RemoveKeysFromBinding(const std::string& bindingName, const std::vector<SDL_Keycode>& keys) {
    if(mNameToBindingMap.find(bindingName) == mNameToBindingMap.end()){ return; }

    InputBinding* binding = mNameToBindingMap[bindingName];
    for(SDL_Keycode key : keys){
        auto it = std::find(binding->keys.begin(), binding->keys.end(), key);
        if(it != binding->keys.end()){
            binding->keys.erase(it);
            mKeyToBindingMap[key].remove(binding);
            if(mKeyToBindingMap[key].empty()){
                mKeyToBindingMap.erase(key);
            }
        }
    }
}

void InputManager::RebindKey(const std::string& bindingName, SDL_Keycode oldKey, SDL_Keycode newKey) {
    if(mNameToBindingMap.find(bindingName) == mNameToBindingMap.end()){ return; }

    InputBinding* binding = mNameToBindingMap[bindingName];
    auto it = std::find(binding->keys.begin(), binding->keys.end(), oldKey);
    if(it != binding->keys.end()){
        *it = newKey;

        mKeyToBindingMap[oldKey].remove(binding);
        if(mKeyToBindingMap[oldKey].empty()){
            mKeyToBindingMap.erase(oldKey);
        }
        mKeyToBindingMap[newKey].push_back(binding);
    }
}