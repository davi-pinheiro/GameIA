#include "vivo.h"

Vivo::Vivo(int vidaMaxima, int velocidade, int forca){
    this->vidaMaxima = vidaMaxima;
    this->vida = vidaMaxima;
    this->velocidade = velocidade;
    this->forca = forca;
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