#pragma once
#include "ship.h"
#include "pirates.h"
class explorer :
	public ship
{
public:

	  explorer(int=0 , int=0, int=0);
	 ~explorer();
	 void movement();
	 void leitourgia(int,map table[100][100],vector <ship*> ploia);
};

