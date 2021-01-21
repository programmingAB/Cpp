/*
Составить программу, которая будет печатать ромб одним из значков (* или + или #)
Выбор значков организовать оператором switch.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int choose=0, hight = 0;
	char symbol;
	cout << "Choose the symbol: \n1 - *\n2 - +\n3 - #\n";

	while (true)
	{
		cin >> choose;
		switch (choose)
		{
		case 1:
			symbol = '*';
			break;
		case 2:
			symbol = '+';
			break;
		case 3:
			symbol = '#';
			break;
		default:
			cout << "Input is incorrect\n";
			continue;
		}
		break;
	}

	cout << "Input the hight = width of the rhombus (a odd number): "; cin >> hight;
	const int pos = hight / 2 + 1;
	for (int j = -hight/2; j <= hight / 2; j++)
	{
		int pos1 = pos - (hight / 2- abs(j));
		int pos2 = pos + (hight / 2 - abs(j));
		for (int i = 1; i <= hight; i++)
		{
			if (i == pos1 || i == pos2)
				cout << symbol;
			else
				cout << " ";
		}
		cout << endl;
	}
		return 0;
}