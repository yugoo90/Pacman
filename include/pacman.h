#ifndef PACMAN_H
#define PACMAN_H

#include "renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Pacman {
    public:
        enum class Direction {KUp, KDown, KLeft, KRight };
        Pacman(std::size_t x, std::size_t y, const std::string &path);
        
        void UpdatePacman();
        bool alive{true};
        float speed{0.1f};
        Direction direction = Direction::KRight;
        std::string getPath() const {
            return _path;
        }
        

    private:
        std::string _path;
        std::size_t _x;
        std::size_t _y;
        
};

#endif