/*
Запрограммировать генератор псевдослучайных чисел, 
используя конгруэнтный метод формирования псевдослучайных чисел.
*/

#include <iostream>
#include <iomanip>
using namespace std;



const int nu = 354;
int a = 12;
int yi = 2;
int m = 1651;
int numOfRand = 20;

double pseudo_random();

int main()
{
	cout << "pseudo-random numbers: ";
	for (int i=0; i<numOfRand; i++)
		cout << setprecision(2) << pseudo_random() << endl;
	return 0;
}

double pseudo_random()
{
	double ynP1 = ((a*yi)+nu) % m;
	double n = ynP1 / m;
	yi = ynP1;
	return n;
}