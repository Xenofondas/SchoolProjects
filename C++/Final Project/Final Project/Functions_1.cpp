void menu()//emfanizei to menu
{
cout << " \nThe system is now running. Press corresponding number for each desired action\n";
cout << " 1 Pause\n";
cout << " 2 Restart\n";
cout << " 3 Create new vehicle\n";
cout << " 4 Information about the whole population of a vehicle\n";
cout << " 5 Information about  a certain position in the system \n";
cout << " 6 Information about the whole status(prints the system)\n";
cout << " 7 Enter fire (Will burn everything in this position)\n";
cout << " 8 Enter damage\n";
cout << " 9 Terminate\n";
}


void pause_menu()//emfanizetai kata tin pausi tou programmatos
{
     cout << "\nThe program has been paused. Enter new action\n";
                         cout << " 1) Resume\n";
                         cout << " 2) Restart\n";
                         cout << " 3) Create new vehicle\n";
                         cout << " 4) Information about all vehicles of a kind\n";
                         cout << " 5) Information about a certain position at the system\n";
                         cout << " 6) Information about the whole status(prints the system)\n";
                         cout << " 7) Enter fire (Will burn everything in this position)\n";
                         cout << " 8) Enter damage \n";
                         cout << " 9) Terminate\n";
}
void arson()//Me tin arson o xristis vazei fotia se ena shmeio
{

     int x,y;
     char z='a';

      cout<<"Select place to burn (x,y) :";
      cin>>x>>y;
      if (x>=200||x<0||y>=200||y<0)//o xristis mporei kai na min prospathisei ksana an dosei lathos timi
         {
         do
            {
             cout<<"\n";
             cout<<"Wrong place.Do you want to try again (y\n)?";
             cin>>z;
         if (z=='y')
            continue;
         else if(z=='n')
            break;
         }
         while(z!='y'||z!='n');};
         if (table[x][y].ID==7)
                cout<<"Already on fire\n";
         else
             {
                  if(table[x][y].ID==1||table[x][y].ID==2||table[x][y].ID==3||table[x][y].ID==4||table[x][y].ID==5||table[x][y].ID==0)
                  {
                    table[x][y]=f();}
                  else if(table[x][y].ID==6)
                    {cout<<"This is a base square and will not be burnt immediately.\n";
                     table[x][y].On_Fire++;}
               }

}


void firestarter()//dimiourgei treis foties se tyxaies thesei tou xarti , kaleitai tin proti mera tis evdomadas
{
   int i,j,k;
   fire f();
   for (i=0;i<3;i++)
      {do
         {j=rand()%200;
          k=rand()%200;
          }
       while(table[j][k].ID!=7);//h fotia dimiourgeitai se shmeio pou sen exei idi fotia
       if(table[j][k].ID==0||(table[j][k].ID<6&&table[j][k].ID>2))
            {//~vehicle();
            table[j][k]=f();}
       else if(table[j][k].ID==6)
        {if(table[j][k].On_Fire==2)
            table[j][k]=f();}
        else
            table[j][k].On_Fire++;}
   }



