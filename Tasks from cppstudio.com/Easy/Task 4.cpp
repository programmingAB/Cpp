
/*
Напишите программу , в которой по извесной начальной скорости V и времени полета тела T
определяется угол aльфа под которым тело брошено по отношению к горизонту
(воспользуйтесь соотношением a = arcsin(gT/2V) ).
*/

#include <iostream>
#include <cmath>
using namespace std;

#define g 9.8

int main()
{
	setlocale(LC_ALL, "Russian");
	int V = 0, T = 0;
	cout << "Введите V: ";
	cin >> V;
	cout << "Введите T: ";
	cin >> T;
	cout << "Угол: " << asin(g * T / (2 * V)) * 180 / 3.14;
	return 0;
}