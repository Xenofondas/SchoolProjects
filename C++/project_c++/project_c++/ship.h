#pragma once
#include "map.h"
#include <iostream>
#include <vector>
using namespace::std;

class ship
{
public:
	ship(int=0, int=0, int=0);
	virtual ~ship(void);
	void printSomething();
	void move();
	virtual void leitourgia(int,map table[100][100],vector <ship*> ploia)=0;
    virtual void movement()=0;
	static void printObj(ship*);
	void getCoordinates();
	


public:
	
	
	vector <ship*> ploia;
	int getX_pos() const;
	int getY_pos() const;
	void setX_pos(int);
	void setY_pos(int);
	void setCoordinates();
	void setNewCoordinates(int,int);
	int geteidos() const;
	int getMaxAtoxi() const;
	void setTrex_antoxi(int);
	int getTrex_antoxi() const;
	void setStuckTr(int);
	int getStuckTr() const;
	void operator--();
	void operator++();
	friend ostream &operator<<(ostream &out,ship*) ;

	int p_k; //plithos ploiwn 
	void set_aa(int);// Auxwn arithmos ploiou
	int get_aa() const;
	void set_plkin(int);
	int get_plkin() const;
	void inc_plkin(int);
	void setS_z(int);
	int getS_z() const;
	void count_damage(int);
	void inc_plEp(int);
	static int get_plEp();


private:
	int x_pos;
	int y_pos;
	int eidos;  //eidos karabiou: 1->peiratiko, 2->emporiko 
	int max_antoxi;
	int trex_antoxi;	
	int stuck_treasure;
	int speed;
	int a_a; //Auxon arithmos ploiou
	int pl_kin; //Synolo thesewn pou kinhthike
	int s_z; //Synolo zhmia pou proklhthke sto ploio
	static int pl_epith;

};

