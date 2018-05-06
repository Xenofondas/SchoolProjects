#pragma once
#include "pirates.h"
class fregata :
	public pirates
{
public:
	fregata(int=0 , int=0, int=0);
	~fregata(void);
	void movement(); //H kinhsh gia to peiratiko
	void leitourgia(int,map table[100][100],vector <ship*> ploia);
	typedef pirates super;
};

