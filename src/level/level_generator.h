#pragma once
#include <vector>


class LevelGenerator {
public:
    std::vector<std::vector<float>> GenerateLevel(int width, int height);

private:
    int kScreenWidth{ 640 };
    int kScreenHeight{ 480 };
    int seed{ 0 };

    std::vector<std::vector<float>> GenerateDungeon(int width, int height, int octave);
    std::vector<float> GetGradient(int x, int y);
    float GenerateNoise(float x, float y);
    float Interpolate(float a, float b, float w);
    float DotGridGradient(int gx, int gy, float x, float y);
};