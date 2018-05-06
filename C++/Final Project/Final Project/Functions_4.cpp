void return_to_base()
{
  bool returned_to_base = 0;
  int R =0;
  if ((ID > 2)&&(ID < 6))
{

do
  {
    if (x>y && x+y<199 && x<100) // PANW ARISTERA , gia to panw aristera oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
         else if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
	 else if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
	 else if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
       }
    if (x>y && x+y<199 && x>99) // PANW DEKSIA , gia to panw deksia oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
	 else if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
	 else if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
	 else if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
       }
    if (x>y && x+y>199 && y<100) // DEKSIA PANW , gia to deksia panw oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
	 else if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
	 else if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
	 else if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
       }
    if (x>y && x+y>199 && y>99) // DEKSIA KATW , gia to deksia katw oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
	 else if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
	 else if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
	 else if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
       }
    if (x<y && x+y>199 && x>99) // KATW DEKSIA , gia to katw deksia oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
	 else if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
	 else if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
	 else if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
       }
    if (x<y && x+y>199 && x<100) // KATW ARISTERA , gia to katw aristera oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
	 else if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
	 else if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
	 else if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
       }
    if (x<y && x+y<199 && y>99) // ARISTERA KATW , gia to aristera katw oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
	 else if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
	 else if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
	 else if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
       }
    if (x<y && x+y<199 && y<100) // ARISTERA PANW , gia to aristera panw oktamorio tha prepei na akoulthisei tis parakatw entoles gia na epistrepsei sth bash
       {
	 if (table[x][y+1].ID == 0)
	 {y++; table[x][y-1] = S();}
	 else if (table[x+1][y].ID == 0)
	 {x++; table[x-1][y] = S();}
	 else if (table[x-1][y].ID == 0)
	 {x--; table[x+1][y] = S();}
	 else if (table[x][y-1].ID == 0)
	 {y--; table[x][y+1] = S();}
       }
    for (R=0;R<9;R++) {if( table[x+R%3-1][y+R/3-1] == base) {returned_to_base = 1; refill();}} // an vrei thn bash kanei thn synarthsh refill
                                                                                               // kai vgainei apo to do...while
  }
 while(returned_to_base == 0);}



  if ((ID == 1)||(ID ==2)) // an einai aircraft petaei diagwnia
    {

if (((x==98)||(x==99)||(x==100)||(x==101))&&(y>99))
  {do{y--; table[x][y+1] = S();}while(y!=102); refill();}
if (((x==98)||(x==99)||(x==100)||(x==101))&&(y<100))
  {do{y++; table[x][y-1] = S();}while(y!=97); refill();}

if (((y==98)||(y==99)||(y==100)||(y==101))&&(x>99))
  {do{x--; table[x+1][y] = S();;}while(x!=102); refill();}
if (((y==98)||(y==99)||(y==100)||(y==101))&&(x<100))
  {do{x++; table[x-1][y] = S();}while(x!=97); refill();}

if ((x<98)&&(y<98))
  {
    if (x>y)
      {do{x++; y++; table[x-1][y-1] = S();}while(x!=97); while(y!=97){y++; table[x][y-1] = S();} refill();}
    else
      {do{x++; y++; table[x-1][y-1] = S();}while(y!=97); while(x!=97){x++; table[x-1][y] = S();} refill();}
  }

if ((x<98)&&(y>101))
  {
    if (x+y<200)
      {do{x++; y--; table[x-1][y+1] = S();}while(y!=102); while(x!=97){x++; table[x-1][y] = S();} refill();}
    else
      {do{x++; y--; table[x-1][y+1] = S();}while(x!=97); while(y!=102){y--; table[x][y+1] = S();} refill();}
  }

if ((x>101)&&(y<98))
  {
    if (x+y<200)
      {do{x--; y++; table[x+1][y-1] = S();}while(x!=102); while(y!=97){y++; table[x][y-1] = S();} refill();}
    else
      {do{x--; y++; table[x+1][y-1] = S();}while(y!=97); while(x!=102){x--; table[x+1][y] = S();} refill();}
  }

if ((x>101)&&(y>101))
  {
    if (x>y)
      {do{x--; y--; table[x+1][y+1] = S();}while(y!=102); while(x!=102){x--; table[x+1][y] = S();} refill();}
    else
      {do{x--; y--; table[x+1][y+1] = S();}while(x!=102); while(y!=102){y--; table[x][y+1] = S();} refill();}
  }

}

}







void world_status()
{
  int i,j;

  //edw h synarthsh sarwnei olon ton kosmo kai ektypwnei se kathe thesh tou to antikeimeno pou vrisketai ekei
  //shmeiwste oti thelei toulaxiston 200 sthles perithwrio sth grammh entolwn(p.x. to cmd) gia na ektypwthei xwris paramorfwsh
  //ektypwnei keno (space) gia thesh tou pinaka pou den periexei fwtia vash h kapoio pyrosvestiko oxhma
  //E gia elikoptera, A gia aeroplana, S gia SUV, R gia diaswstika, L gia skales, B gia vash kai F gia fwtia


  for (i=0;i<200;i++)
    {
      cout << endl;

    for (j=0;j<200;j++)
      {
	switch (table[j][i].ID) {
      case 1:
	cout << "E";
	break;
      case 2:
	cout << "A";
	break;
      case 3:
	cout << "S";
	break;
      case 4:
	cout << "R";
	break;
      case 5:
	cout << "L";
	break;
      case 6:
	cout << "B";
	break;
      case 7:
	cout << "F";
	break;
      default:
	cout << " "; }
	break;
      }
    }

  cout << endl;

}







