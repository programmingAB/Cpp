/*
»спользу€ оператор цикла do while, составить программу, котора€ будет требовать ввод цифр с клавиатуры до тех пор, 
пока не будет введена цифра 1.
*/

#include <iostream>
using namespace std;

int main()
{
	int b = 0, sum=0;
	cout << "Input the right bound of interval: "; cin >> b;
	while (b % 5 != 0)
		b--;
	while (b)
	{
		sum += b;
		b -= 5;
	}
	cout << "Sum: " << sum << endl;
	return 0;
}

