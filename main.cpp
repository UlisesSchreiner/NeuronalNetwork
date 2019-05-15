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
{1,0,0.2,0,0.10,1},
{0,1,0.15,0.4,0,0},
{1,0,0.7,0.2,0.8,1},
{1,1,0.3,0.5,0,0}
};

std::vector< vector< double > > entrenador2{
    {0.1},
    {1},
    {0},
    {0.9}
    };

    std::vector <int>capas;
    capas.push_back(6);
    capas.push_back(15);
    capas.push_back(15);
    capas.push_back(1);
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

     vector < double >  inPuts;

     bool state = true;
     while(state == true)
     {

       std::cout << "ANALIZADOR DE TENDENCIA POLITICA" << std::endl;
       std::cout << "introduzca un 1 si trabaja y un 0 si no trabaja. " << std::endl;
       double in_work;
       std::cin >> in_work;
       inPuts.push_back(in_work);
       std::cout << "introduzca un 1 si recibe alguna asistencia social y un 0 si no recibe" << std::endl;
       double in_social;
       std::cin >> in_social;
       inPuts.push_back(in_social);
       std::cout << "introduzva su salario promedio x0.00001" << std::endl;
       double in_salary;
       std::cin >> in_salary;
       inPuts.push_back(in_salary);
       std::cout << "introduzca la cantidad de hijos que tiene" << std::endl;
       double in_chil;
       std::cin >> in_chil;
       inPuts.push_back(in_chil);
       std::cout << "introduzca las horas por seana que estudia x0.01" << std::endl;
       double in_study;
       std::cin >> in_study;
       inPuts.push_back(in_study);
       std::cout << "introduzca un 1 si su futuro depende de usted y un 0 si depende de factores externos" << std::endl;
       double in_fut;
       std::cin >> in_fut;
       inPuts.push_back(in_fut);

       red.Calcular_outputs(inPuts);

       double result;
       result = red.Mostrar_Output();
       std::cout << std::endl;
       std::cout << std::endl;
       if(result < 0.2)
       {
         std::cout << "---> Usted tiene tendencia a votar a MM <---" << std::endl;
       }else{
         std::cout << "---> Usted tiene tendencia a votar a CFK <---" << std::endl;
       }

       std::cout << std::endl;
       std::cout << std::endl;

       int cont;
       std::cout << "desea seguir analizando? 1-si / 0-no" << std::endl;
       std::cin >> cont;
       if(cont == 0){state = false;}
     }


    cout << "Simulacion finalizada" << endl;
    return 0;
}
