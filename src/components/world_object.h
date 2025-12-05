#pragma once
#include "game_object.h"
#include "transform.h"

class WorldObject : public GameObject {
public:
    WorldObject();
    ~WorldObject();

    virtual void Render(float offsetX, float offsetY);

    Transform* transform;
};