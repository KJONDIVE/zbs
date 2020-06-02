#pragma once
#include"Object.h"
#include<iostream>
#include<string>
using namespace std;
class Print :
	public Object
{
public:
	Print(void);
	virtual ~Print() {};
	void Show();
	void Input();
	Print(string, string);
	Print(Print&);
	string getName() { return Name; };
	string getAuthor() { return Author; };
	void setName(string);
	void setAuthor(string);
	Print& operator = (const Print&);
protected:
	string Name;
	string Author;

};
