#ifndef JANELA_H
#define JANELA_H

#include <SDL2/SDL.h>
#include "vivo.h"
#include <vector>
#include "monsterCollection.h"
#include "rgba.h"
#include "tempo.h"
#include "personagem.h"

using std::vector;

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

    void backgroundColor(Rgba rgba, Tempo tempo);
    void frontgroundColor(Rgba rgba);

    void renderizarEntities(vector<Vivo*> colecao);
    void renderizarMonsters(vector<Vivo*> colecao);
    void renderizarAllies(vector<Vivo*> colecao);

    void renderizarCharacter(Personagem* personagem);

    ~Janela();


};

#endif