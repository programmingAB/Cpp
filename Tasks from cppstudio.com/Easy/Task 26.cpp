/*
ѕрограмма должна выводить таблицу квадратов чисел от 1 до 5 (необходимо использовать табул€цию и перенос на новую строку, 
см. управл€ющие символы). ¬ первом столбце должны находитьс€ числа от 1 до 5 во втором столбце Ч квадраты этих чисел.
*/

#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cout << "Input the left and the right bounds of interval: "; cin >> a; cin >> b;
	cout << "Number" << "\t\t" << "Square\n";
	cout << "------" << "\t\t" << "-------\n";
	while (a != b+1)
	{
		cout << a << "\t\t" << a * a<<"\n";
		++a;
	}
	return 0;
}

