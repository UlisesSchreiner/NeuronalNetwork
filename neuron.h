#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <fstream>
 
using namespace std;
 
class Network
{
    public:
        //Constructor y destructor
        Network(vector< int >& layers);
        ~Network();
 
        //Debug: mostrar la matriz de pesos y los outputs de cada neurona
        void Mostrar_Pesos();
        void Mostrar_Output();

 
    private:
        int n_capas; //Numero de capas de la red neuronal
         
 
};
