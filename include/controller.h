#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "pacman.h"

class Controller{
    public:
        void HandleInput(bool &running, Pacman &pac) const;

    private:
        void ChangeDirection(Pacman &pac, Pacman::Direction input, 
                            Pacman::Direction opposite) const;
};
#endif