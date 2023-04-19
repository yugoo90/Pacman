#include "pacman.h"0
#include <iostream>

Pacman::Pacman(std::size_t x, std::size_t y, const std::string &path){
    _x = x;
    _y = y;
    _path = path.c_str();
}

void Pacman::UpdatePacman(){
    switch (direction)
    {
    case Direction::KUp:
        _y -= speed;
        break;
    case Direction::KDown:
        _y += speed;
        break;
    case Direction::KLeft:
        _x -= speed;
        break;
    case Direction::KRight:
        _x += speed;
        break;
    }
}

