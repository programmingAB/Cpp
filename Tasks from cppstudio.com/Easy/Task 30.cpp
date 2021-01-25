/*
»спользу€ оператор цикла do while, составить программу, котора€ будет требовать ввод цифр с клавиатуры до тех пор, 
пока не будет введена цифра 1.
*/

#include <iostream>
using namespace std;

int main()
{
	double number=0;
	do
	{
		cout << "Input 1: "; cin >> number;
	} while (number != 1);
	return 0;
}

