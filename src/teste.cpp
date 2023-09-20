#include <iostream>
#include <SDL2/SDL.h>
#include "vivo.h"
#include "janela.h"
#include "rgba.h"
#include "vampiro.h"
#include <cstdlib>
#include <vector>

using std::rand;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<Vivo> monster;
    Rgba cor(0, 0, 0, 0);
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++)
    {
        x = rand() % 1081;
        y = rand() % 541;
        
        Vampiro eu(50, 5, 3, false,  20,  20,  x,  y, cor);
        monster.push_back(eu);
    }
    
    //Vampiro eu(50, 5, 3, false,  20,  20,  0,  0, cor);

    
    SDL_Init(SDL_INIT_VIDEO);

    Janela janela(540, 1080);
    SDL_ShowWindow(janela.getJanela());
    Rgba rgba(255, 255, 255, 255);

    for (int i = 0; i < 255; i++)
    {
        //rgba.setRgba(255, 255, 255, 255);
        janela.backgroundColor(rgba);
        
        
        
        janela.frontgroundColor(monster[0].getRgba());
        SDL_RenderFillRect(janela.getRenderizador(), monster[0].getPersonagem());

        //janela.frontgroundColor(monster[1].getRgba());
        SDL_RenderFillRect(janela.getRenderizador(), monster[1].getPersonagem());

        //janela.frontgroundColor(monster[2].getRgba());
        SDL_RenderFillRect(janela.getRenderizador(), monster[2].getPersonagem());
        

        SDL_RenderPresent(janela.getRenderizador());
        SDL_Delay(10);
    }

    
    

    return 0;
}
