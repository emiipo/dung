#include "component.h"
#include <iostream>

Component::Component(){

}

Component::~Component(){
    
}

void Component::TestComp(){
    std::cout << "ID: " << id << std::endl;
}