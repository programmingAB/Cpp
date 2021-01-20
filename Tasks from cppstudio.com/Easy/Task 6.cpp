/*
Суть задачи: по введенному номеру дня недели вывести его название, используя оператор множественного выбора. 
Нумерация дней недели начинается с 1 – понедельник, 2 — вторник и т. д.
*/

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int nummer;
	cout << "1. Понедельник\n"
			"2. Вторник\n"
			"3. Среда\n"
			"4. Четверг\n"
			"5. Пятница\n"
			"6. Суббота\n"
			"7. Воскресение\n"
			"Введите номер дня недели: "; cin >> nummer;
	switch (nummer)
	{
	case 1:
		cout << "Понедельник";
		break;
	case 2:
		cout << "Вторник";
		break;
	case 3:
		cout << "Среда";
		break;
	case 4:
		cout << "Четверг";
		break;
	case 5:
		cout << "Пятница";
		break;
	case 6:
		cout << "Суббота";
	case 7:
		cout << "Воскресение";
		break;
	default:
		cout << "День недели с таким номером не существует\n";
		break;
	}
	return 0;

}

