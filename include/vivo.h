#ifndef VIVO_H
#define VIVO_H

class Vivo
{
private:
    int vidaMaxima;
    int vida;
    int velocidade;
    int forca;
public:
    Vivo(int vidaMaxima, int velocidade, int forca);
    //~Vivo(void);

    int getVidaMaxima(void);
    int getVida(void);
    int getVelocidade(void);
    int getForca(void);

    void setVidaMaxima(int vidaMaxima);
    void setVida(int vida);
    void setVelocidade(int velocidade);
    void setForca(int forca);
};

#endif