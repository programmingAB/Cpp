/*
Требуется вывести в консоль от 1-го до 6-ти равнобедренных треугольников, в зависимости от того какое число введет пользователь. 
Например, если на вход в программу будет отправлено число 3, то необходимо напечатать 3 треугольника, 
если пользователь введет 6, то напечатать 6-ть треугольников. 
Треугольники нужно выводить не в столбик, а в строчку. При этом размер треугольников также формируется по введенному пользователем числу. Как я и говорил, если пользователь введет число 3, то должно напечататься три равнобедренных треугольника, высота которых равна — 3-м. 
Для печати треугольников можно выбрать любой символ, как вам удобно, в существующем решении используется символ звездочки — *.
*/

#include <iostream>
using namespace std;

class triangles
{
public:
	int numberOfTriangles;
	int lengthOfTriangle(int);

	void printT();
	triangles(int n) { numberOfTriangles = n; };
};



int main()
{
	int n=0;
	cout << "Enter number of triangles: "; cin >> n;
	triangles first(n);
	first.printT();
	return 0;
}

int triangles::lengthOfTriangle(int n)
{
	if (n==1)
		return 1;
	else
		return 2 + lengthOfTriangle(n - 1);
}

void triangles::printT()
{
	int lengthOfField = lengthOfTriangle(numberOfTriangles)* numberOfTriangles +(numberOfTriangles -1);
	int* Tops_of_triangels = new int[numberOfTriangles];
	Tops_of_triangels[0] = numberOfTriangles -1; // первая верхняя левая вершина
	for (int i = 1; i < numberOfTriangles; i++)
		Tops_of_triangels[i] = Tops_of_triangels[i-1] + numberOfTriangles * 2 ;
	for (int q=0; q< numberOfTriangles; q++)
	{
		for (int i = 0; i < lengthOfField; i++)
		{
			for (int j = 0; j < numberOfTriangles; j++)
			{
				for (int a = Tops_of_triangels[j] - q; a <= Tops_of_triangels[j] + q; a++)
				{
					if (i == a) 
					{
						cout << "*";
						i++;
					}
				}
			}
			cout << " ";
		}
		cout << endl;
	}
}