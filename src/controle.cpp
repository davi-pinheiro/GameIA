#include "controle.h"

void controle(Personagem* player, SDL_Event *evento)
{
    if(evento->type == SDL_KEYDOWN)
    {
        switch(evento->key.keysym.sym)
        {
        case SDLK_w:
            player->getPersonagem()->y -= 10;
            break;
        case SDLK_a:
            player->getPersonagem()->x -= 10;
            break;
        case SDLK_s:
            player->getPersonagem()->y += 10;
            break;
        case SDLK_d:
            player->getPersonagem()->x += 10;
            break;
        }
    }
}