/*
Программа должна, в качестве входных данных, 
принимать пятизначные числа и определять, является ли введенное пятизначное число палиндромом.
*/

#include <iostream>
#include <cmath>
using namespace std;

int lengthNum(int num);

int main()
{
	bool isPalindrome = false;
	int number = 0, count=0;
	cout << "Input a number: "; cin >> number;
	count = lengthNum(number);
	int i = 0; // считаем до какого i дошла программа. Если i == count / 2 - число палиндром
	for (i = 0; i < count / 2; i++)
	{
		int n1 = (int)(number / pow(10, count- 1 - i)) % 10;
		int n2 = (int)(number / pow(10, i)) % 10;
		if (n1 != n2)
			break;
	}
	if (i == count / 2)
		cout << "Pal";
	return 0;
}

int lengthNum(int num)
{
	int count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return count;
}