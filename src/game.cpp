#include "game.h"
#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height, std::string path)
    : pacman(grid_width, grid_height, path.c_str()){}