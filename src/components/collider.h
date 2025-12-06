#pragma once
#include "component.h"
#include <SDL3/SDL.h>
#include "../util/common.h"

class Collider : public Component {
public:
    Collider(float width = tilesize, float height = tilesize);

    // Maybe make my own as i only need width and height, transform would drive the position
    SDL_FRect bounds;
};