#include "renderer.h"

Renderer::Renderer(char defaultChar, SDL_Color defaultColor){
    renderChar = defaultChar;
    renderColor = defaultColor;
    mWidth = tilesize;
    mHeight = tilesize;
}

void Renderer::SetRenderCharacter(char c){
    renderChar = c;
}

const char Renderer::GetRenderCharacter(){
    return renderChar;
}

void Renderer::SetRenderColor(SDL_Color color){
    renderColor = color;
}

const SDL_Color Renderer::GetRenderColor(){
    return renderColor;
}

Vector2 Renderer::GetDimensions(){
    return {mWidth, mHeight};
}