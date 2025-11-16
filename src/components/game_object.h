#pragma once
#include <list>
#include <iostream>
#include "component.h"

class GameObject {
public:
    GameObject();
    ~GameObject();

    template <class T>
    T AddComponent(){
        //Make sure it's of component type and that only one exists(hmm not necessarily always tho)
        T newComponent;
        mComponents.push_back(newComponent);
        for(Component comp : mComponents){
            std::cout << comp.id << std::endl;
        }
        return newComponent;
    }

    /*template <class T>
    T GetComponent(){
        for(Component comp : mComponents){
            if(comp)
        }
        return nullptr;
    }*/

private:
    std::list<Component> mComponents;
};