#include "janela.h"
#include <iostream>


Janela::Janela(int altura, int largura)
{    
    janela = SDL_CreateWindow("GameIA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largura, altura, SDL_WINDOW_HIDDEN);

    renderizador = SDL_CreateRenderer(janela, -1, 0);
}

int Janela::getAltura()
{
    return altura;
}

void Janela::setAltura(int altura)
{
    this->altura = altura;
}

int Janela::getLargura()
{
    return largura;
}

void Janela::setLargura(int largura)
{
    this->largura = largura;
}

SDL_Renderer* Janela::getRenderizador()
{
    return renderizador;
}

SDL_Window* Janela::getJanela()
{
    return janela;
}

void Janela::backgroundColor(Rgba rgba)
{
    frontgroundColor(rgba);
    SDL_RenderClear(renderizador);
}

void Janela::frontgroundColor(Rgba rgba)
{
    SDL_SetRenderDrawColor(renderizador, rgba.getR(), rgba.getG(), rgba.getB(), rgba.getA());
}

Janela::~Janela()
{
    SDL_DestroyWindow(janela);
    SDL_Quit();
}