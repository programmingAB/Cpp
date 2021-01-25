/*
Составить программу-тест в MVS на языке программирования С++: 
на экране по очереди появляются вопросы (вопросы выбираются программистом), с вариантами ответов. 
В конце работы программа выдает количество заработанных баллов по результатам ответа.
*/

#include <iostream>
using namespace std;

int main()
{
	int answer = 0, score = 0;
	cout << "how many lives does a cat have" << endl;
	cout << "-> 5 lives\n-> 7 lives\n-> 9 lives\n";
	cout << "Your answer: "; cin >> answer;
	if (answer == 7)
		score++;
	cout << "How many cm means 1 meter?" << endl;
	cout << "-> 50 cm\n-> 70 cm\n-> 100 cm\n";
	cout << "Your answer: "; cin >> answer;
	if (answer == 100)
		score++;
	cout << "Speed of sound: " << endl;
	cout << "-> 343 m/s\n-> 326 m/s\n-> 241 m/s\n";
	cout << "Your answer: "; cin >> answer;
	if (answer == 343)
		score++;
	cout << "Your score: " << score << endl;
}