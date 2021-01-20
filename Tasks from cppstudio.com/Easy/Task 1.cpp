/*
Найти Y, если Y = X1 + X2 + … + Xn,   X = Z^3 - B + A^2 / tg^2?.
Количество X вводятся пользователем программы.
Для каждого X значения Z, B, А, ? разные (вводятся пользователем программы).
*/

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

int main()
{
	setlocale(LC_ALL, "Russian");
	int countX=0;
	cout << "Количество Х: ";
	cin >> countX;
	double* mass = new double[countX];
	double summe = 0;
	for (int i = 0; i < countX; i++)
	{
		double Z=0, B=0, A=0, Be=0; //Be - угол в градусах
		cout << "Введите значения для X" << i+1 << endl;
		cout << "Z: "; cin >> Z;
		cout << "B: "; cin >> B;
		cout << "A: "; cin >> A;
		cout << "Betta (радианы): "; cin >> Be;
		mass[i] = pow(Z, 3) - B + pow(A, 2) / pow(tan(Be /** PI / 180*/), 2);
		summe += mass[i];
	}
	cout << summe << endl;


	return 0;
}