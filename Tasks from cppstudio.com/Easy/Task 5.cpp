/*
Возвести, введенное с клавиатуры число, в степень n, 
степень тоже вводится с клавиатуры. Возведение в степень организовать с использованием циклов.
*/

#include <iostream>
//#include <cmath>
using namespace std;

int funcPower1(int numF, int powF);
int funcPower2(int numF, int powF);
//#define g 9.8

int main()
{
	setlocale(LC_ALL, "Russian");
	int number=0, pow=0;
	cout << "Введите число: "; cin >> number;
	cout << "Введите степень: "; cin >> pow;
	//cout << funcPower1(number, pow) << endl;
	cout << funcPower2(number, pow);
	return 0;
}

int funcPower1(int numF, int powF)
{
	if (powF == 1)
		return numF;
	else
		return numF * funcPower1(numF, powF - 1);
}

int funcPower2(int numF, int powF)
{
	int temp = numF;
	for (int i = 1; i < powF; i++)
	{
		temp *= numF;
	}
	return temp;
}