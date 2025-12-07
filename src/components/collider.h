#pragma once
#include "component.h"
#include <SDL3/SDL.h>
#include "../util/common.h"

class Transform;

class Collider : public Component {
public:
    Collider(float width = tilesize, float height = tilesize, float offsetX = 0, float offsetY = 0);

    void Init() override;

    Vector4 GetBounds();
    Vector2 GetPosition();
    Vector2 GetOffset();
    Vector2 GetSize();

private:
    Transform* mTransform{ nullptr };

    Vector2 mOffset;
    Vector2 mSize;
};