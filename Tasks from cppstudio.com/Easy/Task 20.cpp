/*
Составить программу табулирования функции y=ctg^2(lnx) на интервале [a,b] с шагом h
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double ln(double x);

int main()
{
	double a = 0, b = 0, interval=0;
	while (a == 0 || b == 0 || interval==0)
	{
		cout << "Ipnut a left value of bound of interval: "; cin >> a;
		cout << "Ipnut a right value of bound of interval: "; cin >> b;
		cout << "Ipnut a interval: "; cin >> interval;
	}
	cout << "-------------------------------------\n";
	cout << "Table of values " << a << "<=x<="<< b << endl;
	cout << "-------------------------------------\n";
	cout << "  x: " << "\t\ty: " << endl;
	for (a; a<=b; a += interval)
	{
		cout << left << setw(15) << setfill('.') << fixed << setprecision(2) << a << right;
		cout << pow(1 / tan(ln(a)), 2) << endl;
	}


}

double ln(double x)
{
	return log(x) / log(exp(1));
}