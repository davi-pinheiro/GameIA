#include "janela.h"
#include "vampiro.h"
#include "guerreiro.h"
#include <iostream>

using std::cout;
using std::endl;

Janela::Janela(int mapaAltura, int mapaLargura, int telaAltura, int telaLargura)
{    
    janela = SDL_CreateWindow("GameIA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, telaLargura, telaAltura, SDL_WINDOW_HIDDEN);

    renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    background.setRgba(195, 195, 195, 195);

    textura = SDL_CreateTexture(renderizador, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, mapaLargura, mapaAltura);
}

int Janela::getAltura()
{
    return altura;
}

int Janela::getLargura()
{
    return largura;
}

SDL_Renderer* Janela::getRenderizador()
{
    return renderizador;
}

SDL_Window* Janela::getJanela()
{
    return janela;
}

SDL_Texture* Janela::getTextura()
{
    return textura;
}

void Janela::setAltura(int altura)
{
    this->altura = altura;
}

void Janela::setLargura(int largura)
{
    this->largura = largura;
}


void Janela::backgroundColor(Tempo& tempo)
{
    tempo.changeStateDay();
    switch (tempo.getEstadoDia())
    {
    case MORNING:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(195,195,195,195);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(225,225,225,225);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(255,255,255,255);
        }
            
        break;
    case AFTERNOON:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(255,255,255,255);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(225,225,225,225);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(195,195,195,195);
        }
        break;
    case EVENING:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(195,195,195,195);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(165,165,165,165);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(135,135,135,135);
        }
        break;
    case DAWN:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(135,135,135,135);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(165,165,165,165);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(195,195,195,195);
        }
        break;
    
    default:
        break;
    }

    frontgroundColor(background);
    SDL_RenderClear(renderizador);
}

void Janela::frontgroundColor(Rgba rgba)
{
    SDL_SetRenderDrawColor(renderizador, rgba.getR(), rgba.getG(), rgba.getB(), rgba.getA());
}

