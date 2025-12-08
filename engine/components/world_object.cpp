#include "world_object.h"

WorldObject::WorldObject(bool initRenderer, bool initCollider) {
    transform = AddComponent<Transform>();
    if(initRenderer) renderer = AddComponent<Renderer>();
    if(initCollider) collider = AddComponent<Collider>();
}