#include <iostream>
#include <cstdlib>
/*Hacer un algoritmo que lea 30 notas las cargue un vector y luego muestre la nota máxima.*/

using namespace std;

int arrayLoadNotes(int[], const int);
void showArray(int[], const int);
int maxNote(int[], const int);

int main()
{
    const int dim = 30;
    int array[dim];
    arrayLoadNotes(array, dim);
    cout << "Mostrando el vector" << endl;
    showArray(array, dim);
    cout << "La nota maxima fue: " << maxNote(array, dim) << endl;
    return 0;
}

int arrayLoadNotes(int array[], const int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        array[i] = rand() % 10 + 1; // Genera un número aleatorio entre 1 y 100
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

int maxNote(int array[], const int dim)
{
    int value = 0;
    for (int i = 0; i < dim; i++)
    {
        if (array[i] > value)
        {
            value = array[i];
        }
    }

    return value;
}
