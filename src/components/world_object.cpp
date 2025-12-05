#include "world_object.h"
#include "transform.h"

WorldObject::WorldObject(){
    transform = AddComponent<Transform>();
}

WorldObject::~WorldObject(){

}

void WorldObject::Render(float offsetX, float offsetY){

}