#include <iostream>
/* Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados), se pide
determinar el/los empleados de máximo sueldo
a) Los números de legajo son números correlativos de 1 a 100
b) Los números de legajo son números no correlativos de 4 cifras.

Consideramos que no se repiten
*/
using namespace std;

void showArrays(int[], int[], const int);
int loadArrays(int[], int[]);
int higherSalary(int[], const int);
int main()
{
    const int dim = 100;
    int legArray[dim];
    int salArray[dim];

    int qualityDim = loadArrays(legArray, salArray);

    cout << "---------------------------" << endl;
    cout << "Mostrando vectores: " << endl;
    showArrays(legArray, salArray, qualityDim);

    int pos = higherSalary(salArray, qualityDim);
    
    cout << "---------------------------" << endl;
    cout << "El mayor salario es: " << salArray[pos - 1] << " -> legajo: " << legArray[pos - 1] << endl;

    return 0;
}

int higherSalary(int v1[], const int dim)
{
    int mayor = 0;
    int count = 0;
    for (int j = 0; j < dim; j++)
    {
        if (mayor <= v1[j])
        {
            mayor = v1[j];
        }
        count++;
    }
    return count;
}

void showArrays(int v1[], int v2[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Legajo -> " << v1[i] << "    Sueldo -> " << v2[i] << endl;
    }
}

int loadArrays(int v1[], int v2[])
{
    int leg, i = 0;
    cout << "Legajo: ";
    cin >> leg;
    while (leg != 0)
    {
        v1[i] = leg;
        cout << "Salario: ";
        cin >> v2[i];
        cout << "Legajo: ";
        cin >> leg;

        i++;
    }
    return i;
}