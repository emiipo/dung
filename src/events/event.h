#pragma once
#include <list>
#include <functional>

// TODO: Using std::function for now, move it to delegates later

class Event{
public:
    void Invoke();

    void AddListener(std::function<void()> listener);
    //void RemoveListener(void (*listener)());
private:
    std::list<std::function<void()>> listeners;
};