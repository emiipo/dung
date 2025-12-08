#pragma once
#include "game_object.h"

class Transform;
class Collider;
class Renderer;

class WorldObject : public GameObject {
public:
    WorldObject(bool initRenderer = true, bool initCollider = true);

    Transform* transform{ nullptr };
    Renderer* renderer{ nullptr };
    Collider* collider{ nullptr };
};