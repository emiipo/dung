#include "world_object.h"
#include "transform.h"

WorldObject::WorldObject(){
    transform = AddComponent<Transform>();
}

void WorldObject::Render(float offsetX, float offsetY){
    // Empty for now
}