/*
Составить программу, которая будет печатать ромб одним из значков (* или + или #) 
Выбор значков организовать оператором switch.
*/

#include <iostream>
using namespace std;

int main()
{
	int a=0, b=0, c=0, openingA=0, openingB=0;
	cout << ".....a >= b >= c.....||.....lenght of the opening >= height....."<<endl; 
	while (true)
	{
		cout << "Input the length (a): "; cin >> a;
		cout << "Input the width (b): "; cin >> b;
		cout << "Input the height (c): "; cin >> c;
		cout << "Enter the lenght of the opening (a): "; cin >> openingA;
		cout << "Enter the height of the opening (b): "; cin >> openingB;
		if (((a >= b) or (a >= c) or (b >= c)) and (openingA>=openingB))
			break;
		cout << "Input is incorrect. Try again" << endl;
	}
	if (((a <= openingA) and (b <= openingB)) or ((b <= openingA) and (a <= openingB)))
		cout << "The first, second and third side of the brick pass into opening";
	else if ( ((a <= openingA) and (c <= openingB)) or ((c <= openingA) and (a <= openingB)) )
		cout << "The first and the second side of the brick pass into opening";
	else if ( ((b <= openingA) and (c <=openingB)) or ((c <= openingA) and (b <= openingB)) )
		cout<<"The first side of the brick pass into opening";
	return 0;
}