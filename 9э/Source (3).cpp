#include <iostream>
#include <Windows.h>

#include <cstdlib>
#include <ctime>

#include "Header.h"

using namespace std;

void addTable(Table*, int);
void findHash(int);
void collision(int);

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int hsize = 0;
	cout << "Введите размер хэш-таблицы == 40, 75, 90: ";
		cin >> hsize;

		for (int i = 0; i < hsize; i++)
		{
			Table* somebody = new Table;

			somebody->fio = mid[rand() % 12] + ' ' + first[rand() % 15] + ' ' + last[rand() % 15];
			somebody->databorn = dobs[rand()%4];
			somebody->numberpasport = 100000 + rand() % 999999;
			addTable(somebody, hsize);
		}

		findHash(hsize);
		collision(hsize);
}