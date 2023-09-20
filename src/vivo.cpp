#include "vivo.h"

Vivo::Vivo(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, Rgba rgba){
    this->vidaMaxima = vidaMaxima;
    this->vida = vidaMaxima;
    this->velocidade = velocidade;
    this->forca = forca;
    this->inimigo = inimigo;

    personagem.h = h;
    personagem.w = w;
    personagem.x = x;
    personagem.y = y;

    this->rgba = rgba;
}

int Vivo::getVidaMaxima(void){
    return vidaMaxima;
}

int Vivo::getVida(void){
    return vida;
}

int Vivo::getVelocidade(void){
    return velocidade;
}

int Vivo::getForca(void){
    return forca;
}

bool Vivo::isInimigo(void){
    return inimigo;
}

SDL_Rect* Vivo::getPersonagem(void)
{
    return &personagem;
}

void Vivo::setVidaMaxima(int vidaMaxima){
    vida = (int) (vida * vidaMaxima) / this->vidaMaxima;
    this->vidaMaxima = vidaMaxima;
}

void Vivo::setVida(int vida){
    this->vida = vida;
}

void Vivo::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

void Vivo::setForca(int forca){
    this->forca = forca;
}

void Vivo::setInimigo(bool inimigo)
{
    this->inimigo = inimigo;
}

Rgba Vivo::getRgba(void)
{
    return rgba;
}
