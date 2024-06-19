#include <iostream>
#include <cstdlib>
/*Hacer un algoritmo que lea 40 números y los muestre en orden inverso.*/

using namespace std;

int arrayLoadNotes(int[], const int);
void showArray(int[], const int);
void orderInverse(int[], const int);

int main()
{
    const int dim = 40;
    int array[dim];
    arrayLoadNotes(array, dim);
    cout << "vector orden original" << endl;
    showArray(array, dim);
    cout << "vector orden inverso" << endl;
    orderInverse(array, dim);
   
    return 0;
}

int arrayLoadNotes(int array[], const int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        array[i] = rand() % 100 + 1; // Genera un número aleatorio entre 1 y 100
    }
    return 0;
}

void showArray(int array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "[" << i << "] : " << array[i] << endl;
    }
}

void orderInverse(int array[], const int dim)
{
    int arrayAux[dim] = {0};
    for (int i = 0; i < dim; i++)
    {
        arrayAux[i] = array[dim - i - 1];
    }
    /* array = arrayAux; */
    showArray(arrayAux, dim);
}
