void newvehicle()
{

int i;int j;int age;int type;
char ans;
int gas;int water;

  do
  {
          cout << "Give a number between 1-5 for the vehicle you want to create \n";
          cout << "1. helicopter\n2. airplane \n3.suv \n4. rescue\n5. lader \n";
         cin >> type;

      if (type <1 || type >5)
       cout <<"try again\n";
    }
     while (type <1 || type >5);//zhtame apo to xrhsth na dwsei mia epilogh mexri na dwsei thn swsth


  do
  {
       cout<<"give two numbers that indicate the place of the vehicle,the numbers must be between x=0-199 and y=0-199 \n"<<"for example (15,18) or (105,15)\n";
       cin>>i,j;

       if ((i>=0)&&(i<200)&&(j>=0)&&(j<200))//an einai entos twn oriwn tou pinaka emfanizei thn thesh
       cout<<"("<<i<<","<<j<<")";
       else
       cout<<"try again and give the correct numbers\n";

       if ((table[i][j].ID < 6) && (table[i][j].ID  > 0))//elegxei an uparxei allo oxhma se auth thn thesi
       cout<<"a vehicle in this place already exists,try agian\n";
       else if (table[i][j].ID == 6)//elegxei an einai h vash
       {
       cout<<"the base is in this position, try again\n";
       continue;
       }

     if (table[i][j].ID==7)//elegxei an einai fwtia
     {
                      cout<<"there is a fire in this place you want to continue? y/n\n"<<"if you continue the vehicle will be destoyed\n";

     do
     {
     cin>>ans;

     if ((ans!='y')||(ans!='n')||(ans!='Y')||(ans!='N'))
     cout<<"give only y for yes or n for no\n"<<"try again\n";
     }
     while ((ans!='y')||(ans!='n')||(ans!='Y')||(ans!='N'));//epanalhpsh mexri na dwsei thn swsth epilogh


     if ((ans=='y') || (ans=='Y'))//an sunexisei katastrefei to oxhma kai termatizei thn sunarthsh
       {
             cout<<"the vehicle is destroyed"<<endl;
             ~vehicle();
             break;
       }
     else
       {
             cout<<"give new coordinates\n";
             continue;
       }
}
}
     while ( (i<0) || (i>200) || (j<0) || (j>200) || ( table[i][j].ID < 6 && table[i][j].ID > 0) );//elegxei an einai oi swstes suntetagmenes kai uparxei oxhma se auth thn thesh





     if (type == 1)//elegxei an einai elikoptero
{
             cout << "Give gas. It must be between 0 and 300 litre\n";
             cin >> gas;
             while ((gas <0) || (gas > 300)) //Μέγεθος μεταξύ 0-300
             {
                   cout << "Wrong size. It must be between 0 and 300\n";
                   cin >> gas;
             }

 cout << "Give water. It must be between 0 and 400 litre\n";
             cin >> water;
             while (water <0 || water > 400) //Μέγεθος μεταξύ 0-400
             {
                   cout << "Wrong size. It must be between 0 and 400\n";
                   cin >> water;
             }

cout << "Give the age of the vehicle.\n" ;
             cin >>age;
             while (age <=0 || age >5)
             {
                   cout << "Wrong age. It must be between 0 and 5\n";
                   cin >> age;
             }

             helicopter hel(gas,water,age,i,j);//dhmiourgei ena antikeimeno elikopterou me orismata tis parapanw metavlhtes

	     table[i][j]=hel;//ekxwrei sthn sugekrimenh thesh tou pinaka ena elikoptero

      //oi duo parakatw sunthikes elegxoun an uparxei diathesimo kausimo h nero an oxi kaloun thn sunarthsh epistrofhs sthn vash
if (water==0)
{
cout<<"need water return to base";
return_to_base();
}
if (gas==0)
{
cout<<"need gas return to base";
return_to_base();
}
}




 if (type == 2)//elegxei an einai aeroplano
{
             cout << "Give gas. It must be between 0 and 400 litre\n";
             cin >> gas;
             while (gas <0 || gas > 400) //Μέγεθος μεταξύ 0-400
             {
                   cout << "Wrong size. It must be between 0 and 400\n";
                   cin >> gas;
             }

 cout << "Give water. It must be between 0.0 and 500.0 litre\n";
             cin >> water;
             while (water <0 || water > 500) //Μέγεθος μεταξύ 0-500
             {
                   cout << "Wrong size. It must be between 0 and 500\n";
                   cin >> water;
             }

cout << "Give the age of the vehicle.";
             cin >> age;
             while (age <0 || age > 4) //Μέγεθος μεταξύ 0-4
             {
                   cout << "Wrong age. It must be between 0 and 4\n";
                   cin >> age;
             }


            airplane air(gas,water,age,i,j);
table[i][j]=air;

if (water==0)
{
cout<<"need water return to base";
return_to_base();
}

if (gas==0)
{
cout<<"need gas return to base";
return_to_base();
}

}



if (type == 3)//elegxei an einai suv
{
             cout << "Give gas. It must be between 0 and 60 litre\n";
             cin >> gas;
             while (gas <0|| gas > 60) //Μέγεθος μεταξύ 10-20
             {
                   cout << "Wrong size. It must be between 0 and 60\n";
                   cin >> gas;
             }

       cout << "Give water. It must be between 0 and 200 litre\n";
             cin >> water;
             while (water <0 || water > 200) //Μέγεθος μεταξύ 0-200
             {
                   cout << "Wrong size. It must be between 0 and 200\n";
                   cin >> water;
             }

cout << "Give the age of the vehicle.";
             cin >> age;
             while (age <0 || age > 10) //Μέγεθος μεταξύ 0-10
             {
                   cout << "Wrong size. It must be between 0 and 400\n";
                   cin >> age;
             }
             SUV s(gas,water,agei,j);
table[i][j]=s;
if (gas==0)
{cout<<"need gas return to base";
return_to_base();
}
if (water==0)
{cout<<"need water return to base";
return_to_base();
}
}
if (type == 4)
{
             cout << "Give gas. It must be between 0 and 100 litre\n";
             cin >> gas;
             while (gas <0|| gas > 100) //Μέγεθος μεταξύ 0-100
             {
                   cout << "Wrong size. It must be between 0 and 100\n";
                   cin >> gas;
             }

 cout << "Give water. It must be between 0 and 500 litre\n";
             cin >> water;
             while (water <0 || water > 500) //Μέγεθος μεταξύ 0-500
             {
                   cout << "Wrong size. It must be between 0 and 200\n";
                   cin<< water;
                   }
             cin >> age;
             while (age <0 || age > 10) //Μέγεθος μεταξύ 0-10
             {
                   cout << "Wrong size. It must be between 0 and 400\n";
                   cin >> age;
             }
            rescue re (gas,water,agei,j);
table[i][j]=re;
if (gas==0)
{cout<<"need gas return to base";
return_to_base();
}
if (water==0)
{cout<<"need water return to base";
return_to_base();
}
}

if (type == 5)
{
             cout << "Give gas. It must be between 0 and 100 litre\n";
             cin >> gas;
             while (gas <0 || gas > 200) //Μέγεθος μεταξύ 0-200
             {
                   cout << "Wrong size. It must be between 0 and 200\n";
                   cin >> gas;
             }

           cout << "Give water. It must be between 0 and 200 litre\n";
             cin >> water;
             while (water <0 || water >1000) //Μέγεθος μεταξύ 0-1000
             {
                   cout << "Wrong size. It must be between 0 and 1000\n";
                   cin >> water;
             }

          cout << "Give the age of the vehicle." ;
             cin >> age;
             while (age <0|| age > 10) //Μέγεθος μεταξύ 0-10
             {
                   cout << "Wrong age. It must be between 0 and 10\n";
                   cin >> age;
             }
             ladder l(gas,water,age,i,j);
           table[i][j]=l;
        if (gas==0)
        {cout<<"need gas return to base";
             return_to_base();
           }
           if (water==0)
           {
           cout<<"need water return to base";
           return_to_base();
           }
}

}


