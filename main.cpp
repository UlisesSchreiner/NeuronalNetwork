/*   CODIGO DE ROBOT ESQUIVA-OBSTACULOS CON V-REP

     Escrito por Nano en beneficio de los seres humanos
     www.robologs.net
*/

#include <iostream>
#include "neuron.h"

/*
extern "C" {
    #include "extApi.h"
}
*/


using namespace std;

int main()
{

  std::vector <int>capas;
capas.push_back(27);
capas.push_back(28);
capas.push_back(29);
capas.push_back(30);
    //Creamos la red
    cout << "Creando red..." << endl;
    Network red(capas);
    cout << "Red creada" << endl;

    cout << "Simulacion finalizada" << endl;
    return 0;
}
