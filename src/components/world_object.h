#pragma once
#include "game_object.h"
#include "transform.h"
#include "renderer.h"

class WorldObject : public GameObject {
public:
    WorldObject(bool initRenderer = true);

    Transform* transform{ nullptr };
    Renderer* renderer{ nullptr };
};