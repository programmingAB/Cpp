/*
Вычислить значение выражения по формуле (все переменные принимают действительные значения):
(1-tg x)^(ctg x)+ cos(x-y).
*/

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

int main()
{
	setlocale(LC_ALL, "Russian");
	double angleX = 0, angleY = 0, answer = 0;
	cout << "Input the angle X in degrees: "; cin >> angleX;
	cout << "Input the angle Y in degrees: "; cin >> angleY;
	answer = pow((1 - tan(angleX * PI / 180)), 1 / tan(angleX * PI / 180)) + cos(PI / 180 * (angleX - angleY));
	cout << "Answer: " << answer;
	return 0;
}
