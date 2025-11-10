#pragma once
#include <SDL3/SDL.h>
#include <vector>


class Application {
public:
    Application();
    ~Application();

    void Run();

private:
    int kScreenWidth{ 640 };
    int kScreenHeight{ 480 };

    SDL_Window* mainWindow{ nullptr };
    SDL_Renderer* mainRenderer{ nullptr };

    std::vector<float> GetGradient(int x, int y);
    float GenerateNoise(float x, float y);
    float Interpolate(float a, float b, float w);
    float DotGridGradient(int gx, int gy, float x, float y);
};