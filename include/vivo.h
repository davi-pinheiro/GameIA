#ifndef VIVO_H
#define VIVO_H

#include <SDL2/SDL.h>
#include "rgba.h"

class Vivo
{
protected:
    int vidaMaxima;
    int vida;
    int velocidade;
    int forca;
    bool inimigo;
    Rgba rgba;
    SDL_Rect personagem;

public:
    Vivo(int vidaMaxima, int velocidade, int forca, bool inimigo, int h, int w, int x, int y, Rgba rgba);

    int getVidaMaxima(void);
    int getVida(void);
    int getVelocidade(void);
    int getForca(void);
    bool isInimigo(void);
    SDL_Rect* getPersonagem(void);

    Rgba getRgba(void);

    void setVidaMaxima(int vidaMaxima);
    void setVida(int vida);
    void setVelocidade(int velocidade);
    void setForca(int forca);
    void setInimigo(bool inimigo);
};

#endif