#include <iostream>
#include <string>

using namespace std;

const int size40 = 40, size75 = 75, size90 = 90;

struct Table//структура с данными
{
	string fio, databorn;
	unsigned long int numberpasport = 0;

	Table* next = 0;//для создания односвязного списка
};

struct Cep//структура для метода цепочек
{
	Table* first = 0;//указатель на первое звено цепи
	int size = 0;//число звеньев
	void push(Table* sled)
	{
		Table* p = first;//сохраняем указатель на первое звено
		
		if (p)//если первое звено существует
		{
			while (p->next)p = p->next;
			p->next = sled;//добавляем новый
		}
		else first = sled;//просто добавляем звено
		size++;
	}

	bool empty() { return !this->size; }//проверка пуста ли цепочка
};

//хэш таблицы. Каждый элемент - цепочка
Cep* Hash40 = new Cep[size40];
Cep* Hash75 = new Cep[size75];
Cep* Hash90 = new Cep[size90];

//Данные берутся отсюда: ФИО и Дата рождения
string mid[] = { "Иванов","Петров","Сидоров","Тесла","Маск","Эйнштейн","Ньютон","Гук","Кюри","Сталин","Ленин","Маркс" };
string first[] = { "Иван","Никита","Сидор","Никола","Илон","Альберт","Исаак","Роберт","Мария","Иосиф","Владимир","Карл","Алексей","Михаил","Дмитрий" };
string last[] = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович","Владимирович","Карлович","Алексеевич","Михаилович","Дмитриевич" };
string dobs[] = { "01.01.2001", "10.10.2010", "20.02.2020", "02.02.2020"};

int doHash(string data, int hashTableSize)
{
	int key = 0;
	for (int i = 0; i < data.size(); i++) key = key + ((int)(data[i])*i*9);
	return (hashTableSize*((key*0.61)-trunc(key*0.61)));
}

void addTable(Table* p, int hsize)
{
	int i;
	i = doHash(p->databorn, hsize);

	switch (hsize)
	{
	case size40:
		Hash40[i].push(p);
		break;
	case size75:
		Hash75[i].push(p);
		break;
	case size90:
		Hash90[i].push(p);
		break;
	}
}

void find(int i, string data, Cep* mass)
{
	if (mass[i].empty())
		cout << "Человека с такой датой рождения нет!\n";
	else
	{
		if (mass[i].size == 1)//Если в цепочке одно звено
			if (mass[i].first->databorn == data)
			{
				cout << "Человек найден\n";
				cout << "ФИО:\t" << mass[i].first->fio;
				cout << "\nДата рождения: " << mass[i].first->databorn;
				cout << "\nНомер паспорта: " << mass[i].first->numberpasport;
				return;
			}
			else cout << "\nЧеловека с такой датой рождения нет!";

		else {
			Table* f = mass[i].first;

			while (f)
			{

				if (f->databorn == data)
				{
					cout << "Человек найден\n";
					cout << "ФИО:\t" << mass[i].first->fio;
					cout << "\nДата рождения: " << mass[i].first->databorn;
					cout << "\nНомер паспорта: " << mass[i].first->numberpasport;
					return;
				}
				else f = f->next;
			}
			cout << "Человека с такой датой рождения нет!\n";
		}

	}
}

void findHash(int hsize)
{
	string rdata;
	cin.ignore(32767, '\n');
	cout << "Введите искомую дату рождения";
	getline(cin, rdata, '\n');

	int i = doHash(rdata, hsize);

	switch (hsize)
	{
	case size40:
		find(i, rdata, Hash40);
		break;
	case size75:
		find(i, rdata, Hash75);
		break;
	case size90:
		find(i, rdata, Hash90);
		break;

	}

}

void collision(int hsize)
{
	int k = 0;
	switch (hsize)
	{
	case size40:
		for (int i = 0; i < size40; i++)
		{
			if (Hash40[i].size)
				if (Hash40[i].size > 1)
					k++;
		}
		break;
	case size75:
		for (int i = 0; i < size75; i++)
		{
			if (Hash75[i].size)
				if (Hash75[i].size > 1)
					k++;
		}
		break;
	case size90:

		for (int i = 0; i < size90; i++)
		{
			if (Hash90[i].size)
				if (Hash90[i].size)
					k++;
		}
		break;
	}

	cout << "\nКоличество коллизий: " << k << '\n';
}