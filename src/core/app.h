#include <SDL3/SDL.h>

class Application {
public:
    Application();
    ~Application();

    void Run();

private:
    constexpr int kScreenWidth{ 640 };
    constexpr int kScreenHeight{ 480 };

    SDL_Window* mainWindow{ nullptr };
    SDL_Renderer* mainRenderer{ nullptr };
};