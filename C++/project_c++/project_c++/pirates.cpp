#include "pirates.h"
#include <vector>
using namespace::std;

pirates::pirates(int e,int m_a,int stuck_tr):
	ship(e,m_a,stuck_tr)
{
	
}


pirates::~pirates(void)
{
}

void pirates::set_damage(int x)
{
	damage=x;
}

int pirates::get_damage() const
{
	return damage;
}

void pirates::movement()
{
	int x,y,move;
	
	
	
	x=getX_pos();
	y=getY_pos();

	move=rand()%2;
	if    (move==0 && x-1>-1 && x-1<100 ) 
     {
		 x--; 
	inc_plkin(1);
	}
  else if (move==1 && x+1>-1 && x+1<100 ) 
     {
		 x++; 
		 inc_plkin(1);
	}

	move=rand()%2;
   if (move==2 && y-1>-1 && y-1<100 ) 
    { 
		y--;
		inc_plkin(1);
   }
  else if (move==3 && y+1>-1 && y+1<100 ) 
    {
		y++;
		inc_plkin(1);
   }
   	
	setNewCoordinates(x,y);
	
	
}

void pirates::leitourgia(int w,map table[100][100],vector <ship*> ploia)
{

	int i,j,k;
	int x=getX_pos(); 
	int y=getY_pos();
	int a=get_aa();	

	for(i=x-1; i<=x+1; i++){ //elegxoume gia geitonika ploia
		for(j=y-1; j<=y+1; j++){
			
				for(k=0; k<ploia.size(); k++)

					if(ploia[k]->getX_pos()==i && ploia[k]->getY_pos()==j && ploia[k]->get_aa()!=a){

						inc_plEp(1);
						//cout<<"To peiratiko ploio "<<get_aa()<<" kanei epithesh!"<<endl;
				ploia[k]->setTrex_antoxi(ploia[k]->getTrex_antoxi()-get_damage()); //Attack
				
				ploia[k]->setStuckTr(ploia[k]->getStuckTr()-3); 
				
				ploia[k]->count_damage(3);
				setStuckTr(getStuckTr()+3);//Auxisi tou thisaurou kata 3 monades tou peiratikou
				
				}
					
					
		}	
		
	}
}
