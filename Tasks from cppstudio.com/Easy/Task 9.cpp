/*
Вычислить значение выражения по формуле (все переменные принимают действительные значения): 
(1-tg x)^(ctg x)+ cos(x-y).
*/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int length = 0;
	double sum = 0;
	cout << "Input the lenght of the mass: "; cin >> length;
	double* mass = new double[length];
	for (int i = 0; i < length; i++)
	{
		cin >> *(mass + i);
		if (abs(*(mass + i)) > 2.5)
			continue;
		sum += pow(*(mass + i), 2);
	}
	//for (int i = 0; i < length; i++)
	//{
	//	if (abs(*(mass + i)) > 2.5)
	//		continue;
	//	sum += pow(*(mass + i),2);
	//}
	cout << sum << endl;
	delete[] mass;
	return 0;
}

