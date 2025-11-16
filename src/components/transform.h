#pragma once
#include "component.h"

class Transform : public Component {
public:
    Transform(float x = 0, float y = 0);
    ~Transform();

    void SetPosition(float newX, float newY);

private:
    float x;
    float y;
};