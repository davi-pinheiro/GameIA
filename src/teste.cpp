#include <iostream>
#include <SDL2/SDL.h>
#include "vivo.h"
#include "janela.h"
#include "rgba.h"
#include "vampiro.h"
#include "monsterCollection.h"


using std::rand;
using std::cout;
using std::endl;
using std::vector;

const int ALTURA = 540;
const int LARGURA = 1080;

int main(int argc, char const *argv[])
{
    Rgba cor (0, 0, 0, 0);
    MonsterCollection colecao;
    colecao.generateMonsters(ALTURA, LARGURA, cor);
    //Vampiro eu(50, 5, 3, false,  20,  20,  0,  0, cor);

    
    SDL_Init(SDL_INIT_VIDEO);

    Janela janela(ALTURA, LARGURA);
    SDL_ShowWindow(janela.getJanela());
    Rgba rgba(255, 255, 255, 255);

    for (int i = 0; i < 255; i++)
    {
        //rgba.setRgba(255, 255, 255, 255);
        janela.backgroundColor(rgba);
        
        colecao.renderizarMonsters(janela);
        

        SDL_RenderPresent(janela.getRenderizador());
        SDL_Delay(10);
    }

    
    

    return 0;
}
