#include "vivo.h"
#include "vampiro.h"

    Vampiro::Vampiro(int vidaMaxima, int velocidade, int forca) : Vivo(vidaMaxima, velocidade, forca)
    {
        
    }
    void mente(void)
    {

    }
    //~Inimigo();
enum State
{
    VAGAR,
    ATACAR,
    ESCONDER
};