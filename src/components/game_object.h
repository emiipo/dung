#pragma once
#include <list>
#include <iostream>
#include <typeinfo>
#include <memory>
#include "component.h"

class GameObject {
public:
    template <class T>
    T* AddComponent(){
        std::unique_ptr<T> newComponent = std::make_unique<T>();
        newComponent->mCreator = this;
        T* ptr = newComponent.get();
        mComponents.push_back(std::move(newComponent));
        return ptr;
    }

    template <class T>
    T* GetComponent(){
        const std::type_info& type = typeid(T);
        for(const std::unique_ptr<Component>& comp : mComponents){
            if(typeid(comp.get()) == type) return static_cast<T*>(comp.get());
        }
        return nullptr;
    }

private:
    std::list<std::unique_ptr<Component>> mComponents;
};