void Janela::renderizarMonsters(vector<Vivo*> colecao, Camera& camera)
{
    for(int i = 0; i < (int)colecao.size(); i++)
    {
        if(camera.getCamera()->x < 1080)
        {
            if(camera.getCamera()->y < 1080)
            {
                if((colecao[i]->getPersonagem()->x < 1080) &&
                (colecao[i]->getPersonagem()->y < 1080))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 1080) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 1080))
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
            else if((camera.getCamera()->y >= 1080) &&
            (camera.getCamera()->y < 2160))
            {
                if((colecao[i]->getPersonagem()->x < 1080) &&
                (colecao[i]->getPersonagem()->y >= 1080) &&
                (colecao[i]->getPersonagem()->y < 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 1080) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 2160))
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }

                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }                    
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
            }
            else if(camera.getCamera()->y >= 2160)
            {
                if((colecao[i]->getPersonagem()->x < 1080) &&
                (colecao[i]->getPersonagem()->y >= 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if(camera.getCamera()->x + camera.getCamera()->w >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
        }
        else if((camera.getCamera()->x >= 1080) &&
        (camera.getCamera()->x < 2160))
        {
            if(camera.getCamera()->y < 1080)
            {
                if((colecao[i]->getPersonagem()->x >= 1080) &&
                (colecao[i]->getPersonagem()->x < 2160) &&
                (colecao[i]->getPersonagem()->y < 1080))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 2160) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 1080))
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
            else if((camera.getCamera()->y >= 1080) &&
            (camera.getCamera()->y < 2160))
            {
                if((colecao[i]->getPersonagem()->x >= 1080) &&
                (colecao[i]->getPersonagem()->x < 2160) &&
                (colecao[i]->getPersonagem()->y >= 1080) &&
                (colecao[i]->getPersonagem()->y < 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 2160) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 2160))
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
            else if(camera.getCamera()->y >= 2160)
            {
                if((colecao[i]->getPersonagem()->x >= 1080) &&
                (colecao[i]->getPersonagem()->x < 2160) &&
                (colecao[i]->getPersonagem()->y >= 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if(camera.getCamera()->x + camera.getCamera()->w >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
        }
        else if(camera.getCamera()->x >= 2160)
        {
            if(camera.getCamera()->y < 1080)
            {
                if((colecao[i]->getPersonagem()->x >= 2160) &&
                (colecao[i]->getPersonagem()->y < 1080))
                {
                    ((Vampiro*)colecao[i])->machine();
                }

                if(camera.getCamera()->y + camera.getCamera()->h >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
            }
            else if((camera.getCamera()->y >= 1080) &&
            (camera.getCamera()->y < 2160))
            {
                if((colecao[i]->getPersonagem()->x >= 2160) &&
                (colecao[i]->getPersonagem()->y >= 1080) &&
                (colecao[i]->getPersonagem()->y < 2160))
                {
                    ((Vampiro*)colecao[i])->machine();
                }

                if(camera.getCamera()->y + camera.getCamera()->h >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
            }
            else if(camera.getCamera()->y >= 2160)
            {
                if((colecao[i]->getPersonagem()->x >= 2160) &&
                (colecao[i]->getPersonagem()->y >= 2160))
                {
                    ((Vampiro*)colecao[i])->machine();
                }
            }
        }

        frontgroundColor(colecao[i]->getRgba());
        SDL_RenderFillRect(renderizador, colecao[i]->getPersonagem());
    }
}

void Janela::renderizarAllies(vector<Vivo*> colecao, Camera& camera)
{
    for(int i = 0; i < (int)colecao.size()-1; i++)
    {
        if(camera.getCamera()->x < 1080)
        {
            if(camera.getCamera()->y < 1080)
            {
                if((colecao[i]->getPersonagem()->x < 1080) &&
                (colecao[i]->getPersonagem()->y < 1080))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 1080) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 1080))
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
            else if((camera.getCamera()->y >= 1080) &&
            (camera.getCamera()->y < 2160))
            {
                if((colecao[i]->getPersonagem()->x < 1080) &&
                (colecao[i]->getPersonagem()->y >= 1080) &&
                (colecao[i]->getPersonagem()->y < 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 1080) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 2160))
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }

                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }                    
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x < 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
            }
            else if(camera.getCamera()->y >= 2160)
            {
                if((colecao[i]->getPersonagem()->x < 1080) &&
                (colecao[i]->getPersonagem()->y >= 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if(camera.getCamera()->x + camera.getCamera()->w >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
        }
        else if((camera.getCamera()->x >= 1080) &&
        (camera.getCamera()->x < 2160))
        {
            if(camera.getCamera()->y < 1080)
            {
                if((colecao[i]->getPersonagem()->x >= 1080) &&
                (colecao[i]->getPersonagem()->x < 2160) &&
                (colecao[i]->getPersonagem()->y < 1080))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 2160) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 1080))
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y < 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->y >= 1080))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
            else if((camera.getCamera()->y >= 1080) &&
            (camera.getCamera()->y < 2160))
            {
                if((colecao[i]->getPersonagem()->x >= 1080) &&
                (colecao[i]->getPersonagem()->x < 2160) &&
                (colecao[i]->getPersonagem()->y >= 1080) &&
                (colecao[i]->getPersonagem()->y < 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if((camera.getCamera()->x + camera.getCamera()->w >= 2160) &&
                (camera.getCamera()->y + camera.getCamera()->h >= 2160))
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }

                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->x + camera.getCamera()->w >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
                else if(camera.getCamera()->y + camera.getCamera()->h >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 1080) &&
                    (colecao[i]->getPersonagem()->x < 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
            else if(camera.getCamera()->y >= 2160)
            {
                if((colecao[i]->getPersonagem()->x >= 1080) &&
                (colecao[i]->getPersonagem()->x < 2160) &&
                (colecao[i]->getPersonagem()->y >= 2160))
                {
                    ((Vampiro*)colecao[i])->machine();                    
                }

                if(camera.getCamera()->x + camera.getCamera()->w >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();                    
                    }
                }
            }
        }
        else if(camera.getCamera()->x >= 2160)
        {
            if(camera.getCamera()->y < 1080)
            {
                if((colecao[i]->getPersonagem()->x >= 2160) &&
                (colecao[i]->getPersonagem()->y < 1080))
                {
                    ((Vampiro*)colecao[i])->machine();
                }

                if(camera.getCamera()->y + camera.getCamera()->h >= 1080)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 1080) &&
                    (colecao[i]->getPersonagem()->y < 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
            }
            else if((camera.getCamera()->y >= 1080) &&
            (camera.getCamera()->y < 2160))
            {
                if((colecao[i]->getPersonagem()->x >= 2160) &&
                (colecao[i]->getPersonagem()->y >= 1080) &&
                (colecao[i]->getPersonagem()->y < 2160))
                {
                    ((Vampiro*)colecao[i])->machine();
                }

                if(camera.getCamera()->y + camera.getCamera()->h >= 2160)
                {
                    if((colecao[i]->getPersonagem()->x >= 2160) &&
                    (colecao[i]->getPersonagem()->y >= 2160))
                    {
                        ((Vampiro*)colecao[i])->machine();
                    }
                }
            }
            else if(camera.getCamera()->y >= 2160)
            {
                if((colecao[i]->getPersonagem()->x >= 2160) &&
                (colecao[i]->getPersonagem()->y >= 2160))
                {
                    ((Vampiro*)colecao[i])->machine();
                }
            }
        }

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