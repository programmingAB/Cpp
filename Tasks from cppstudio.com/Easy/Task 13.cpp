/*
—оставить алгоритм определ€ющий, 
есть ли среди цифр введенного трехзначного числа Ч одинаковые. 
„исло вводитс€ с клавиатуры.
*/

#include <iostream>
using namespace std;

int main()
{
	int tD_number = 0;
	int n1=0, n2=0, n3=0;
	cout << "Input a three-dight number: "; cin >> tD_number;
	n1 = tD_number / 100;
	n2 = (tD_number / 10) % 10;
	n3 = tD_number % 10;
	if (n1 == n2 or n1 == n3 or n2 == n3)
		cout << "The number has identical figures";
	else
		cout << "The number doesn't have identical figures";
	return 0;
}