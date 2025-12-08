#pragma once
#include "component.h"
#include <SDL3/SDL.h>
#include "../util/common.h"

class Transform;

class Collider : public Component {
public:
    Collider(float width = tilesize, float height = tilesize, float offsetX = 0, float offsetY = 0);

    void Init() override;

    Vector4 GetBounds() const;
    Vector2 GetPosition() const;
    Vector2 GetOffset() const;
    Vector2 GetSize() const;

private:
    Transform* mTransform{ nullptr };

    Vector2 mOffset;
    Vector2 mSize;
};