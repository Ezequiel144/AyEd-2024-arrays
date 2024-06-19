#include <iostream>
#include <cstdlib>
/*
    Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y muestre una lista
donde  se  vea  cuántas  veces  se  dio  cada  uno  de  los  resultados  posibles.  Por  cada  tirada  se  deberán
ingresar  2  valores,  cada  uno  representa  el  valor  de  un  dado.  El  formato  de  la  salida  debe  ser  el
siguiente:
2 salió ... veces
3 salió ... veces
.
.
12  salió ... veces
*/

void arrayLoadGiven(int[], const int);
void showArray(int[], const int);

using namespace std;

int main()
{
    /*al ser 2 dados los resultados posibles son 2,3,4,5,6,7,8,9,10,11,12*/
    const int dim = 11;
    const int dimDiceRoll = 50;
    int arrayResults[dim] = {0}; /* 2 a 12 en posiciones 0 a 10 */
    arrayLoadGiven(arrayResults, dimDiceRoll);
    showArray(arrayResults, dim);
    return 0;
}

void showArray(int array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "[" << i + 2 << "] : " << array[i] << endl;
    }
}

void arrayLoadGiven(int array[], const int dim)
{
    int givenOne = 0, givenTwo = 0,sumResult = 0;
    for (int i = 0; i < dim; ++i)
    {
        givenOne = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6
        givenTwo = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6
        sumResult = givenOne + givenTwo;
        array[sumResult - 2]++;
    }
}
