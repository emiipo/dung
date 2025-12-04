#pragma once
#include <list>
#include <iostream>
#include <typeinfo>
#include <memory>
#include "component.h"

class GameObject {
public:
    GameObject();
    ~GameObject();

    template <class T>
    T* AddComponent(){
        std::unique_ptr<T> newComponent = std::make_unique<T>();
        mComponents.push_back(std::move(newComponent));
        return newComponent.get();
    }

    template <class T>
    T* GetComponent(){
        const std::type_info& type = typeid(T);
        for(const std::unique_ptr<Component>& comp : mComponents){
            if(typeid(*comp.get()) == type) return static_cast<T*>(comp.get());
        }
        return nullptr;
    }

private:
    std::list<std::unique_ptr<Component>> mComponents;
};