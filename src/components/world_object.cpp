#include "world_object.h"
#include "transform.h"

WorldObject::WorldObject(bool initRenderer){
    transform = AddComponent<Transform>();
    if(initRenderer) renderer = AddComponent<Renderer>();
}