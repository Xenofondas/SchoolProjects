#pragma once
#include "pirates.h"
class sebek :
	public pirates
{
public:
	sebek(int=0 , int=0, int=0);
	~sebek(void);
	typedef pirates super;
	void movement(); //H kinhsh gia to peiratiko
	void leitourgia(int,map table[100][100],vector <ship*> ploia);
};

