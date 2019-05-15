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
        double Mostrar_Output();

        double sigmoide(double x);
        double sigmoide_prima(double x);

        std::vector <double> Calcular_outputs(std::vector<double>& input);
        void Aprendizaje_Prop_Atras(vector< vector < double > >& inputs, vector < vector < double > >& outputs);

    private:
        int n_capas; //Numero de capas de la red neuronal
        vector< vector < vector <double> > > Weight; //Pesos de la red neuronal
        vector< vector < double > > in; //Input de cada neurona
        vector< vector < double > > a; //Output de cada neurona (aplicando la funcion sigmoide al input)
        vector< vector < double > > delta; //Error de cada neurona

};
