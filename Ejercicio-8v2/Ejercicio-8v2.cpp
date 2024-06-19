#include <iostream>
/*Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
  a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
  b) Dado un código de producto informar su precio.
*/
using namespace std;

void addValueProduct(int[], int[], const int);
void showArrays(int[], int[], const int);
void descendingOrderByprice(int[], int[], const int);
int searchCode(int[], const int, int);

int main()
{
    const int dim = 10;
    int posCode = 0;
    int productCode[dim];
    int productPrice[dim];

    addValueProduct(productCode, productPrice, dim);

    cout << "Mostrando vectores: " << endl;
    showArrays(productCode, productPrice, dim);

    descendingOrderByprice(productCode, productPrice, dim);

    cout << "----------------------------------" << endl;
    cout << "Ordenamiento de forma descendente: " << endl;
    showArrays(productCode, productPrice, dim);

    cout << "----------------------------------" << endl;
    cout << "Digite un codigo para buscar: ";
    int valueSearch;
    while (cin >> valueSearch && valueSearch != 0)
    {
        posCode = searchCode(productCode, dim, valueSearch);
        cout << "Codigo: " << productCode[posCode] << " - Precio: " << productPrice[posCode] << endl;
        cout << "Digite un codigo para buscar: ";
    }

    return 0;
}

int searchCode(int v[], const int dim, int value)
{
    int posValue = 0;
    for (int i = 0; i < dim; i++)
    {
        if (v[i] == value)
        {
            posValue = i;
        }
    }
    return posValue;
}

void descendingOrderByprice(int v1[], int v2[], const int dim)
{
    int higher = 0, pos = 0;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (v2[j] > v2[i])
            {
                higher = v2[i];
                v2[i] = v2[j];
                v2[j] = higher;

                pos = v1[i];
                v1[i] = v1[j];
                v1[j] = pos;
            }
        }
    }
}

void addValueProduct(int v1[], int v2[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        v1[i] = rand() % 999 + 1;
        v2[i] = rand() % 10000 + 1;
    }
}

void showArrays(int v1[], int v2[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Codigo -> " << v1[i] << "    Precio -> " << v2[i] << endl;
    }
}