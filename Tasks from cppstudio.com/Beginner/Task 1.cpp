/*
Составить программу, которая будет считывать введённое число. 
После чего, каждую цифру этого числа необходимо вывести в новой строке.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int number;
	string strNumber;
	cin >> strNumber;
	number = stoi(strNumber);
	for (int i = 1; i < strNumber.length()+1; i++)
		cout << (int)(number / pow(10, strNumber.length() - i)) % 10 << endl;
}