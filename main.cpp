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
capas.push_back(6);
capas.push_back(15);
capas.push_back(15);
capas.push_back(2);
    //Creamos la red
    cout << "Creando red..." << endl;
    Network red(capas);
    cout << "Red creada" << endl;

cout << "mostramos pesos: " << endl;
red.Mostrar_Pesos();

std::cout << "mostramos resultados: " << std::endl;
red.Mostrar_Output();

    cout << "Simulacion finalizada" << endl;
    return 0;
}
