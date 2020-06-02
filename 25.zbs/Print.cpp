#include "Print.h"
Print::Print(void)
{
	Name = "Name";
	Author = "Author";
}
void Print::Show()
{
	cout << "\nNAME: " << Name;
	cout << "\nAUTHOR: " << Author;

}
void Print::Input()
{
	cout << "Name? ";
	getline(cin, Name);
	getline(cin, Name);
	cout << endl;
	cout << "\nAuthor? ";
	getline(cin, Author);
}
Print::Print(string n, string a)
{
	Name = n;
	Author = a;
}
Print::Print(Print& p)
{
	Name = p.Name;
	Author = p.Author;
}
void Print::setName(string n)
{
	Name = n;
}
void Print::setAuthor(string a)
{
	Author = a;
}
Print& Print::operator=(const Print&p)
{
	if (&p == this)return *this;
	Name = p.Name;
	Author = p.Author;
	return *this;
}
