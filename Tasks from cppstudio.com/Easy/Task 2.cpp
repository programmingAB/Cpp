/*
Найти алгебраическую сумму для выражения: 1k + 2k + 3k + … + Nk. N и степень k вводит пользователь. 
*/

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

int main()
{
	setlocale(LC_ALL, "Russian");
	int N = 0, sum=0, k=0;
	cout << "Введите N: ";
	cin >> N;
	cout << "Введите k: ";
	cin >> k;
	for (int i = 1; i <= N; i++)
		sum += pow(i, k);
	cout << "Сумма: " << sum;
	return 0;
}