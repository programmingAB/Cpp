/*
Вычислить, не используя функцию pow, значения функции z(x,m) = x^m sin^m(xm), для значений аргументов:
	x от -1.1 до 0.3 с шагом 0.2;
	m от 1 до 5 с шагом 1.
*/

#include <iostream>
#include <cmath>
using namespace std;

//int ifEqualPower = 1;

int main()
{
	setlocale(LC_ALL, "Russian");
	for (double d=-1.1; d<0.3; d+=0.2)
	{
		cout << "x = " << d << endl;
		for (int power = 1; power < 5; power++)
		{
			static int ifEqualPower;
			ifEqualPower = 1;
			double partLeft = d; // хранит в себе переменную d в степени 1, используется для сохранения d в степени power
			double partRight = sin(d*power); // аналогично partRight, только для "правой части" выражения

			while (power > ifEqualPower)
			{
				partLeft *= d;
				partRight *= sin(d * power);
				ifEqualPower++;
			}
			cout << "Значение функции = " << partLeft * partRight <<" При m = "<<power<< endl;
		}
		cout << "----------------------------------\n";
	}
	return 0;
}

