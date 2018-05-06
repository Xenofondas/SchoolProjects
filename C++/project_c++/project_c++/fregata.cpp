#include "fregata.h"


fregata::fregata(int e,int m_a,int stuck_tr):
	pirates(e,m_a,stuck_tr)
{
	set_damage(3);//H zhmia pou prokalei h fregata einai 3 monades antoxis.

}


fregata::~fregata(void)
{
}

void fregata::movement()
{
	super::movement();
}

void fregata::leitourgia(int,map table[100][100],vector <ship*> ploia)
{
	
	super::leitourgia(1, table,ploia);
}