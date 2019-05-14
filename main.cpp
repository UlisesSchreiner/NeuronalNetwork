/*   CODIGO DE ROBOT ESQUIVA-OBSTACULOS CON V-REP

     Escrito por Nano en beneficio de los seres humanos
     www.robologs.net
*/

#include <iostream>
#include "neuron.h"

using namespace std;


int main()
{

std::vector< vector< double > > entrenador1{
{0.23,1,1,1,1,1},
{0.23,0.23,1,1,1,1},
{0.12,0.12,1,1,1,1},
{1,1,1,1,1,1},
{1,1,0.12,0.12,1,1},
{1,1,0.23,0.23,1,1},
{1,1,1,1,0.23,0.23},
{1,1,1,1,1,0.23},
{1,1,1,1,0.12,0.12},
{1,1,1,0.23,1,1},
{1,1,0.23,1,1,1},
{1,1,1,0.12,0.12,1}};

std::vector< vector< double > > entrenador2{
    {1,0.5},
    {1,0.5},
    {1,0},
    {1,1},
    {0,0.75},
    {0.6,1},
    {0.5,1},
    {0.5,1},
    {0,1},
    {0,1},
    {0,1},
    {0,0.5}};

    std::vector <int>capas;
    capas.push_back(6);
    capas.push_back(15);
    capas.push_back(15);
    capas.push_back(2);
      //Creamos la red
      cout << "Creando red..." << endl;
      Network red(capas);
      cout << "Red creada" << endl;



  //Entrenamos la red con los ejemplos
     cout << "Entrenando red..." << endl;
     red.Aprendizaje_Prop_Atras(entrenador1, entrenador2);
     cout << "Red entrenada" << endl;

     red.Mostrar_Pesos(); //Mostramos los pesos definitivos

     //Mostrar los outputs:
     for(int i = 0; i < entrenador1.size(); i++)
     {
         red.Calcular_outputs(entrenador1[i]);
         red.Mostrar_Output();
     }




    cout << "Simulacion finalizada" << endl;
    return 0;
}
