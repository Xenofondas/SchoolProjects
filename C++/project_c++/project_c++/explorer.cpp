#include "explorer.h"


explorer::explorer(int e,int m_a,int stuck_tr):
	ship(e,m_a,stuck_tr)
{


}

explorer::~explorer(void)
{


}

void explorer::movement(void)
{
	int x,y,move;
		
	x=getX_pos();
	y=getY_pos();

	move=rand()%4;
	if  (move==0 && x-1>-1 && x-1<100 ) 
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

void explorer::leitourgia(int,map table[100][100],vector <ship*> ploia)
{
	int i,j,k;
	int x=getX_pos();
	int y=getY_pos();

		for(i=x-1; i<=x+1; i++){
			for(j=y-1; j<=y+1; j++){
				for(k=0; k<ploia.size(); k++){
					if(ploia[k]->getX_pos()==i && ploia[k]->getY_pos()==j){

		                pirates *q = dynamic_cast < pirates * >( ploia[k] );
						if (q!=0)
						{
							inc_plkin(1); //Metakinish kata mia thesh
							if(getX_pos()>ploia[k]->getX_pos() && getX_pos()-1>-1 && getX_pos()+1<100 ){
								setX_pos(getX_pos()+1);
							}
							else if(getX_pos()<ploia[k]->getX_pos() && getX_pos()-1>-1 && getX_pos()+1<100 )
							{
								setX_pos(getX_pos()-1);				// Syntetagmenh x

							}

							else if(getY_pos()>ploia[k]->getY_pos() && getY_pos()-1>-1 && getY_pos()+1<100)
							{
								setY_pos(getY_pos()+1);
							}
							else if(getY_pos()<ploia[k]->getY_pos() && getY_pos()-1>-1 && getY_pos()+1<100 )
							{
								setY_pos(getY_pos()-1);				// Syntetagmenh y
							}
						}
					}
						}
						
				if (table[i][j].getCurrentEntasi()>7)
						{
							if(getX_pos()>i && getX_pos()-1>-1 && getY_pos()+1<100)
							{setX_pos(getX_pos()-1); }
							else if(getX_pos()<i && getX_pos()-1>-1 && getY_pos()+1<100)
							{setX_pos(getX_pos()+1);}

							else if(getY_pos()>j && getY_pos()-1>-1 && getY_pos()+1<100)
							{
								setY_pos(getY_pos()+1);
							}
							else if(getY_pos()<j && getY_pos()-1>-1 && getY_pos()+1<100 )
							{
								setY_pos(getY_pos()-1);				// Syntetagmenh y
							}
							inc_plkin(1); //Metakinish kata mia thesh
						}
					}
	}

}

