#include <iostream>

/*
Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota
*/
using namespace std;

void arrayLoadNotes(int[], const int);
void arrayLoadDocument(int[], const int);
void showArray(int[], const int);

int main()
{
    const int dim = 12;
    int arrayNotes[dim];
    int arrayDocument[dim];

    arrayLoadNotes(arrayNotes, dim);
    arrayLoadDocument(arrayDocument, dim);
    cout << "Notas: " << endl;
    showArray(arrayNotes, dim);
    cout << "Documentos: " << endl;
    showArray(arrayDocument, dim);

    int aux;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if(arrayNotes[j] < arrayNotes[i]){
                aux = arrayNotes[i];
                arrayNotes[i] = arrayNotes[j];
                arrayNotes[j] = aux;
            }
        }
    }
    cout<<"Alumnos de "
    showArray(arrayNotes, dim);

    return 0;
}

void showArray(int array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "[" << i << "] : " << array[i] << endl;
    }
}

void arrayLoadNotes(int array[], const int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        array[i] = rand() % 10 + 1;
    }
}

void arrayLoadDocument(int array[], const int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        array[i] = rand() % 99999999 + 10000000;
    }
}