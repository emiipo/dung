#pragma once
#include "component.h"

// For now this will be default renderer, eventually extend into ascii/texture etc
class Renderer : public Component {
public:
    Renderer(char defaultChar = '#');

    void SetRenderCharacter(char c);
    const char GetRenderCharacter();

private:
    char renderChar;
};