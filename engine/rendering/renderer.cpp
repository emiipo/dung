#include "renderer.h"
#include "../components/game_object.h"
#include "../components/transform.h"
#include "../core/app.h"

Renderer::Renderer(char defaultChar, SDL_Color defaultColor){
    mRenderChar = defaultChar;
    mRenderColor = defaultColor;
    mSize.x = tilesize;
    mSize.y = tilesize;
}

//Disable if transform doesnt exist
void Renderer::Init() {
    mTransform = gameObject->GetComponent<Transform>();

    Application::Instance->GetRenderManager().RegisterRenderer(this);
}

void Renderer::SetRenderCharacter(char c){
    mRenderChar = c;
}

char Renderer::GetRenderCharacter() const{
    return mRenderChar;
}

void Renderer::SetRenderColor(SDL_Color color){
    mRenderColor = color;
}

const SDL_Color Renderer::GetRenderColor() const{
    return mRenderColor;
}

Vector4 Renderer::GetBounds() const{
    if(!mTransform) return {0,0,0,0};
    return {mTransform->position.x, mTransform->position.y, mSize.x, mSize.y};
}

Vector2 Renderer::GetPosition() const{
    if(!mTransform) return {0,0};
    return {mTransform->position.x, mTransform->position.y};
}

Vector2 Renderer::GetSize() const{
    return {mSize.x, mSize.y};
}