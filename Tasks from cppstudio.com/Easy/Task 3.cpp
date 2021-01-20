/*
Организовать ввод двухзначного натурального числа с клавиатуры.
Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.
*/

#include <iostream>
//#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int number = 0, n1 = 0, n2 = 0;;
	cout << "Введите число: "; cin >> number;
	n1 = number / 10;
	n2 = number % 10;
	if (n1 > n2)
		cout << n1 << " - большая цифра" << endl << n2 << " - меньшая цифра";
	else if (n1 < n2)
		cout << n2 << " - большая цифра" << endl << n1 << " - меньшая цифра";
	else
		cout << "Цифры равны";
	return 0;
}
