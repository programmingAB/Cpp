/*
Ќапишите программу, котора€ позвол€ет пользователю ввести в консоли латинскую букву нижнего регистра, 
переводит еЄ в верхний регистр и результат выводит в консоль.
*/

#include <iostream>
using namespace std;

int main()
{
	char letter;
	cin >> letter;
	// 1 вариант -  toupper();
	// cout<<char(toupper(letter);
	// 2 вариант
	if (letter >= 'a' && letter <= 'z')
		cout << char(letter+('A'-'a')); // или же letter-('a'-'A')
}