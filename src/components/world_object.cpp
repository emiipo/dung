#include "world_object.h"
#include "transform.h"

WorldObject::WorldObject(){
    AddComponent<Transform>();
}

WorldObject::~WorldObject(){

}