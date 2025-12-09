#include "dung.h"
#include "level/level_generator.h"
#include "../engine/components/world_object.h"
#include "../engine/rendering/camera.h"

void Dung::Start(){
    // Setup input
    inputManager->CreateBinding("Move Up", {SDLK_UP, SDLK_W});
    inputManager->CreateBinding("Move Down", {SDLK_DOWN, SDLK_S});
    inputManager->CreateBinding("Move Left", {SDLK_LEFT, SDLK_A});
    inputManager->CreateBinding("Move Right", {SDLK_RIGHT, SDLK_D});
    inputManager->AddKeyDownListenerToBinding("Move Up", [this]() {this->MoveUp();});
    inputManager->AddKeyDownListenerToBinding("Move Down", [this]() {this->MoveDown();});
    inputManager->AddKeyDownListenerToBinding("Move Left", [this]() {this->MoveLeft();});
    inputManager->AddKeyDownListenerToBinding("Move Right", [this]() {this->MoveRight();});

    // Setup camera & player
    Camera* cam = new Camera(0,0,kScreenWidth,kScreenHeight);
    renderManager->SetMainCamera(cam);

    WorldObject* player = new WorldObject();
    player->renderer->SetRenderCharacter('@');
    player->renderer->SetRenderColor({255, 182, 193, 255});
    renderManager->AddRenderer(player->renderer);
    cam->SetFollowTarget(player);
    t = player->transform;

    // Generate level
    LevelGenerator gen;
    std::vector<std::vector<float>> map = gen.GenerateLevel(400, 400);

    for(int x = 0; x < 400; x++){
        for(int y = 0; y < 400; y++){
            if(map[y][x] > 1){
                WorldObject* tile = new WorldObject();
                //Uint8 a = (Uint8)((map[x][y] * 0.5f) * 255);
                tile->transform->SetPosition((float)(x * tilesize), (float)(y * tilesize));
                //tile->renderer->SetRenderColor({255, 255, 255, a});
                //tile->renderer->SetRenderCharacter((int)map[y][x]);
                renderManager->AddRenderer(tile->renderer);
                //SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, a);
                //SDL_FRect rect{(float)x,(float)y,1,1};
                //SDL_RenderRect(mainRenderer, &rect);
                //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x - t->position.x, tilesize*y - t->position.y, "%i", (int)map[x][y]);
            }
        }
    }
}

void Dung::Update(){

}

void Dung::MoveUp(){
    if(t) t->SetPosition(t->position.x, t->position.y - tilesize);
}

void Dung::MoveDown(){
    if(t) t->SetPosition(t->position.x, t->position.y + tilesize);
}

void Dung::MoveLeft(){
    if(t) t->SetPosition(t->position.x - tilesize, t->position.y);
}

void Dung::MoveRight(){
    if(t) t->SetPosition(t->position.x + tilesize, t->position.y);
}