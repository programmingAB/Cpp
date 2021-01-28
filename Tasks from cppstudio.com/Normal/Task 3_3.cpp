/*
Нужно вычислить произведение матрицы на вектор. В полученном векторе найти макисмальный  элемент. необходимо решить данную задачу тремя способами:

    с использованием статических массивов
    использовать только динамические массивы с явным разыменованием указателя
    использовать только динамические массивы, адресацию к элементам массива выполнять с помощью индексов.

То есть, у вас должно получиться три отдельных исходника — три программы. Пример работы программы смотрите ниже.
*/

#include <iostream>
using namespace std;

int main()
{
    int rowsOfMatrix = 0, columnsOfMatrix = 0, rowsOfVector = 0, rowsOfVectorResult = 0;
    

    cout << "Input a count of rows in the matrix: "; cin >> rowsOfMatrix;
    cout << "Input a count of colums in the matrix: "; cin >> columnsOfMatrix;
    rowsOfVector = columnsOfMatrix;
    rowsOfVectorResult = rowsOfMatrix; // согласно правилу умножения
    int **matrix=new int*[rowsOfMatrix];
    for (int i = 0; i < rowsOfMatrix; i++)
        matrix[i] = new int[columnsOfMatrix];
    int *vector=new int[rowsOfVector];
    int *vectorRes=new int[rowsOfVectorResult];
    cout << "Input matrix[row][column]\n";
    for (int i = 0; i < rowsOfMatrix; i++)
    {
        for (int j = 0; j < columnsOfMatrix; j++)
        {
            cout << "Input matrix[" << i+1 << "]" << "[" << j+1 << "]\n";
            cin >> matrix[i][j];
        }
    }
    cout<<"Matrix["<<rowsOfMatrix<<"]["<<columnsOfMatrix<<"]\n";
    for (int i = 0; i < rowsOfMatrix; i++)
    {
        for (int j = 0; j < columnsOfMatrix; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int v = 0; v < rowsOfVector; v++)
    {
        cout << "Vector[" << v+1 << "]\n";
        cin >> vector[v];
    }

    cout << "Vector["<<rowsOfVector<<"]" << endl;
    for (int v = 0; v < rowsOfVector; v++)
        cout << vector[v] << endl;
    
    for (int i = 0; i < rowsOfVectorResult; i++)
        vectorRes[i]=0;

    for (int i = 0; i < rowsOfVectorResult; i++)
        for (int j = 0; j < columnsOfMatrix; j++)
            vectorRes[i] += matrix[i][j] * vector[j];

    for (int i = 0; i < rowsOfMatrix; i++)
        delete[] matrix[i];

    delete[] vector;


    cout << endl;
    cout << "Matrix[" << rowsOfMatrix << "][" << columnsOfMatrix << "] * vector[" << rowsOfVector <<"] = " << endl;
    for (int i = 0; i < rowsOfVectorResult; i++)
        cout << vectorRes[i] << endl;
    delete[] vectorRes;

}