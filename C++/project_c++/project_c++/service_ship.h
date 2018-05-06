#pragma once
#include "ship.h"


class service_ship :
	public ship
{
public:
	service_ship(int=0 , int=0, int=0);
	~service_ship(void);
	void movement();
	void leitourgia(int,map table[100][100],vector <ship*> ploia);
private:
	int tres_gain;
};

