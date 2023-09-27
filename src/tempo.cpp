#include "tempo.h"

Tempo::Tempo()
{
    tempoInicial = time(NULL);
    estadoDia = MORNING;
    passou = true;
}

time_t Tempo::getTempoInicial()
{
    return tempoInicial;
}

StateDay Tempo::getEstadoDia()
{
    return estadoDia;
}

void Tempo::setEstadoDia(StateDay estadoDia)
{
    this->estadoDia = estadoDia;
}

time_t Tempo::getTempoNow()
{
    time_t tempoAgora = time(NULL);
    return difftime(tempoAgora, tempoInicial);
}

void Tempo::changeStateDay()
{
    if((getTempoNow() % 15 == 0))
    {
        if(passou == false)
        {
            passou = true;
            switch (estadoDia)
            {
            case MORNING:
                estadoDia = AFTERNOON;
                break;
            case AFTERNOON:
                estadoDia = EVENING;
                break;
            case EVENING:
                estadoDia = DAWN;
                break;
            case DAWN:
                estadoDia = MORNING;
                break;
            
            default:
                break;
            }
        }
    }
    else
    {
        passou = false;
    }
}
//bool getPassou();