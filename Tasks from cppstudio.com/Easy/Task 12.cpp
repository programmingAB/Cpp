/*
ќпределить номер четверти плоскости, в которой находитс€ точка с координатами X и Y , 
причем XY != 0.  оординаты вводить с клавиатуры.
*/

#include <iostream>
using namespace std;

int main()
{
	int X=0, Y = 0;
	do {
		cout << "Input X: ";	cin >> X;
		cout << "Input Y: ";	cin >> Y;
		if (!(X * Y))
			cout << "False input. Try again"<<endl;
	} while (!(X * Y));
	if (X > 0 && Y > 0)
		cout << "Quadrant I";
	else if (X > 0 && Y < 0)
		cout << "Quadrant II";
	else if (X < 0 && Y < 0)
		cout << "Quadrant III";
	else
		cout << "Quadrant IV";
	return 0;
}