#pragma once
#include <SDL3/SDL.h>
#include "component.h"
#include "../util/common.h"

class Transform;

// For now this will be default renderer, eventually extend into ascii/texture etc
class Renderer : public Component {
public:
    Renderer(char defaultChar = '#', SDL_Color defaultColor = {255, 255, 255, 255});

    void Init() override;

    void SetRenderCharacter(char c);
    const char GetRenderCharacter();

    void SetRenderColor(SDL_Color color);
    const SDL_Color GetRenderColor();

    Vector4 GetBounds();
    Vector2 GetPosition();
    Vector2 GetSize();

private:
    Transform* mTransform{ nullptr };

    Vector2 mSize;

    char mRenderChar;
    SDL_Color mRenderColor;
};