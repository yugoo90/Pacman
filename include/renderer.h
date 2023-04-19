#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "pacman.h"

class Renderer{
    public:
        Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t grid_width, const std::size_t grid_height);
        ~Renderer();

        void Render(Pacman const pacman);
        void UpdateWindowTitle(int score, int fps);

    private:
        SDL_Window *_win;
        SDL_Texture *_pacmanTexture = nullptr;
        SDL_Renderer *_renderer;

        const std::size_t _screen_width;
        const std::size_t _screen_height;
        const std::size_t _grid_width;
        const std::size_t _grid_height;
};
#endif