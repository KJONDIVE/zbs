#pragma once
#include"Object.h"
#include"Print.h"
#include"Book.h"
#include<iostream>
using namespace std;
class List
{
public:
	List(int);

public:
	~List(void);
	void Add();
	void Add(Book*);
	void Add(Print*);
	void Add(Object*);
	void Del();
	void Show();
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};

