#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

double sinFunc(int n) {
	double sumTotal=0;
	for (int i = 1; i <= n; i++)
	{
		double sumStep = 0;
		int j = i;
		while (j)
		{
			sumStep += sin(j * PI / 180);
			j--;
		}
		sumTotal += 1 / sumStep;
	}
	return sumTotal;
}

int main()
{
	int n = 0;
	cout << "Input n: "; cin >> n;
	cout << sinFunc(n) << endl;

	return 0;
}

