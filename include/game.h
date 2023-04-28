#ifndef GAME_H
#define GAME_H

#include <random>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "controller.h"
#include "renderer.h"
#include "pacman.h"

class Game{
    public:
        Game(std::size_t grid_width, std::size_t grid_height, std::string path);
        void Run(Controller const &controller, Renderer &renderer,
            std::size_t target_frame_duration);

        int GetScore() const;
        
    private:
        Pacman pacman;
        int score{0};
        void PlaceFood();
        void Update();
};

#endif