void vehicle_status()
{
  int i,j;
  int type_of_vehicle;
  char repeat_choice;
  int E = 0, Ewater = 0, Egas = 0;
  int A = 0, Awater = 0, Agas = 0;
  int J = 0, Jwater = 0, Jgas = 0;
  int R = 0, Rwater = 0, Rgas = 0;
  int L = 0, Lwater = 0, Lgas = 0;
  int F = 0, Fwater = 0, Fgas = 0;

// to *gas einai h synolikh venzinh pou exei olos o kosmos sto * oxhma, opou E elikoptero, A aeroplano, J SUV, R rescue, L ladder, F fwtia
// akolouthei mia sarwsh olou tou pinaka pou anathetei stis parapanw metavlhtes tis times tous



  for (i=0;i<200;i++)
    {
      cout << endl;

    for (j=0;j<200;j++)
      {
	switch (table[j][i].ID) {
      case 1:
	E++; Egas += table[j][i].current_water; Ewater += table[j][i].current_gas;
	break;
      case 2:
	A++; Agas += table[j][i].current_water; Awater += table[j][i].current_gas;
	break;
      case 3:
	J++; Jgas += table[j][i].current_water; Jwater += table[j][i].current_gas;
	break;
      case 4:
	R++; Rgas += table[j][i].current_water; Rwater += table[j][i].current_gas;
	break;
      case 5:
	L++; Lgas += table[j][i].current_water; Lwater += table[j][i].current_gas;
	break;
      case 7:
	F++;
	break;
      }
    }
}
  cout << endl;


  do {
  cout << " gia thn epilogh elikopterwn pathste 1" << endl ;
  cout << " gia aeroplana pathste 2" << endl ;
  cout << " gia SUV patiste 3" << endl ;
  cout << " gia rescue (diaswstiko) patiste 4" << endl ;
  cout << " gia ladder (skala) patiste 5" << endl ;
  cin >> type_of_vehicle ;
  }while( type_of_vehile != 1 && type_of_vehile != 2 && type_of_vehile != 3 && type_of_vehile != 4 && type_of_vehile != 5 );




do
  {
    switch (type_of_vehicle){
    case 1:
  cout << "Υπάρχει/ουν " << E << "ελικόπτερο/α στον κόσμο μας." << endl;
  cout << "ta opoia exoun sto synolo tous" << Ewater/E << "% apothemata nerou." << endl;
  cout << "kai " << Egas/E << "% apothemata kausimwn." << endl ;
  break;
    case 2:
  cout << "Υπάρχει/ουν " << A << "αεροπλάνο/α στον κόσμο μας." << endl;
  cout << "ta opoia exoun sto synolo tous" << Awater/A << "% apothemata nerou." << endl;
  cout << "kai " << Agas/A << "% apothemata kausimwn." << endl ;
  break;
    case 3:
  cout << "Υπάρχει/ουν " << J << "πυροσβεστικό/ά SUV στον κόσμο μας." << endl;
  cout << "ta opoia exoun sto synolo tous" << Jwater/J << "% apothemata nerou." << endl;
  cout << "kai " << Jgas/J << "% apothemata kausimwn." << endl ;
  break;
    case 4:
  cout << "Υπάρχει/ουν " << R << "διασωστικό/ά στον κόσμο μας." << endl;
  cout << "ta opoia exoun sto synolo tous" << Rwater/R << "% apothemata nerou." << endl;
  cout << "kai " << Rgas/R << "% apothemata kausimwn." << endl ;
  break;
    case 5:
  cout << "Υπάρχει/ουν " << L << "πυροσβεστικό/ά με σκάλα στον κόσμο μας." << endl;
  cout << "ta opoia exoun sto synolo tous" << Lwater/L << "% apothemata nerou." << endl;
  cout << "kai " << Lgas/L << "% apothemata kausimwn." << endl ;
  break;
    case 7:
  cout << "Υπάρχει/ουν " << F << "φωτιά/ές στον κόσμο μας." << endl;
  break;}

    do{
      cout << "Thelete na epanalavete thn diadikasia;" << endl ;
	cin >> repeat_choice ;
	if ( repeat_choice != 'Y' && repeat_choice != 'y' && repeat_choice != 'N' && repeat_choice != 'n' )
	  cout << "Wrong entry, try Y/y for yes, or N/n for no:" << endl;
      }while( repeat_choice != 'Y' && repeat_choice != 'y' && repeat_choice != 'N' && repeat_choice != 'n' );




  }
 while( repeat_choice == 'y' || repeat_choice == 'Y' );

}
