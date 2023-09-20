#ifndef VAMPIRO_H
#define VAMPIRO_H

#include <SDL2/SDL.h>
#include "vivo.h"
#include "state.h"
#include "rgba.h"

class Vampiro : public Vivo
{
private:
    State estado;
public:
    Vampiro(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, Rgba rgba);
    State getEstado();
    void setEstado(State estado);

    void machine();
};

#endif