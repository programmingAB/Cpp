/*
аписать программу преобразования десятичного числа в шестнадцатеричное.
*/

#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << "Input a number: "; cin >> number;
	cout << number;
	return 0;
}