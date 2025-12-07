#pragma once
#include <SDL3/SDL.h>
#include "component.h"
#include "../util/common.h"

// For now this will be default renderer, eventually extend into ascii/texture etc
class Renderer : public Component {
public:
    Renderer(char defaultChar = '#', SDL_Color defaultColor = {255, 255, 255, 255});

    void SetRenderCharacter(char c);
    const char GetRenderCharacter();

    void SetRenderColor(SDL_Color color);
    const SDL_Color GetRenderColor();

    Vector2 GetDimensions();

private:
    float mWidth;
    float mHeight;

    char renderChar;
    SDL_Color renderColor;
};