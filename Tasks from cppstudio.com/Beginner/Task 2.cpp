/*
����������������� ��������� ���������: (� + b � f / �) + f * a * a � (a + b)
����� �, b, f �������� � ����������.
������������ ���������������� ���������, ����� �������, ����� ���� �������, � ����� ������� ������ ��������� �����.
*/

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 0, f = 0;
	cout << "������� ����� a, b, f" << endl;
	cin >> a >> b >> f;
	cout << "��������� �� �������: (� + b � f / �) + f * a * a � (a + b)" << endl;
	cout << "(" << a << " + " << b << " - " << f << " / " << a << ") + " << f << " * " << a << " * " << a << " � " << "(" << a << " + " << b << ")" << endl;
	cout << "��������� ����������: " << (a + b - f / a) + f * a * a - (a + b);
}