/*
ѕрограмма должна переводить число, введенное с клавиатуры в метрах, в километры.
*/

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double meter, km;
	do {
		cout << "¬ведите метры: ";
		cin >> meter;
		km = meter / 1000;
		// 1 вариант -  toupper();
		// cout<<char(toupper(letter);
		// 2 вариант
		cout << "ѕеревод в километры: " << endl;
		if (meter > 0 && meter < 1)
			cout << meter << " метра - " << km << " километра" << endl;
		else if (meter == 1)
			cout << meter << " метр - " << km << " километра" << endl;
		else if (meter > 1 && meter < 5)
			cout << meter << " метра - " << km << " километра" << endl;
		else if (meter >= 5 && meter < 1000)
			cout << meter << " метров - " << km << " километра" << endl;
		else if (meter > 1000)
			cout << meter << " метров - " << km << " километров" << endl;

	} while (meter != -1);
}