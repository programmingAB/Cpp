/*
»спользу€ один оператор вывода cout, программа должна напечатать пр€моугольный треугольник из символов знака плюс +
*/

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int lineCount = 0;
	cout << "¬ведите количество ""строк"" треугольника: ";
	cin >> lineCount;
	for (int i = 1; i <= lineCount; i++)
	{
		int j = 1;
		while (j <= i)
		{
			cout << "+";
			j++;
		}
		cout << endl;
	}
}