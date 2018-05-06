#include "sebek.h"


sebek::sebek(int e,int m_a,int stuck_tr):
	pirates(e,m_a,stuck_tr)
{
	set_damage(3); //H zhmia pou prokalei to sebek einai 3 monades antoxis.
}


sebek::~sebek(void)
{
}

void sebek::movement()
{
	super::movement();
}

void sebek::leitourgia(int,map table[100][100],vector <ship*> ploia)
{
	cout<<"Einai peiratiko sebek!"<<endl;
	super::leitourgia(1, table,ploia);
}