void burn(int x,int y)//eksaplwnei th fwtia , x,y to position tis fotias
{//h burn kaleitai kathe mera
   int r,j,i;
   fire f();
   if (x==0)//fotia stis gwnies
   {
      if(y==0)
      {table[0][1]=f;
       table[1][0]=f;
       table[1][1]=f;}
      else if(y==199)
      {table[0][198]=f;
       table[1][198]=f;
       table[1][199]=f;}
   }
   else if (x==199)
   {
      if(y==0)
      {table[199][1]=f;
       table[198][1]=f;
       table[198][0]=f;}
      else if(y==199)
      {table[199][198]=f;
       table[198][199]=f;
       table[198][198]=f;}
   }
   else if((x!=0)&&(y!=0)&&(y!=199)&&(x!=199))//tyxaio tetragwno pou den einai stis akres
   {
      r=rand()%4;
      switch (r){//apo poia meria e3aplwnetai
      case 0:
         i=x+1;
         for(j=y-1;j<y+2;j++)
            {if((table[i][j].ID==6)&&(table[x][y].On_Fire<2))
             table[i][j].On_Fire++;
             else
              table[i][j]=f;}
      break;
      case 1:
         j=y+1;
         for(i=x-1;i<x+2;i++)
            {if((table[i][j].ID==6)&&(table[x][y].On_Fire<2))
             table[i][j].On_Fire++;
             else
              table[i][j]=f;}
      break;
      case 2:
         i=x-1;
         for(j=y-1;j<y+2;j++)
            {if((table[i][j].ID==6)&&(table[x][y].On_Fire<2))
             table[i][j].On_Fire++;

             else
              table[i][j]=f;}
              break;
      case 3:
         j=y-1;
         for(i=x-1;i<x+2;i++)
            {if((table[i][j].ID==6)&&(table[x][y].On_Fire<2))
             table[i][j].On_Fire++;
             else
              table[i][j]=f;}
              break;
      }
   }
   else // einai stin akri
      {if(x==0)
      {r=rand()%3;
       switch(r)
       { case 0:
            table[0][y-1]=f;
             table[1][y-1]=f;
             table[1][y]=f;
             break;
         case 1:
            table[1][y]=f;
             table[1][y-1]=f;
             table[1][y+1]=f;
             break;
         case 2:
            table[1][y+1]=f;
             table[1][y]=f;
             table[0][y+1]=f;
             break;
       }}
       if(x==199)
      {r=rand()%3;
       switch(r)
       { case 0:
            table[198][y-1]=f;
             table[199][y-1]=f;
             table[199][y]=f;
             break;
         case 1:
            table[198][y]=f;
             table[198][y-1]=f;
             table[198][y+1]=f;
             break;
         case 2:
            table[199][y+1]=f;
             table[198][y]=f;
             table[198][y+1]=f
             break;
       }}
        if(y==0)
      {r=rand()%3;
       switch(r)
       { case 0:
            table[x+1][0]=f;
             table[x+1][1]=f;
             table[x][1]=f;
             break;
         case 1:
            table[x+1][1]=f;
             table[x][1]=f;
             table[x-1][1]=f;
             break;
         case 2:
            table[x-1][0]=f;
             table[x-1][1]=f;
             table[x][1]=f;
             break;
       }}
         if(y==199)
      {r=rand()%3;
       switch(r)
       { case 0:
            table[x+1][199]=f;
             table[x+1][198]=f;
             table[x][198]=f;
             break;
         case 1:
            table[x+1][198]=f;
             table[x][198]=f;
             table[x-1][198]=f;
             break;
         case 2:
            table[x-1][198]=f;
             table[x-1][199]=f;
             table[x][198]=f;
             break;
       }
      }
      }
}


bool scan()//elegxei an olos o xartis exei piasei fotia
{
   bool s;
   int i,j,count;
   for(i=0;i<200;i++)
      for(j=0;j<200;j++)
         if(table[i][j].ID=7)
            count++;
   if (count==40000)
      s=true;//termatizei to programma an s=true
   return s;
}
      }}}}


void Aging(){
  
      int i,j;
     for(i=0;i<200<i++)
     {  for(j=0;j<200;j++)
        {   if(table[i][j].ID!=0&&table[i][j]!=6)//afksisi ths ilikias twn oximatwn kata 1
             {table[i][j].age++;
              if (table[i][j].ID!=7)&&(table[i][j].age>table[i][j].withdraw)
                table[i][j]=S;//an to oxima kseperasei thn ilikia aposyrsis , katastrefetai
             }
        }
      }
   }
         
void initialisation()
{
  int i,j;
  Systhma S();
  base b();

  for (i=0;i<200;i++)
    for (j=0;j<200;j++)
      table[i][j] = S;

  for (i=98;i<102;i++)
    for (j=98;j<102;j++)
      table[i][j] = b;

}


void firefighting(int x,int y)//sunarthsh purosveshs
{
int FF = 0;//metavlhth pou mas vohthaei gia ton elegxo twn triguro thesewn

    while ( (current_water != 0) && (table[x+FF%3-1][y+FF/3-1].ID == 7) && (FF != 9) )//elegxei an uparxei diathesimo nero,an uparxei fwtia kai tis riguro theseis
    {
          if (table[x+FF%3-1][y+FF/3-1] == NULL)//elegxei an einai thesh tou susthmatos
          continue;
    current_water = current_water - water_consumption;//meiwnei to nero
    table[x+FF%3-1][y+FF/3-1].ID= 0;//svhnei thn fwtia
    FF++;//paei sthn epomenh thesh
    }
}
