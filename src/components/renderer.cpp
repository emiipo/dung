#include "renderer.h"

Renderer::Renderer(char defaultChar){
    renderChar = defaultChar;
}

void Renderer::SetRenderCharacter(char c){
    renderChar = c;
}

const char Renderer::GetRenderCharacter(){
    return renderChar;
}