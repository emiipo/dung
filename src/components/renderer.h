#pragma once
#include <SDL3/SDL.h>
#include "component.h"
#include "../util/common.h"

class Transform;
class Component;

// For now this will be default renderer, eventually extend into ascii/texture etc
class Renderer : public Component {
public:
    Renderer(char defaultChar = '#', SDL_Color defaultColor = {255, 255, 255, 255});

    void Init() override;

    void SetRenderCharacter(char c);
    char GetRenderCharacter() const;

    void SetRenderColor(SDL_Color color);
    const SDL_Color GetRenderColor() const;

    Vector4 GetBounds() const;
    Vector2 GetPosition() const;
    Vector2 GetSize() const;

private:
    Transform* mTransform{ nullptr };

    Vector2 mSize;

    char mRenderChar;
    SDL_Color mRenderColor;
};