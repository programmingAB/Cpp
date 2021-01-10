#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>
#include <sstream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <mutex>
using namespace std;
using namespace std::chrono;

class resultsType 
{

	
public:
	string nameRes;
	int lvlRes;
	string dateRes;
	resultsType(string str)
	{
		replace(str.begin(), str.end(), ';', ' ');
		istringstream resultsString(str);
		resultsString >> nameRes;
		resultsString >> lvlRes;
		resultsString >> dateRes;
		//cout << nameRes << " " << lvlRes << " " << dateTimeRes << endl;
		
	}


	
};

enum setDufficult { easy, normal, hard, unreal };


class Game/*: public resultsType*/
{

	
	//string debug;
	bool printName = true;
	bool cleanscr = true; // условие чистить ли экран
	vector <resultsType> vectorRes;
	int countRightAnsw=0;
	bool gStart = true; // булевская паеременная отвечающая за обнуление результатов при повторном входе в игру невыходя из программы
	int lives = 3;
	string Output[8];
	int answerMass[8];
	int option;
	int optionHard; // для функции hard
	int lvl = 0; // уровень зависящий от количества правильных ответов
	bool generation=false; // управление генерацией рандомных чисел
	int a = -1;
	int b = -1;//переменные которые хранят значения для рандома. Чтобы функция каждый раз не обновляла ззначения при вызове, добавляется проверка
	int c = -1;
	int d = -1;
	int x = -1;
	int seconds = 10000;
	string name="";
	setDufficult sD = easy;
	int answer, answerPlayer;
	string answerPlayerString;
	istringstream inputStream;
	stringstream buffer;
	void bubbleSort(vector <resultsType>&);

public:

	void initialisation();
	void gameMenuMain();
	void gameMenuPlay();
	void fGame();
	void easyGameDisplay();
	void normalGameDisplay();
	void hardGameDisplay();
	void fTimer();
	void fInput();
	void initMassHardGame();
	void gameOver();
	void inputInFile(ofstream&);
	void outputFromFile(ifstream& td);
	string DateTime();
	void bestScore();
};

//class resultsType : Game
//{
//	string nameRes;
//	int lvlRes;
//	string dateTimeRes;
//public:
//	resultsType(string nR, int lR, string dR)
//	{
//		nameRes = nR;
//		lvlRes = lR;
//		dateTimeRes = dR;
//	};
//};
//
//class GameMods
//{
//
//public:
//
//};
//
