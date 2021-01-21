/*
—оставить алгоритм определ€ющий, 
есть ли среди цифр введенного трехзначного числа Ч одинаковые. 
„исло вводитс€ с клавиатуры.
*/

#include <iostream>
using namespace std;

int main()
{
	char ch[100] = "12345 \n12345\n12345 \n12345\n12345 \n12345\n12345 \n12345\n#";
	int i = 0, countNewLine = 0;
	while (ch[i] != '#')
	{
		if (*(ch + i) == '\n')
			countNewLine++;
		i++;
	}
	cout << "Count of new lines: " << countNewLine;
	return 0;
}