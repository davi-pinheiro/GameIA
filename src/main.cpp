#include <iostream>
#include <SDL2/SDL.h>
#include "controle.h"
#include "vivo.h"
#include "janela.h"
#include "rgba.h"
#include "vampiro.h"
#include "monsterCollection.h"
#include "allyCollection.h"
#include "personagem.h"
#include "tempo.h"


using std::rand;
using std::cout;
using std::endl;
using std::vector;

const int ALTURA = 540;
const int LARGURA = 1080;

int main(int argc, char const *argv[])
{
    Tempo tempo;
    MonsterCollection colecaoMonster;
    AllyCollection colecaoAlly;

    colecaoMonster.generateMonsters(ALTURA, LARGURA);
    colecaoAlly.generateAllies(ALTURA, LARGURA);
    Personagem* personagem = new Personagem(50, 5, 3, false, 20, 20, LARGURA/2, ALTURA/2, NONE);

    colecaoAlly.getAllyCollection().push_back(personagem);

    colecaoMonster.setInimigos(colecaoAlly.getAllyCollection());
    colecaoAlly.setInimigos(colecaoMonster.getMonsterCollection());

    SDL_Init(SDL_INIT_VIDEO);

    Janela janela(ALTURA, LARGURA);
    SDL_ShowWindow(janela.getJanela());
    Rgba rgba(255, 255, 255, 255);
    SDL_Event* evento = new SDL_Event;

    while (!SDL_QuitRequested())
    {
        while (SDL_PollEvent(evento))
        {
            controle(personagem, evento);
        }
        
        janela.backgroundColor(rgba, tempo);

        janela.renderizarCharacter(personagem);
        janela.renderizarMonsters(colecaoMonster.getMonsterCollection());
        janela.renderizarAllies(colecaoAlly.getAllyCollection());

        
        
        
        SDL_RenderPresent(janela.getRenderizador());
        SDL_Delay(100);

        if(SDL_QuitRequested())
        {
            break;
        }
    }
    
    janela.~Janela();
    

    return 0;
}
