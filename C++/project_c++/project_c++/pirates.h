#pragma once
#include "ship.h"
using namespace::std;
class pirates :
	public ship
{
public:
	pirates(int=0 , int=0, int=0);
	~pirates(void);
    void movement(); //H kinhsh gia to peiratiko
	void leitourgia(int,map table[100][100],vector <ship*> ploia);
	void set_damage(int);
	int get_damage() const;

private:
	int damage;

	
};

