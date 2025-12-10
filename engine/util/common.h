#pragma once
#include <SDL3/SDL.h>

const int tilesize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;

struct Vector2{
    float x, y;

    Vector2 operator+(Vector2 other) const{
        return {x+other.x, y+other.y};
    }

    Vector2 operator-(Vector2 other) const{
        return {x-other.x, y-other.y};
    }

    bool operator==(Vector2 other) const{
        return (x == other.x && y == other.y);
    }

    bool operator!=(Vector2 other) const{
        return !(x == other.x && y == other.y);
    }
};

struct Vector3{
    float x, y, z;

    Vector3 operator+(Vector3 other) const{
        return {x+other.x, y+other.y, z+other.z};
    }

    Vector3 operator-(Vector3 other) const{
        return {x-other.x, y-other.y, z-other.z};
    }

    bool operator==(Vector3 other) const{
        return (x == other.x && y == other.y && z == other.z);
    }

    bool operator!=(Vector3 other) const{
        return !(x == other.x && y == other.y && z == other.z);
    }
};

struct Vector4{
    float x, y, z, w;

    Vector4 operator+(Vector4 other) const{
        return {x+other.x, y+other.y, z+other.z, w+other.w};
    }

    Vector4 operator-(Vector4 other) const{
        return {x-other.x, y-other.y, z-other.z, w-other.w};
    }

    bool operator==(Vector4 other) const{
        return (x == other.x && y == other.y && z == other.z && w == other.w);
    }

    bool operator!=(Vector4 other) const{
        return !(x == other.x && y == other.y && z == other.z && w == other.w);
    }
};