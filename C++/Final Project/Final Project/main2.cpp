#include "classes.cpp"
#include "Functions_1.cpp"
#include "Functions_2.cpp"
#include "Functions_3.cpp"
#include "Functions_4.cpp"

main()
{

int day=1;int week=0;int month=0;//dhlwnei mera mhna kai evdomada kai arxikopoioume
int i,j;
bool restart=0;//metavlhth pou elegxei an ginete epanekinhsh
bool pause=0;//metavlhth pou elegxei an to programma kanei paush
char ans;//metavlhth sthn opoia ekxwreitai epilogh tou xristi
bool sar=0;
   initialisation();//ftiaxnei to susthma
   start_up_vehicles();//eisagei oxhmata me tuxaio tropo
   menu();//emfanizei to menu epilogwn
   firestarter();
for(;;)
{  
   if (kbhit() != 0)
 {       
       ans=(char) getch();//dinei o xrhsths mia epilogh me vash to menu
       if  (ans=='1')
         {
             pause=1;
             while (pause=1)//elegxei an to programma eksakolouthei na einai se paush
         {  
              pause_menu();
              ans1=(char) gets();//dinei o xrhsths mia epilogh me vash to menu pausis
              if (ans1=='1')
              pause=0;
              else if (ans1=='2')
              {
                  pause=0;
                  restart=1;
              }
              else if (ans1=='3')
               newvehicle();
              else if (ans1=='4')
               vehicle_status;
              else if (ans1=='5')
               position_status();
              else if (ans1=='6')
                world_status();
              else  if (ans1=='7')
                arson();
              else if (ans1=='8')
                damage();
              else if (ans1=='9')
              {
                   pause=0;
                   ans='9';
              }
             else 
               cout<<"wrong entry. Nothing happend\n"; //emfanizetai an o xrhsths dwsei allh entolh ektos autwn pou orizei to menu pausis    
         }     
     }
     else if (ans=='2')
          restart=1;
     else if (ans=='3')
          newvehicle();   
     else if (ans=='4')
        vehicle_status();
     else if (ans=='5')
       position_status();
     else if (ans=='6')
      world_status();
     else if (ans=='7')
      arson();
     else if (ans=='8')
       damage_dealer();
     else if (ans=='9')
       break; 
     else 
      cout << "Wrong entry. Nothing happened \n";
  }
                
  if (restart==1)//shmenei oti o xrhsths exei pathsei restart
   {//ksanathetoume to programma sthn arxikh tou morfh
              day = 1; 
              week = 0; 
              month = 0;
   menu();
   initialisation();
   strat_up_vehicles();
   restart=0;//allazoume thn metvlhth se faulse esti wste na mn ksanakanei epanekinhsh
   }
   
  Sleep(1500); //kathe mera leitourgei me kathisterish 1500 monadwn xronou
   
  sar=scan();
  if (sar==1)//an exei piasei fwtia se olo to susthma termatizei to programma
  break;
  for(i=0;i<200;i++)
   for(j=0;j<200;j++)
      if((table[i][j].ID==7)&&(table[i][j].age!=0))
         burn(i,j);
  
  day++;
   if (day == 8) //auksanei thn vdomada
   {
            firestarter();
            Aging(); 
            week ++; 
            day = 1;
      }
  if (week == 5) //auksanei ton mhna
     {
          month++; 
          week = 1;
     }
    cout << "Another day has passed. We are now at " << day << "days "<< week << "weeks "<< month << "months \n";
}
system ("PAUSE");
}
