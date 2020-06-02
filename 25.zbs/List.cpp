#include"List.h"
#include "Print.h"
#include"Book.h"
List::~List(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
List::List(int n)
{
	beg = new Object *[n];
	cur = 0;
	size = n;
}
void List::Add()
{
	Object* p;
	cout << "1.Print" << endl;
	cout << "2.Book" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (choice == 2)
		{
			Book* b = new Book;
			b->Input();
			p = b;
			if (cur < size)

			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;

}
void List::Add(Book* a) {
	Object* p;
	p = a;
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

void List::Add(Print*b) {
	Object* p;
	p = b;
	if (cur < size)

	{
		beg[cur] = p;
		cur++;
	}
}

void List::Add(Object* p) {
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

void List::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;

	}
}
int List::operator ()()
{
	return cur;
}
void List::Del()
{
	if (cur == 0)return;
	cur--;
}
