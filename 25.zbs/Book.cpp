#include "Book.h"

Book::Book(void) : Print()
{
	Pages = 0;
	Press = "Publishing House";
}

void Book::Show()
{
	cout << "\nNAME: " << Name;
	cout << "\nAUTHOR: " << Author;
	cout << "\nPAGES: " << Pages;
	cout << "\nPRESS: " << Press << endl;
}

void Book::Input()
{
	cout << "\nName?\n";
	getline(cin, Name);
	getline(cin, Name);
	cout << "\nAuthor?\n";
	getline(cin, Author);
	cout << "\nPress?\n";
	getline(cin, Press);
	cout << "\nPages?\n";
	cin >> Pages;
	cout << endl;
}

Book::Book(string n, string a, int pag, string p)
{
	Name = n;
	Author = a;
	Pages = pag;
	Press = p;
}

Book::Book(const Book& b)
{
	Name = b.Name;
	Author = b.Author;
	Pages = b.Pages;
	Press = b.Press;
}

void Book::setPages(int p)
{
	Pages = p;
}

void Book::setPress(string p)
{
	Press = p;
}

Book& Book::operator=(const Book& b)
{
	if (&b == this) return *this;
	Name = b.Name;
	Author = b.Author;
	Pages = b.Pages;
	Press = b.Press;
	return *this;
}