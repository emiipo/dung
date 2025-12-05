#include "renderer.h"

Renderer::Renderer(char defaultChar, SDL_Color defaultColor){
    renderChar = defaultChar;
    renderColor = defaultColor;
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