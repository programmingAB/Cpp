/*
Используя показатели функции вычислить цепную дробь. 
Количество елементов дроби надо задавать с клавиатуры.
*/

#include <iostream>
using namespace std;

double funcFraction(int n, double sum)
{
	if (n == 1)
		return sum;
	else
		return funcFraction(n - 1, 1 + 1 / sum);
}

double funcFraction2(int n)
{
	static double sum = 2;
	if (n == 1)
		return sum;
	else
		return funcFraction(n - 1, 1 + 1 / sum);
}

double funcFraction3(int n)
{
	double sum = 2;
	while (n-1)
	{
		sum = 1 + 1 / sum;
		n--;
	}
	return sum;
}

int main()
{
	int n = 0;
	cout << "Input n: "; cin >> n;
	//cout << funcFraction(n, 2);
	//cout << funcFraction2(n);
	cout << funcFraction3(n);
	return 0;
}