#include "trade_ship.h"


trade_ship::trade_ship(int e,int m_a,int stuck_tr):
	ship(e,m_a,stuck_tr)
{
	tres_gain=0;
}


trade_ship::~trade_ship(void)
{
}

void trade_ship::movement()
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
	
	if (x>=y)
	{
		inc_plkin(x);
	}else if(x<y)
	{
		inc_plkin(y);
	}

	setNewCoordinates(x,y);
	
}

void trade_ship::leitourgia(int,map table[100][100],vector <ship*> ploia)
{
	
	int i,j,temp;
	int x=getX_pos();
	int y=getY_pos();
	
	for(i=x-1; i<=x+1; i++){
		for(j=y-1; j<=y+1; j++){
			if(i>=0 && i<100 && j>=0 && j<100){
				if(table[i][j].getLimani()==1){       //Kathe limani pou vrisketai se geitonikh thesh auksanei to treasure
				temp=getStuckTr()+3;			  //tou emporikou ploiou(kata 3 monades).
				setStuckTr(temp);
				tres_gain+=3;
				
				}
			}
		}
	}	
}