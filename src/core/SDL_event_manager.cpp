#include "SDL_event_manager.h"

SDLEventManager::SDLEventManager() {
    SDL_zero(sdlEvent);
}

void SDLEventManager::SetInputManager(InputManager* im) {
    inputManager = im;
}

void SDLEventManager::HandleSDLEvents() {
    while (SDL_PollEvent(&sdlEvent)) {
        if (sdlEvent.type == SDL_EVENT_QUIT) {
            //Setup quit event
        }
        else if(sdlEvent.type == SDL_EVENT_KEY_DOWN || sdlEvent.type == SDL_EVENT_KEY_UP){
            inputManager->HandleInputEvent(sdlEvent);
        }
    }
}