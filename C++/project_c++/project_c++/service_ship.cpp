#include "service_ship.h"
#include <iostream>

using namespace::std;


service_ship::service_ship(int e,int m_a,int stuck_tr):
	ship(e,m_a,stuck_tr)
{
	tres_gain=0;
}


service_ship::~service_ship(void)
{
}

void service_ship::movement(void)
{
	int x,y,move;
	
	
	
	x=getX_pos();
	y=getY_pos();

	move=rand()%4;
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
  else if (move==2 && x-2>-1 && x-2<100 )
	 { 
		 x-=2;
		 inc_plkin(2);
  }
  else if (move==3 && x+2>-1 && x+2<100 )
	{
		x+=2;
		inc_plkin(2);
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
	else if (move==2 && y-2>-1 && y-2<100 )
	{
		y-=2;
		inc_plkin(2);
  }
  else if (move==3 && y+2>-1 && y+2<100 )
	{
		y+=2;
		inc_plkin(2);
	}
	
	

	
	setNewCoordinates(x,y);
	
	
}

void service_ship::leitourgia(int,map table[100][100],vector <ship*> ploia)
{
	int i,j,k;
	int x=getX_pos();
	int y=getY_pos();

	for(i=x-1; i<=x+1; i++){ //elegxoume gia geitonika ploia
		for(j=y-1; j<=y+1; j++){

			if(i!=getX_pos() && j!=getY_pos()){ //exeroume thn idia thesh apo ton elegxo
				
				for(k=0; k<ploia.size(); k++){
					if(ploia[k]->getX_pos()==i && ploia[k]->getY_pos()==j){
						if(ploia[k]->getTrex_antoxi()<ploia[k]->getMaxAtoxi()){ //elegxoume an exei zhmia
							
							ploia[k]->setTrex_antoxi(ploia[k]->getTrex_antoxi()+5); // auxanoume thn trexousa antoxi
							ploia[k]->setStuckTr(ploia[k]->getStuckTr()-3);//meiwnoume to thisauro tou ploiou poy episkeuast..
							setStuckTr(getStuckTr()+3);// auxanoume to thisauro tou episkeuastikou
							tres_gain+=3;
						}
					}
				}
			}
		}
	}
}