/*
Разработать функцию, в которую передаются в качестве аргументов массив типа float и его размер. 
Функция должна возвращать среднее арифметическое элементов массива.
*/

#include <iostream>
using namespace std;

float avgArr(float*, int&);

int main()
{
	int size = 0;
	cout << "Input size of an array: "; cin >> size;
	float* arr = new float[size];
	for (int i = 1; i <= size; i++)
	{
		cout << "Number "<<i<<": ";
		cin >> arr[i];
	}
	cout<<"Average: "<<avgArr(arr, size)<<endl;
	return 0;
}

float avgArr(float* arr, int &size)
{
	float sum = 0, divisor=size;
	while (size)
	{
		sum += arr[size];
		size--;
	}
	return (float)(sum / divisor);
}

