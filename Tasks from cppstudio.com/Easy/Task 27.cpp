/*
— помощью оператора цикла for, разработать программу, котора€ будет выводить 
таблицу умножени€ введенного пользователем числа с клавиатуры.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 0;
	cout << "Input a number: "; cin >> a;
	for (int i = 1; i <= 10; i++)
		cout  << a << "  * " << setw(2) << i <<"  =  " << a * i << endl;
	return 0;
}

