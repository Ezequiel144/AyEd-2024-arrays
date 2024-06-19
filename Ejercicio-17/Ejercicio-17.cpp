#include <iostream>
/*En un comercio se ingresan los datos de las ventas realizadas en el día. Por cada una se ingresa
número de factura, código de vendedor que realizó la venta (de 1 a 25) e importe de la misma. El
lote de datos finaliza con número de factura cero. Se pide desarrollar un algoritmo que:
- Imprima un listado ordenado por código de vendedor, detallando el importe total de ventas de
cada uno de ellos
- Dado un código de vendedor, imprima la cantidad de ventas realizadas por el mismo

Arrays:
- VentasPorDia (7) ¿?
- NumeroDeFacturas (1-25)
- CodigoDeVendedor (1-25)
- Importe
Info Destacado:
- Finaliza el ingreso de datos con el numero de factura es 0
- Codigo de vendedor de 1 a 25
Pide:
- Mostrar un listado ordenado por codigo de vendedor y detallar el importe total de ventas de cada uno de ellos
- Pedir un codigo de vendedor para mostrar la cantidad de ventas realizadas

*/

using namespace std;

void showArrays(int array1[], int array2[], int array3[], int dim);
int enterData(int array1[], int array2[], int array3[]);
void sortBySelleCode(int array1[], int array2[], int array3[], int dim);
void searchBySellerCode(int array1[], int array2[], int array3[], int dim);

int main()
{
    int invoiceNumber[100]; // Numero de factura //
    int sellerCode[100];    // Codigo de vendedor //
    int amount[100];        // Importe //
    int dim;

    dim = enterData(invoiceNumber, sellerCode, amount);
    cout << "------------------------------" << endl;
    cout << "Mostrando Datos" << endl;
    showArrays(invoiceNumber, sellerCode, amount, dim);

    sortBySelleCode(invoiceNumber, sellerCode, amount, dim);
    cout << "------------------------------" << endl;
    cout << "Datos ordenados por codigo de vendedor" << endl;
    showArrays(invoiceNumber, sellerCode, amount, dim);

    cout << "------------------------------" << endl;
    searchBySellerCode(invoiceNumber, sellerCode, amount, dim);

    return 0;
}

void searchBySellerCode(int array1[], int array2[], int array3[], int dim){
    int valueSellerCode = 0;
    int valueReturn;
    cout << "Ingresar codigo de vendedor para la busqueda: ";
    cin >> valueSellerCode;
    while (valueSellerCode != 0)
    {
        for (int i = 0; i < dim; i++)
        {
            if (array2[i] == valueSellerCode)
            {
                valueReturn = i; // Devuelve la posicion del array //
                cout << "Factura -> " << array1[valueReturn] << "   Vendedor -> " << array2[valueReturn] << "   Importe -> " << array3[valueReturn] << endl;
            }
        }
        cout << "Ingresar codigo de vendedor para la busqueda: ";
        cin >> valueSellerCode;
    }
}

void sortBySelleCode(int array1[], int array2[], int array3[], int dim)
{
    int aux1, aux2, aux3;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (array1[i] > array1[j])
            {
                aux1 = array1[i];
                array1[i] = array1[j];
                array1[j] = aux1;

                aux2 = array2[i];
                array2[i] = array2[j];
                array2[j] = aux2;

                aux3 = array3[i];
                array3[i] = array3[j];
                array3[j] = aux3;
            }
        }
    }
}

int enterData(int array1[], int array2[], int array3[])
{
    int i;
    int saveNumber;
    int quality = i + 1;
    cout << "Ingresar Datos: " << endl;
    for (i = 0; i < quality; i++)
    {
        cout << "Numero de factura: ";
        cin >> saveNumber;
        if (saveNumber == 0)
        {
            quality = i;
            break;
        }
        array1[i] = saveNumber;
        cout << "Codigo de vendedor: ";
        cin >> array2[i];
        cout << "Importe: ";
        cin >> array3[i];
        quality++;
    }
    return i;
}

void showArrays(int array1[], int array2[], int array3[], int dim)
{

    for (int i = 0; i < dim; i++)
    {
        cout << "Factura -> " << array1[i] << "   Vendedor -> " << array2[i] << "   Importe -> " << array3[i] << endl;
    }
}
