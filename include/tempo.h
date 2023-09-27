#ifndef TEMPO_H
#define TEMPO_H

#include <ctime>
#include "stateDay.h"

class Tempo
{
private:
    time_t tempoInicial;
    StateDay estadoDia;
    bool passou;
public:
    Tempo();
    time_t getTempoInicial();
    StateDay getEstadoDia();
    bool getPassou();

    void setEstadoDia(StateDay estadoDia);


    int getTempoNow();
    void changeStateDay();


};

#endif