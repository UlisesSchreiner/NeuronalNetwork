#include "neuron.h"



#define ALPHA 0.8


/*CONSTRUCTOR*/
Network::Network(vector< int >& layers)
{
  n_capas = layers.size();  //numbrer of layers
  srand (time(NULL));      //generate a seed

  double r;

    for(int k = 0; k < n_capas-1; k++) // hace una iter x cada capa
    {
    Weight.push_back({});
      for(int j = 0; j < layers[k]; j++) // aca recorre cada capa con su n de nueronas
      {
        Weight[k].push_back({});
          for(int i = 0; i < layers[k+1]; i++) // haca hace ina iter x cada neurona de la siguiente capa
          {
              //generate a random numbet between -1 and 1
              r = rand()%200-100;
              r = r/100;

              //generate a weight with this random number
              Weight[k][j].push_back(r);
          }
      }
    }

for(int k = 0; k < n_capas; k++) // hace una iter x cada capa
{
 a.push_back({});
 in.push_back({});
 delta.push_back({});
   for(int j = 0; j < layers[k]; j++) // hace una iter x cada neurona de la capa
   {
    a[k].push_back(j);
    in[k].push_back(j);
    delta[k].push_back(j);
   }
}

}


/*DESTRUCTOR*/
Network::~Network(){};




/*FUNCIONES DE DEBUG*/
void Network::Mostrar_Pesos()
{
  std::cout << "Pesos: " << std::endl;
  for(int k = 0; k < Weight.size(); k++)
  {
    std::cout << std::endl << "[" << k << "]  ";
    for(int j = 0; j < Weight[k].size(); j++)
    {
      std::cout << "[" << j << "](";
      for(int i = 0; i < Weight[k][j].size()-1; i++)
      {
        std::cout << Weight[k][j][i] << ", ";
      }
      std::cout << Weight[k][j][Weight[k][j].size()-1] << ")   ";
    }
  }
 std::cout << std::endl;

}

void Network::Mostrar_Output()
{
std::cout << "Ouputs: " << std::endl;
for(int k = 0; k < a.size(); k++)
{
  std::cout << "[" << k << "]  ";
  for(int j = 0; j < a[k].size(); j++)
  {
    if(k != a.size()-1)
    {
      std::cout << "[" << j << "](" << a[k][j] << ")  ";
    } else{
      std::cout << "\033[1;44m[" << j << "](" << a[k][j] << ")\033[0m    ";
    }
  }
}
std::cout << std::endl;
}
