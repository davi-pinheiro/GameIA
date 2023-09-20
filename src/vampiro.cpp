#include "vampiro.h"

    Vampiro::Vampiro(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, Rgba rgba) : Vivo(vidaMaxima, velocidade, forca, inimigo, h, w, x, y, rgba)
    {
        estado = VAGAR;
    }

    State Vampiro::getEstado()
    {
        return estado;
    }

    void Vampiro::setEstado(State estado)
    {
        this->estado = estado;
    }

    void Vampiro::machine()
    {
        switch (estado)
        {
        case VAGAR:
            
            break;
        case ATACAR:
            break;
        
        
        default:
            break;
        }
    }