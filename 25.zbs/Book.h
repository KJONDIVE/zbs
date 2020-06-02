#pragma once
#include"Print.h"
class Book :
	public Print
{
public:
	Book(void);
public:
	~Book(void) {};
	void Show();
	void Input();
	Book(string, string, int, string);
	Book(const Book&);
	int getPages() { return Pages; }
	string getPress() { return Press; }
	void setPages(int);
	void setPress(string);
	Book& operator=(const Book&);
protected:
	int Pages;
	string Press;
};
