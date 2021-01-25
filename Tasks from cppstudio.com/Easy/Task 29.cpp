/*
рограмма провер€ет, €вл€етс€ ли введенное с клавиатуры число Ч целым числом.*/

#include <iostream>
using namespace std;

int main()
{
	double number;
	cout << "Input a number: "; cin >> number;
	if (number - (int)number == 0)
		cout << "Integral number";
	else
		cout << "Nointeger";
	return 0;
}

