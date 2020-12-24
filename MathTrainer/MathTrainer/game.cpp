#include "game.h"


void Game::gameMenuMain()
{
	char option;
	if (name.empty())
	{
		cout << "Welcome! Write please your name.\n";
		cin >> name;
		system("cls");
	}

	do {
		char optionMass[256];
		const string optionValues = "12340pbahePBAHE";
		if (cleanscr)
			system("cls");
		if (printName)
		{
			cout << "Hello, " << name << "!" << endl;
			printName = !printName;
		}
			cout << "Select the option\n"
			"1 ---> (p)lay game\n"
			"2 ---> (b)est score\n"
			"3 ---> (a)bout this game\n"
			"4 ---> (h)elp\n"
			"0 ---> (e)xit\n"
			<< endl;
		cout << "Make a option\n";
		cin >> optionMass;
		if (count(optionValues.begin(), optionValues.end(), optionMass[0]) != 0) //Проверка на входимость введенного символа option в набор допустимых символов в optionValues, при этом
		{
			option = optionMass[0];
			break;
		}															 //нас интересует только первый символ в массиве
		system("cls");
	} while (true);
	switch (option)
	{
	case '1':
	case 'p':
	{
		gameMenuPlay();
		break;
	}
	case '2':
	case 'b':
	{
		system("cls");
		cout << "Best Score\n";
		cleanscr = false;
		bestScore();
		break;
	}
	case '3':
	case 'a':
		system("cls");
		cout << "This is a simlpe game...\n\n";
		cleanscr = false;

		gameMenuMain();
		break;
	case '4':
	case 'h':
		system("cls");
		cleanscr = false;
		cout <<
			"------------------------\n"
			"1 wrong answer = -1 live\n"
			"3 right answer = +1 live\n"
			"right answer -------->\n"
			"easy game: -> +5 seconds\n"
			"normal game: -> +10 seconds\n"
			"hard game: -> +20 seconds\n"
			"------------------------\n\n";
		gameMenuMain();
		break;
	case '0':
	case 'e':
		break;

		
	};
}

void Game::gameMenuPlay()
{
	char option;
	do {
		char optionMass[256];
		const string optionValues = "1230enhbENHB";
		system("cls");
		cout << "Choose your level\n"
			"1 ---> (e)asy\n"
			"2 ---> (n)ormal\n"
			"3 ---> (h)ard\n"
			"0 ---> (b)ack\n"
			<< endl;
		cout << "Make a option\n";
		cin >> optionMass;
		if (count(optionValues.begin(), optionValues.end(), optionMass[0]) != 0) //Проверка на входимость введенного символа option в набор допустимых символов в optionValues, при этом
		{
			option = optionMass[0];
			break;
		}															 //нас интересует только первый символ в массиве
	} while (true);
	switch (option)
	{
	case '1':
	case 'e':
		sD = easy;
		break;
	case '2':
	case 'n':
		sD = normal;
		break;
	case '3':
	case 'h':
		sD = hard;
		break;
	case '0':
	case 'b':
		cleanscr = true;
		gameMenuMain();
		break;
	}
	if (gStart)
	{
		initialisation();
		gStart = false;
	}
	fGame();
}

void Game::fGame()
{

	thread tInput(&Game::fInput, this);
	thread tTimer(&Game::fTimer, this);
	tInput.join();
	tTimer.join();

	system("cls");
}

void Game::fTimer()
{
	
	while (true)
	{
		system("cls");
		cout << seconds << endl;
		cout << "Lives: " << lives << endl;
		cout << "Введенные значения сохраняются автоматически, даже если экран обновлен.\nДля выхода в главное меню введите m.\nInput:" << endl;
		switch (sD)
		{
		case easy:
			easyGameDisplay();
			break;
		case normal:
			normalGameDisplay();
			break;
		case hard:
			hardGameDisplay();
			break; // default значения не может быть
		}
		seconds--;

		if (seconds == -1)
		{
			cout << "\nTime is over. Right answer = " << answer << endl;
			cout << "Press any key\n";
			break;
		}

		this_thread::sleep_for(1s);
		if (answerPlayerString == "m" || lives<1)
		{
			//system("pause");
			break;

		}
	}
}

