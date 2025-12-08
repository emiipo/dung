#include "event.h"

void Event::Invoke() {
    for(std::function<void()> listener : listeners){
        listener();
    }
}

void Event::AddListener(std::function<void()> listener) {
    listeners.push_back(listener);
}