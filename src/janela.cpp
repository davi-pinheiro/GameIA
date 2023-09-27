#include "janela.h"
#include "vampiro.h"
#include "guerreiro.h"
#include <iostream>

using std::cout;
using std::endl;

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

void Janela::backgroundColor(Rgba rgba, Tempo tempo)
{
    tempo.changeStateDay();
    switch (tempo.getEstadoDia())
    {
    case MORNING:
        rgba.setRgba(195,195,195,195);
        break;
    case AFTERNOON:
        rgba.setRgba(255,255,255,255);
        break;
    case EVENING:
        rgba.setRgba(195,195,195,195);
        break;
    case DAWN:
        rgba.setRgba(135,135,135,135);
        break;
    
    default:
        break;
    }

    frontgroundColor(rgba);
    SDL_RenderClear(renderizador);
}

void Janela::frontgroundColor(Rgba rgba)
{
    SDL_SetRenderDrawColor(renderizador, rgba.getR(), rgba.getG(), rgba.getB(), rgba.getA());
}

void Janela::renderizarMonsters(vector<Vivo*> colecao)
{
    for(int i = 0; i < (int)colecao.size(); i++)
    {
        ((Vampiro*)colecao[i])->machine();
        
        frontgroundColor(colecao[i]->getRgba());
        SDL_RenderFillRect(renderizador, colecao[i]->getPersonagem());
    }
}

void Janela::renderizarAllies(vector<Vivo*> colecao)
{
    for(int i = 0; i < (int)colecao.size()-1; i++)
    {
        ((Guerreiro*)colecao[i])->machine();
        
        frontgroundColor(colecao[i]->getRgba());
        SDL_RenderFillRect(renderizador, colecao[i]->getPersonagem());
    }
}

void Janela::renderizarCharacter(Personagem* personagem)
{
    frontgroundColor(personagem->getRgba());
    SDL_RenderFillRect(renderizador, personagem->getPersonagem());
}

Janela::~Janela()
{
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();
}