void Game::fInput()
{
	bool fix = true;
	while (true)
	{

		if (fix)
		{
			cin.ignore(); // чтобы первый ввод не пропускался, используем cin.ignore(). Также чтобы при последующем вызове функции getline не убирался 1ый вводимый символ
			fix = false;  // вызываем данный способ только один раз
		}
		getline(cin, answerPlayerString);
		//cout << answerPlayerString << endl;
		//cin >> answerPlayerString;
		inputStream.str(answerPlayerString);
		if (answerPlayerString == "m")
		{
			gameOver();
			system("cls");
			break;
	
		}
		inputStream >> answerPlayer;
		inputStream.clear();

		//cout << answerPlayer << endl;
		/*if (answerPlayer == answer)
			cout << "OK! ";*/
		if (seconds >= 0)
		{
			if (answerPlayer == answer)
			{
				
				generation = true;
				switch (sD)
				{
				case easy:
					seconds += 5;
					cout << "+5 seconds! You have " << seconds + 1 << " seconds.\n";
					break;
				case normal:
					seconds += 10;
					cout << "+10 seconds! You have " << seconds + 1 << " seconds.\n";
					break;
				case hard:
					seconds += 20;
					cout << "+20 seconds! You have " << seconds + 1 << " seconds.\n";
					break;
				}
				lvl++;
				countRightAnsw++;
				if (countRightAnsw % 3 == 0)
					lives++;
				this_thread::sleep_for(1s);
				
			}
			else
			{
				if (answerPlayerString.length() != 0)
					cout << "False. \n";
				lives--;
				countRightAnsw = 0;
				if (lives < 1)
				{
					gameOver();
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}

void Game::easyGameDisplay()
{
	mt19937 gen;
	gen.seed(system_clock::now().time_since_epoch().count()); // генератор случайных чисел


	if (generation || (a == -1 && b == -1)) // генерируем числа в случае, если они не прионициализированны
	{
		option = gen() % 4;
		a = gen() % 10 + 1 + lvl * 10;
		b = gen() % 10 + 1 + lvl * 10;
	}
	switch (option)
	{
	case 0:
	case 1:
		cout << a << " + " << b << " = ";
		answer = a + b;
		break;
	case 2:
		cout << a << " - " << b / option << " = "; // делим на sighn для улучшения получения случайных чисел
		answer = a - b / option;
		break;
	case 3:
		cout << a / option << " - " << b << " = ";
		answer = a / option - b;
		break;
	}
	generation = false;
}

void Game::normalGameDisplay()
{
	mt19937 gen;
	gen.seed(system_clock::now().time_since_epoch().count()); // генератор случайных чисел


	if (generation || (a == -1 && b == -1)) // генерируем числа в случае, если они не прионициализированны
	{
		option = gen() % 8;
		a = gen() % 10 + 1 + lvl * 3;
		b = gen() % 10 + 1 + lvl * 3;
		c = gen() % 10 + 1 + lvl;
		d = gen() % 10 + 1 + lvl;
	}
	switch (6)//option)
	{
	case 0:
		cout << "(" << a << " + " << b << ")" << "*" << c * d << "/" << d << " = ";
		answer = (a + b) * c * d / d;
		break;
	case 1:
		cout << "(" << a << " - " << b << ")" << "*" << c * d << "/" << d << " = ";
		answer = (a - b) * c * d / d;
		break;
	case 2:
		cout << a * c << "/" << c << " + " << c << "*" << d << " = ";
		answer = a * c / c + c * d;
		break;
	case 3:
		cout << a * c << "/" << c << " - " << c << "*" << d << " = ";
		answer = a * c / c - c * d;
		break;
	case 4:
		cout << b << " + " << c * d << "/" << c << " + " << a << " = ";
		answer = b + c * d / c + a;
		break;
	case 5:
		cout << b << " - " << c * d << "/" << c << " + " << a << " = ";
		answer = b - c * d / c + a;
		break;
	case 6:
	{
		double d1, d2;
		int temp = 0;
		temp = d % 4 + 2; // для удобства
		if ((temp == 2) && ((a + b) % 2 == 0)) // проверка на нечетность
		{
			d1 = round(double(a) * b / temp) - 1; //при делении на два остаток = 0.5, поэтому функция постоянно округляет в большую сторону. Одно значение уменшаем, другое оставляем
			d2 = round(double(a) * b / temp);
			//debug = "in if";
		}
		else
		{
			d1 = round(double(a) * b / temp);
			d2 = round(double(a) * b / temp * (temp - 1)); // умножаем на чсилитель
			//debug = "in else";
		}
		cout << "(" << d1 << "+" << d2 << ")" << "/" << b << "+" << c + d << "=";
		answer = (d1 + d2) / b + c + d;
		//cout << endl << debug << " " << answer << " a:"<<a<<" b:"<< b << " d:" <<d<< endl;
	}
	break;
	case 7:
		double d1, d2;
		int temp = d % 4 + 2; // для удобства
		if (((d % 4) + 2 == 2) && ((a + b) % 2 != 0)) // проверка на нечетность
		{
			d1 = round(double(a) * b / temp) - 1; //при делении на два остаток = 0.5, поэтому функция постоянно округляет в большую сторону. Одно значение уменшаем, другое оставляем
			d2 = round(double(a) * b / temp);
		}
		else
		{
			d1 = round(double(a) * b / temp);
			d2 = round(double(a) * b / temp * (temp - 1)); // умножаем на чсилитель
		}
		cout << "(" << d1 << " + " << d2 << ")" << "/" << b << " - " << c + d << " = ";

		answer = ((d1 + d2) / b) - (c + d);
		//cout << endl << answer << ":answer" << endl;
		break;



	}
	generation = false;
}

void Game::initMassHardGame()
{
	mt19937 gen;
	gen.seed(system_clock::now().time_since_epoch().count()); // генератор случайных чисел

	if (generation || (a == -1 || b == -1 || c == -1 || d == -1)) // генерируем числа в случае, если они не проинициализированны
	{
		for (int i = 0; i < 8; i++)
		{
			option = gen() % 8;
			optionHard = gen() % 8;
			a = gen() % 10 + 1 + lvl * 3;
			b = gen() % 10 + 1 + lvl * 3;
			c = gen() % 10 + 1 + lvl;
			d = gen() % 10 + 1 + lvl;

			switch (i)
			{
			case 0:
				buffer.str(""); // очищаем буффер т.к в нем остаются данные от записи в файл
				buffer.clear();
				buffer << "(" << a << " + " << b << ")" << "*" << c * d << "/" << d;
				Output[i] = buffer.str();
				answerMass[i] = (a + b) * c * d / d;
				buffer.str("");
				buffer.clear();
				break;
			case 1:
				buffer << "(" << a << " - " << b << ")" << "*" << c * d << "/" << d;
				Output[i] = buffer.str();
				answerMass[i] = (a - b) * c * d / d;
				buffer.str("");
				buffer.clear();
				break;
			case 2:
				buffer << a * c << "/" << c << " + " << c << "*" << d;
				Output[i] = buffer.str();
				answerMass[i] = a * c / c + c * d;
				buffer.str("");
				buffer.clear();
				break;
			case 3:
				buffer << a * c << "/" << c << " - " << c << "*" << d;
				Output[i] = buffer.str();
				answerMass[i] = a * c / c - c * d;
				buffer.str("");
				buffer.clear();
				break;
			case 4:
				buffer << b << " + " << c * d << "/" << c << " + " << a;
				Output[i] = buffer.str();
				answerMass[i] = b + c * d / c + a;
				buffer.str("");
				buffer.clear();
				break;
			case 5:
				buffer << b << " - " << c * d << "/" << c << " + " << a;
				Output[i] = buffer.str();
				answerMass[i] = b - c * d / c + a;
				buffer.str("");
				buffer.clear();
				break;
			case 6:
			{
				double d1, d2;
				int temp = 0;
				temp = d % 4 + 2; // для удобства
				if (((d % 4) + 2 == 2) && ((a + b) % 2 == 0)) // проверка на четность
				{
					d1 = round(double(a) * b / temp) - 1; //при делении на два остаток = 0.5, поэтому функция постоянно округляет в большую сторону. Одно значение уменшаем, другое оставляем
					d2 = round(double(a) * b / temp);
				}
				else
				{
					d1 = round(double(a) * b / temp);
					d2 = round(double(a) * b / temp * (temp - 1)); // умножаем на чсилитель
				}
				buffer << "(" << d1 << " + " << d2 << ")" << "/" << b << " + " << c + d;
				Output[i] = buffer.str();
				answerMass[i] = (d1 + d2) / b + c + d;
				buffer.str("");
				buffer.clear();
			}
			break;
			case 7:
				double d1, d2;
				int temp = d % 4 + 2; // для удобства
				if (((d % 4) + 2 == 2) && ((a + b) % 2 != 0)) // проверка на нечетность
				{
					d1 = round(double(a) * b / temp) - 1; //при делении на два остаток = 0.5, поэтому функция постоянно округляет в большую сторону. Одно значение уменшаем, другое оставляем
					d2 = round(double(a) * b / temp);
				}
				else
				{
					d1 = round(double(a) * b / temp);
					d2 = round(double(a) * b / temp * (temp - 1)); // умножаем на чсилитель
				}
				buffer << "(" << d1 << " + " << d2 << ")" << "/" << b << " - " << c + d;
				Output[i] = buffer.str();
				answerMass[i] = ((d1 + d2) / b) - (c + d);
				buffer.str("");
				buffer.clear();
				break;

			}
		}
	}
	generation = false;
}

void Game::hardGameDisplay()
{
	initMassHardGame();
	if (optionHard % 2 == 0)
	{
		cout << Output[option] << " + " << Output[optionHard] << " = " << endl;
		answer = answerMass[option] + answerMass[optionHard];
	}
	else
	{
		cout << Output[option] << " - " << Output[optionHard] << " = " << endl;
		answer = answerMass[option] - answerMass[optionHard];
	}
	/*cout << answer << endl;
	cout << "Output[" << option << "] " << optionHard % 2 << " Output[" << optionHard << "]";*/
	//cout << lvl << endl;

} 

void Game::initialisation()
{
	lvl = 0; // уровень зависящий от количества правильных ответов
	generation = false; // управление генерацией рандомных чисел
	a = -1;
	b = -1;//переменные которые хранят значения для рандома. Чтобы функция каждый раз не обновляла ззначения при вызове, добавляется проверка
	c = -1;
	d = -1;
	x = -1;
	countRightAnsw = 0;
	lives = 3;
}



void Game::gameOver()
{
	switch (sD)
	{
	case 0:
	{
		ofstream csv_o_e("results_easy.csv", ios::app);
		inputInFile(csv_o_e);
		break;
	}
	case 1:
	{
		ofstream csv_o_n("results_normal.csv", ios::app);
		inputInFile(csv_o_n);
		break;
	}
	case 2:
	{
		ofstream csv_o_h("results_hard.csv", ios::app);
		inputInFile(csv_o_h);
		break;
	}
	}
	do {
		char optionMass[256];
		const string optionValues = "120pPmMeE";
		system("cls");
		cout << "Game over. Answer #" << lvl << endl;
		cout << "Press:\n1 ---> (p)lay again\n"
			"2 ---> (m)enu\n"
			"0 ---> (e)xit\n";
		cout << "Make a option\n";
		cin >> optionMass;
		if (count(optionValues.begin(), optionValues.end(), optionMass[0]) != 0) //Проверка на входимость введенного символа option в набор допустимых символов в optionValues, при этом
		{
			option = optionMass[0];
			break;
		}															 //нас интересует только первый символ в массиве
	} while (true);
	switch (option)
	{
	case '1':
	case 'p':
	case 'P':
		initialisation();
		fGame();
		break;
	case '2':
	case 'm':
	case 'M':
		system("cls");
		gStart = true;
		gameMenuMain();
		break;
	case '0':
	case 'e':
	case 'E':
		break;
	}
	
}

void Game::inputInFile(ofstream& csv_i)
{
	csv_i << /*sD << ";" << */name << ";" << lvl << ";" << DateTime() << endl;
}

string Game::DateTime()
{
	buffer.str("");
	buffer.clear();
	time_point<system_clock> za = system_clock::now();
	time_t zb = system_clock::to_time_t(za);
	tm zc;
	string str;
	localtime_s(&zc, &zb);
	buffer << put_time(&zc, "%d.%m.%Y %H:%M:%S");
	return (str = buffer.str());
}

void Game::outputFromFile(ifstream& csv_i)
{
	vectorRes.clear();
	while (csv_i)
	{
		string temp;
		getline(csv_i, temp);
		if (!csv_i)
			break;
		//cout << temp << endl;
		vectorRes.push_back({ temp });
	}
	bubbleSort(vectorRes);
	for (int i = 0; i < vectorRes.size(); i++)
	{
		if (vectorRes.at(i).nameRes == "")
			return;//проверка на пустую строку из файла (если csv не инициализирован, то читается плохое значение. Тут мы его отбрасываем
		cout << "Name: " << setw(8) << left << vectorRes.at(i).nameRes << " Lvl: " << setw(3) << vectorRes.at(i).lvlRes << " Date: " << vectorRes.at(i).dateRes << endl;
	}
}

void Game::bestScore()
{

	ifstream csv_i_e("results_easy.csv");
	ifstream csv_i_n("results_normal.csv");
	ifstream csv_i_h("results_hard.csv");
//	istringstream csv_i_stream;
	if (csv_i_e || csv_i_n || csv_i_h)
	{
		cout << "----------------Easy-------------------\n";
		outputFromFile(csv_i_e);
		cout << "----------------Normal-------------------\n";
		outputFromFile(csv_i_n);
		cout << "----------------Hard-------------------\n";
		outputFromFile(csv_i_h);
	}
	else
	{
		cout << "Fail. Dates aren't created.\n";
	};
	cout << "\n";


	//do {
	//	char optionMass[256];
	//	const string optionValues = "10mMeE";
	//	//system("cls");
	//	cout << "Game over. Answer #" << lvl << endl;
	//	cout << "Press:\n1 ---> (m)enu\n"
	//			"0 ---> (e)xit\n";
	//	cout << "Make a option\n";
	//	cin >> optionMass;
	//	if (count(optionValues.begin(), optionValues.end(), optionMass[0]) != 0) //Проверка на входимость введенного символа option в набор допустимых символов в optionValues, при этом
	//	{
	//		option = optionMass[0];
	//		break;
	//	}															 //нас интересует только первый символ в массиве
	//} while (true);
	//switch (option)
	//{
	//case '1':
	//case 'm':
	//	gStart = true;
	//	gameMenuMain();
	//	break;
	//case '0':
	//case 'e':
	//	break;
	//}
	gameMenuMain();
}

void Game::bubbleSort(vector <resultsType>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		for (int j = vec.size()-1; j > i; j--)
		{
		//	cout << vec.at(j).lvlRes << endl;
			if (vec.at(j).lvlRes > vec.at(j - 1).lvlRes)
			{
				int temp = vec.at(j - 1).lvlRes;
				string tempN = vec.at(j - 1).nameRes;
				string tempD = vec.at(j - 1).dateRes;
				vec.at(j - 1).lvlRes = vec.at(j).lvlRes;
				vec.at(j - 1).nameRes = vec.at(j).nameRes;
				vec.at(j - 1).dateRes = vec.at(j).dateRes;
				vec.at(j).lvlRes = temp;
				vec.at(j).nameRes = tempN;
				vec.at(j).dateRes = tempD;
			}
		}
	}
};

