#include <iostream>
#include "pacman.h"
#include "game.h"
#include "renderer.h"
#include "controller.h"


int main(int argc, char **argv){
    constexpr std::size_t KFramesPerSecond{60};
    constexpr std::size_t KMsPerFrame{1000 / KFramesPerSecond};
    constexpr std::size_t KScreenWidth{640};
    constexpr std::size_t KScreenHeight{640};
    constexpr std::size_t KGridWidth{150};
    constexpr std::size_t KGridHeight{150};

    Renderer renderer(KScreenWidth, KScreenHeight, KGridWidth, KGridHeight);
    Pacman pac (KGridHeight, KGridWidth, "./pacman.png");

    renderer.Render(pac);

    system("read -p 'Press Enter to continue...' var");
    return 0;
}