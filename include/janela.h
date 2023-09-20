#ifndef JANELA_H
#define JANELA_H

#include <SDL2/SDL.h>
#include "rgba.h"

class Janela
{
private:
    SDL_Window *janela;
    SDL_Renderer *renderizador;
    int altura;
    int largura;

public:
    Janela(int altura, int largura);

    int getAltura();
    void setAltura(int altura);
    int getLargura();
    void setLargura(int largura);

    SDL_Renderer* getRenderizador();
    SDL_Window* getJanela();
    void backgroundColor(Rgba rgba);
    void frontgroundColor(Rgba rgba);

    ~Janela();


};

#endif