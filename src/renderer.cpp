#include "renderer.h"
#include <iostream>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t grid_width, const std::size_t grid_height):
    _screen_width(screen_width),
    _screen_height(screen_height),
    _grid_width(grid_width),
    _grid_height(grid_height){
    // intitialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error:" << SDL_GetError() << "\n";
    }

    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
        std::cerr << "IMG could not initialize.\n";
        std::cerr << "SDL_Error:" << SDL_GetError() << "\n";
    }

    // Create Window
    _win = SDL_CreateWindow("Pacman Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screen_width, _screen_height, SDL_WINDOW_SHOWN);

    // Check if window was created
    if(_win == nullptr){
        std::cerr << "Window could not be created.\n";
        std::cerr << "SDL_Error:" << SDL_GetError() << "\n";
    }

    // Create Renderer
    _renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);

    // Check if Renderer was created
    if(_renderer == nullptr){
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error:" << SDL_GetError() << "\n";
    }

}

Renderer::~Renderer(){
    SDL_DestroyTexture(_pacmanTexture);
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void Renderer::Render(Pacman const pacman){
    // Clear Screen
    SDL_SetRenderDrawColor(_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(_renderer);

    // Render Pacman Image
    SDL_Rect block;
    block.w = _grid_width / 2;
    block.h = _grid_height / 2;
    block.x = _screen_width / 8;
    block.y = _screen_height / 6;

    // Load Pacman Image surface
    auto surface = IMG_Load(pacman.getPath().c_str());

    // Check if surface was created
    if(!surface){
        std::cerr << "Failed to create surface"<< std::endl;
    }

    // Create texture from surface
    _pacmanTexture = SDL_CreateTextureFromSurface(_renderer, surface);

    // Check if texture was created
    if(!_pacmanTexture){
        std::cerr << "Failed to create texture. \n";
    }

    // Copy texture to the renderer
    SDL_RenderCopy(_renderer, _pacmanTexture, nullptr, &block);

    // Render the changes to the screen
    SDL_RenderPresent(_renderer);

    // Clean up
    SDL_FreeSurface(surface);
    
}