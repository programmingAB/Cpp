/*
В текстовом файле, содержащем текст программы на языке Си, проверить соответствие открывающихся и закрывающихся фигурных скобок { и }.
Результат проверки вывести на экран и записать в виде фразы в текстовый файл. 
Результат работы программы (вывод) поместить в отдельный текстовый файл (например, "out . txt " ), продублировав на экране.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int left_brackets = 0, right_brackets =0;
	char buff[100];
	ifstream Ifile("in.txt", ios_base::in);
	ofstream Ofile("out.txt");

	if (!Ifile)
	{
		cout << "In.txt can't be opened.";
		return 0;
	}

	while (Ifile.getline(buff, 100))
	{
		//cout << buff << endl;
		int i = 0;
		while (*(buff + i)!='\0')
		{
			if (*(buff + i) == '{')
				left_brackets++;
			else if (*(buff + i) == '}')
				right_brackets++;
			i++;
		}
	}
	Ifile.close();
	Ofile << "Count of left brackets: "<< left_brackets << endl << "Count of right brackets: " << right_brackets <<endl;
	Ofile.close();
	return 0;
}