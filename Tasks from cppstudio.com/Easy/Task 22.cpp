/*
Найти след матрицы,  след матрицы — сумма элементов главной диагонали. 
Размер матрицы вводит пользователь, матрицу заполнять случайными числами.
*/

#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main()
{
	mt19937 gen;
	gen.seed(system_clock::now().time_since_epoch().count());
	int size = 0, sum=0;
	cout << "Input the size of the square matrix: "; cin >> size;
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	for (int i = 0; i < size; i++) // line
		for (int j = 0; j < size; j++) // column
			matrix[i][j] = gen() % 1000;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(3) << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) // line
		for (int j = 0; j < size; j++) // column
			if (i==j)
				sum+=matrix[i][j];
	cout << endl << "Sum: "<<sum << endl;

	for (int i=0; i<size; i++)
		delete []matrix[i];

	return 0;
}


