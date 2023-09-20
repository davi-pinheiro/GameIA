#ifndef MONSTERCOLLECTION_H
#define MONSTERCOLLECTION_H

#include <vector>
#include <SDL2/SDL.h>
#include "vivo.h"
#include "rgba.h"
#include "janela.h"

using std::vector;

class MonsterCollection
{
private:
    vector<Vivo> monsterCollection;
public:
    MonsterCollection(/* args */);
    vector<Vivo> getMonsterCollection();
    void generateMonsters(int altura, int largura, Rgba rgba);
    void renderizarMonsters(Janela janela);
    
};


#endif