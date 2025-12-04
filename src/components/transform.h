#pragma once
#include "component.h"
#include "../util/common.h"

class Transform : public Component {
public:
    Transform(float x = 0, float y = 0);
    ~Transform();

    void SetPosition(float newX, float newY);

    Vector2 position;
};