void strat_up_vehicles() { // sunarthsh sthn opoia tha dhmiourgoume tuxaia oxhmata

     int age;
     int  water;
     int gas;
     int x; int y; int i; int j;

for(j=0; j<13; j++) //tha dhmiourgisoume 13 oxhmata gia kathe tupo
     {
         for (i=0;i<5;i++)
     {
         do{
                      x=rand()%200;
                      y=rand()%200;
                      }
          while (table[x][y].ID!=0);
          if (i==0)
           {
             age = (rand()%((helicopter().withdraw)-1)); //tha exei tuxaia hlikia apo 0 ews thn hlikia aposurshs tou-1

             gas= (rand()%(helicopter().gas_capacity-10));//tha exei tuxaio arithmo kausimwn apo 0 ews to gas capasity tou -10
             water=(rand()%(helicopter().water_capacity-10));//tha exei tuxaio aritho nerou apo 0 ews to sunoliko megethos nerou tou -10
             helicopter hel(gas,water,age,x,y);
             table[x][y]=hel;
             }
          else if (i==1)
    {        age = (rand()%((airplane().withdraw)-1));
             gas= (rand()%(airplane().gas_capacity-10));
             water=(rand()%(airplane().water_capacity-10));
             airplane air(gas,water,age,x,y);
     table[x][y]=air;
     }
     else if (i==2)
     {
           age = (rand()%((SUV().withdraw)-1));
             gas= (rand()%(SUV().gas_capacity-10));
             water=(rand()%(SUV().water_capacity-10));
             SUV s(gas,water,age,x,y);
             table[x][y]=s;
             }
        else if (i==3)
        {
            age = (rand()%((ladder().withdraw)-1));
             gas= (rand()%(ladder().gas_capacity-10));
             water=(rand()%(ladder().water_capacity-10));
             ladder l(gas,water,age,x,y);
     table[x][y]=l;
     }
      else
      {
           age = (rand()%((rescue().withdraw)-1));
             gas= (rand()%(rescue().gas_capacity-10));
             water=(rand()%(rescue().water_capacity-10));
             rescue re(gas,water,age,x,y);
            table[x][y]=re;
            };
};
} ;







}
