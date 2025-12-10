#pragma once
#include "component.h"
#include "../util/common.h"

struct Vector2;

class Transform : public Component {
public:
    Transform(float x = 0, float y = 0);

    void SetPosition(Vector2 newPosition);
    void AddPosition(Vector2 additionalPosition);

    Vector2 position;
};