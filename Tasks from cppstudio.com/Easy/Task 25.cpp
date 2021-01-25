/*
С помощью цикла while разработать программу, которая будет вычислять сумму чисел нацело делящихся на 5. 
Цикл задать от 0 до введенного с клавиатуры числа.
*/

#include <iostream>
using namespace std;


int main()
{
	int n = 0, sum=0;
	cout << "Input a right bounds of interval: "; cin >> n;
	while (n % 5 != 0)
		n--;
	while (n)
	{
		sum += n;
		n -=5;
	}
	cout << "Sum: " << sum;
	return 0;
}

