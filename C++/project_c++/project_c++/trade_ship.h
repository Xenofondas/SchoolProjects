#pragma once
#include "ship.h"
class trade_ship :
	public ship
{
public:
	trade_ship(int=0 , int=0, int=0);
	~trade_ship(void);
	void movement();
	void leitourgia(int,map table[100][100],vector <ship*> ploia);
private:
	int tres_gain;

};

