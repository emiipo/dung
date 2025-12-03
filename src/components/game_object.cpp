#include "game_object.h"

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::TestObj(){
    for(const std::unique_ptr<Component>& comp : mComponents){
        comp->TestComp();
    }
}