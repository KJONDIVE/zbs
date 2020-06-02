#include <iostream>
#include <string>

using namespace std;

const int size40 = 40, size75 = 75, size90 = 90;

struct Table//��������� � �������
{
	string fio, databorn;
	unsigned long int numberpasport = 0;

	Table* next = 0;//��� �������� ������������ ������
};

struct Cep//��������� ��� ������ �������
{
	Table* first = 0;//��������� �� ������ ����� ����
	int size = 0;//����� �������
	void push(Table* sled)
	{
		Table* p = first;//��������� ��������� �� ������ �����
		
		if (p)//���� ������ ����� ����������
		{
			while (p->next)p = p->next;
			p->next = sled;//��������� �����
		}
		else first = sled;//������ ��������� �����
		size++;
	}

	bool empty() { return !this->size; }//�������� ����� �� �������
};

//��� �������. ������ ������� - �������
Cep* Hash40 = new Cep[size40];
Cep* Hash75 = new Cep[size75];
Cep* Hash90 = new Cep[size90];

//������ ������� ������: ��� � ���� ��������
string mid[] = { "������","������","�������","�����","����","��������","������","���","����","������","�����","�����" };
string first[] = { "����","������","�����","������","����","�������","�����","������","�����","�����","��������","����","�������","������","�������" };
string last[] = { "��������","��������","���������","����������","��������","�����������","���������","����������","��������","���������","������������","��������","����������","����������","����������" };
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
		cout << "�������� � ����� ����� �������� ���!\n";
	else
	{
		if (mass[i].size == 1)//���� � ������� ���� �����
			if (mass[i].first->databorn == data)
			{
				cout << "������� ������\n";
				cout << "���:\t" << mass[i].first->fio;
				cout << "\n���� ��������: " << mass[i].first->databorn;
				cout << "\n����� ��������: " << mass[i].first->numberpasport;
				return;
			}
			else cout << "\n�������� � ����� ����� �������� ���!";

		else {
			Table* f = mass[i].first;

			while (f)
			{

				if (f->databorn == data)
				{
					cout << "������� ������\n";
					cout << "���:\t" << mass[i].first->fio;
					cout << "\n���� ��������: " << mass[i].first->databorn;
					cout << "\n����� ��������: " << mass[i].first->numberpasport;
					return;
				}
				else f = f->next;
			}
			cout << "�������� � ����� ����� �������� ���!\n";
		}

	}
}

void findHash(int hsize)
{
	string rdata;
	cin.ignore(32767, '\n');
	cout << "������� ������� ���� ��������";
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

	cout << "\n���������� ��������: " << k << '\n';
}