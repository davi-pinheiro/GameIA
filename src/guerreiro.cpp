#include "guerreiro.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "state.h"


using std::cout;
using std::endl;

Guerreiro::Guerreiro(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado) : Vivo(vidaMaxima, velocidade, forca, inimigo, h, w, x, y, rgba, estado)
{
    this->rgba = Rgba(0, 0, 255, 0);
}
void Guerreiro::machine(void)
{
    
}