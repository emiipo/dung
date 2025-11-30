#pragma once
#include <list>
#include <iostream>
#include <typeinfo>
#include "component.h"

class GameObject {
public:
    GameObject();
    ~GameObject();

    void TestObj();

    template <class T>
    T* AddComponent(){
        //Make sure it's of component type and that only one exists(hmm not necessarily always tho)
        T* newComponent;
        mComponents.push_back(newComponent);
        TestObj();
        return newComponent;
    }

    template <class T>
    T* GetComponent(){
        const std::type_info& type = typeid(T);

        for(Component* comp : mComponents){
            if(typeid(*comp) == type) return static_cast<T*>(comp);
        }
        return nullptr;
    }

private:
    std::list<Component*> mComponents;
};