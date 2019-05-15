#include "neuron.h"



#define ALPHA 0.8

using namespace std;

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

double Network::Mostrar_Output()
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
    return a[k][j];
    }
  }
}
std::cout << std::endl;
}


double Network::sigmoide(double x)
{
  return (1.0/(1+exp(-1*x)));
}

double Network::sigmoide_prima(double x)
{
  return (exp(x)/((exp(x)+1)*(exp(x)+1)));
}

std::vector <double> Network::Calcular_outputs(std::vector<double>& input)
{
std::vector <double> salidas (a[a.size()-1].size());

// calculate the output from imput layers
for(int j = 0; j < a[0].size(); j++)
{
  a[0][j] = input[j];
}

// calculate output of deep layers
for(int l = 1; l < a.size(); l++)
   {
       for(int i = 0; i < a[l].size(); i++)
       {
           in[l][i] = 0;
           for(int j = 0; j < a[l-1].size(); j++)
           {
               in[l][i] += Weight[l-1][j][i]*a[l-1][j];
           }
           a[l][i] = sigmoide(in[l][i]);
       }
   }

   salidas = a[a.size()-1];
   return salidas;

}


void Network::Aprendizaje_Prop_Atras(vector< vector < double > >& inputs, vector < vector < double > >& outputs)
{

    double suma;
    int contador = 0;
    double ERROR = 200;
    double error;

    //La red debe dejar de aprender cuando el error sea menor de 0.0001 o se sobrepase el maximo de iteraciones
    while(ERROR > 0.0001 and contador < 10000)
    {
        ERROR = 0;
        for(int e = 0; e < inputs.size(); e++)
        {
            Calcular_outputs(inputs[e]); //Feedforward (calcular los outputs)

            //Calcular el error delta de la capa de salida
            for(int i = 0; i < a[n_capas-1].size(); i++)
            {
                error = (outputs[e][i]-a[a.size()-1][i]);
                delta[delta.size()-1][i] = sigmoide_prima(in[in.size()-1][i])*error;
                ERROR += error*error; //Guardamos el cuadrado del error para poder calcular el error cuadratico
            }

            //Propagar el error hacia atras
            for(int l = n_capas-2; l >= 0; l--)
            {
                for(int j = 0; j < a[l].size(); j++)
                {
                    suma = 0;
                    for(int i = 0; i < Weight[l][j].size(); i++)
                    {
                        suma = suma + Weight[l][j][i]*delta[l+1][i];
                    }
                    delta[l][j] = sigmoide_prima(in[l][j])*suma;
                    for(int i = 0; i < a[l+1].size(); i++)
                    {
                        Weight[l][j][i] = Weight[l][j][i] + ALPHA*a[l][j]*delta[l+1][i];
                    }
                }
            }
        }

          ERROR *= 0.5*(1.0/inputs.size()); //Calculamos el error cuadratico
        cout << "ERROR = " << ERROR << endl; //Mostramos el error para poder observar la convergencia
        contador ++; //Aumentamos el contador de iteraciones
    }


}
