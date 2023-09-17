#include <iostream>
#include "vivo.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    Vivo eu(50, 3, 5);

    cout << eu.getVidaMaxima() << " + ";
    cout << eu.getVida() << " + ";
    cout << eu.getVelocidade() << " + ";
    cout << eu.getForca() << endl;

    eu.setVida(26);
    cout << eu.getVida() << endl;
    eu.setVidaMaxima(100);
    cout << eu.getVida() << endl;
    eu.setVida(100);
    eu.setVelocidade(5);
    eu.setForca(3);

    cout << eu.getVidaMaxima() << " + ";
    cout << eu.getVida() << " + ";
    cout << eu.getVelocidade() << " + ";
    cout << eu.getForca() << endl;

    return 0;
}
