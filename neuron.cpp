#include "neuron.h"
 

 
#define ALPHA 0.8
 
 
/*CONSTRUCTOR*/
Network::Network(vector< int >& layers)
{ 
  for (int i = 0; i < layers.size(); i++){
  std::cout << "->" << layers[i] << std::endl;
  }
}
 
 
/*DESTRUCTOR*/
Network::~Network(){};
 
 
 
 
/*FUNCIONES DE DEBUG*/
void Network::Mostrar_Pesos()
{ }
 
void Network::Mostrar_Output()
{ }
 
 