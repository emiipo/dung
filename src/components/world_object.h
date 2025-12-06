#pragma once
#include "game_object.h"
#include "transform.h"
#include "renderer.h"
#include "collider.h"

class WorldObject : public GameObject {
public:
    WorldObject(bool initRenderer = true, bool initCollider = true);

    Transform* transform{ nullptr };
    Renderer* renderer{ nullptr };
    Collider* collider{ nullptr };
};