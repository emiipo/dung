#include "game_object.h"

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::TestObj(){
    for(Component* comp : mComponents){
        std::cout << comp->id << std::endl;
    }
}