#include <cstdlib>
#include "monsterCollection.h"
#include "vampiro.h"

using std::rand;

vector<Vivo> MonsterCollection::getMonsterCollection()
{
    return monsterCollection;
}

void MonsterCollection::generateMonsters(int altura, int largura, Rgba rgba)
{
    int x = 0, y = 0;
    int quantidadeInimigos = (20 * largura * altura) / 100;
    for (int i = 0; i < quantidadeInimigos; i++)
    {
        x = rand() % (largura - 19);
        y = rand() % (altura - 19);
        
        Vampiro eu(50, 5, 3, false,  20,  20,  x,  y, rgba);
        monsterCollection.push_back(eu);
    }
}

void MonsterCollection::renderizarMonsters(Janela janela)
{
    for(int i = 0; i < (int) monsterCollection.size(); i++)
    {
        janela.frontgroundColor(monsterCollection[i].getRgba());
        SDL_RenderFillRect(janela.getRenderizador(), monsterCollection[i].getPersonagem());
    }
    
}