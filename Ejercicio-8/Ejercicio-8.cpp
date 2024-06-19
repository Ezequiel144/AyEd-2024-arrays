#include <iostream>

/*
Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
  a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
  b) Dado un código de producto informar su precio.
*/
using namespace std;

void arrayLoadProductCode(int[], const int);
void arrayLoadProductPrice(int[], const int);
void showArrayShearchPos(int[], int[], const int, int[]);
void showArrays(int[], int[], const int);
void orderDecendents(int[], const int);
int searchArray(int, int[], const int, int[]);
void arrayDuplication(int[], const int, int[]);

int main()
{
    int arrayProductCode[10];
    int arrayProductsPrices[10];
    int arrayDupli[10];
    /* int arrayDupliCode[10]; */

    arrayLoadProductCode(arrayProductCode, 10);
    arrayLoadProductPrice(arrayProductsPrices, 10);
    showArrays(arrayProductCode, arrayProductsPrices, 10);
    arrayDuplication(arrayProductsPrices, 10, arrayDupli);
    /* arrayDuplication(arrayProductCode,10,arrayDupliCode); */

    cout << "Precios ordenanos de forma descendente" << endl;
    orderDecendents(arrayProductsPrices, 10);
    showArrayShearchPos(arrayProductsPrices, arrayDupli, 10, arrayProductCode);

    cout << "Buscar un producto por codigo: ";
    int valueSearch;
    /*  cin>>valueSearch; */
    while (cin >> valueSearch && valueSearch != 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if (valueSearch == arrayProductCode[i])
            {
                cout << "codigo -> [" << valueSearch << "]" << " -> precio -> " << arrayDupli[i] << endl;
            }
        }
        cout << "Buscar un producto por codigo: ";
    }

    return 0;
}

void arrayLoadProductCode(int array[], const int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        array[i] = rand() % 999 + 1; // Genera un número aleatorio entre 1 y 999 como codigos de productos
    }
}

void arrayLoadProductPrice(int array[], const int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        array[i] = rand() % 10000 + 1; // Genera un número aleatorio entre 1 y 10000 como precios de productos
    }
}

void showArrays(int arrayOne[], int arrayTwo[], const int dim)
{
    cout << "Codigo" << " " << "Precio" << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << arrayOne[i] << "  :  " << arrayTwo[i] << endl;
    }
}

void orderDecendents(int array[], const int dim)
{
    int temp = 0;

    for (int k = 0; k < dim; k++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (array[j] < array[k])
            {
                temp = array[k];
                array[k] = array[j];
                array[j] = temp;
            }
        }
    }
}

void showArrayShearchPos(int array[], int arrayDuplicate[], const int dim, int arrayProductCode[])
{
    cout << "Codigo" << " " << "Precio" << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << "[" << searchArray(array[i], arrayDuplicate, dim, arrayProductCode) << "] : " << array[i] << endl;
    }
}

int searchArray(int value, int array[], const int dim, int arrayCodes[])
{

    for (int i = 0; i < dim; i++)
    {
        if (value == array[i])
        {
            return arrayCodes[i];
        }
    }
}

void arrayDuplication(int array[], const int dim, int arrayDupli[])
{

    for (int i = 0; i < dim; i++)
    {
        arrayDupli[i] = array[i];
    }
}