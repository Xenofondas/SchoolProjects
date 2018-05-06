void damage_dealer ()
{
  char insert_damage_temp, repeat_damage;
  int x,y;
  //h synarthsh edw mas epitrepei na eisagoume zhmia se kapoio oxhma ean kai mono to vroume apo thn eisagwgh pou kanei o xrhsths
  //
  //

  do{
  cout << "Pick a position, x must be between 0 and 199, same applies to y as well" << endl;
  cout << "Enter x" << endl;
  cin >> x ;
  cout << "Enter y" << endl;
  cin >> y ;

  if (table[x][y].ID == 1)
    { cout << "You chose an airplane, would you like to insert damage?" << endl ;
      cout << "Press y for yes or n for no:" << endl;
      do{cin >> insert_damage_temp; if (insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N'){
	  cout << "Wrong entry: Insert Y/y for yes or N/n for no" << endl;}  }
      while(insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N');

      if (insert_damage_temp == 'Y' || insert_damage_temp == 'y') { table[x][y].damage = 1; }
    }
  else if (table[x][y].ID == 2)
    { cout << "You chose a helicopter, would you like to insert damage?" << endl ;
      cout << "Press y for yes or n for no:" << endl;
      do{cin >> insert_damage_temp; if (insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N'){
	  cout << "Wrong entry: Insert Y/y for yes or N/n for no" << endl;}  }
      while(insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N');

      if (insert_damage_temp == 'Y' || insert_damage_temp == 'y') { table[x][y].damage = 1; }
    }
  else if (table[x][y].ID == 3)
    { cout << "You chose an SUV, would you like to insert damage?" << endl ;
      cout << "Press y for yes or n for no:" << endl;
      do{cin >> insert_damage_temp; if (insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N'){
	  cout << "Wrong entry: Insert Y/y for yes or N/n for no" << endl;}  }
      while(insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N');

      if (insert_damage_temp == 'Y' || insert_damage_temp == 'y') { table[x][y].damage = 1; }
    }
  else if (table[x][y].ID == 4)
    { cout << "You chose a rescue firetruck, would you like to insert damage?" << endl ;
      cout << "Press y for yes or n for no:" << endl;
      do{cin >> insert_damage_temp; if (insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N'){
	  cout << "Wrong entry: Insert Y/y for yes or N/n for no" << endl;}  }
      while(insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N');

      if (insert_damage_temp == 'Y' || insert_damage_temp == 'y') { table[x][y].damage = 1; }
    }
  else if (table[x][y].ID == 5)
    { cout << "You chose a ladder firetruck, would you like to insert damage?" << endl ;
      cout << "Press y for yes or n for no:" << endl;
      do{cin >> insert_damage_temp; if (insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N'){
	  cout << "Wrong entry: Insert Y/y for yes or N/n for no" << endl;}  }
      while(insert_damage_temp != 'Y' && insert_damage_temp != 'y' && insert_damage_temp != 'n' && insert_damage_temp != 'N');

      if (insert_damage_temp == 'Y' || insert_damage_temp == 'y') { table[x][y].damage = 1; }
    }
  else if (table[x][y].ID == 6)
    { cout << "You chose a base's position" << endl; }
  else if (table[x][y].ID == 7)
    { cout << "You choose a position that is on fire." << endl; }

  cout << "\nWould you like to repeat the damage's function? " << endl;
      cout << "Press y for yes or n for no:" << endl;
      do{cin >> repeat_damage ; if (repeat_damage != 'Y' && repeat_damage != 'y' && repeat_damage != 'n' && repeat_damage != 'N'){
	  cout << "Wrong entry: Insert Y/y for yes or N/n for no" << endl;}  }
      while(repeat_damage != 'Y' && repeat_damage != 'y' && repeat_damage != 'n' && repeat_damage != 'N');
  }
  while(repeat_damage == 'Y' || repeat_damage == 'y');
}






void movement(int x, int y) // h synarthsh ths kinhshs
{
 int speed_timer=0;
 int R;
 int temp_swap;
 for (R=0;R<9;R++)
{
  if (table[x+R%3-1][y+R/3-1] == NULL) // elegxoume an kathe tetragwnaki gyrw tou einai mesa sto table (se diaforetikh periptwsh to (x.y)
                                       // tha einai kapoio shmeio sthn perimetro tou table
    continue;

  if (table[x+R%3-1][y+R/3-1].ID == 7) // elegxoume an yparxei fwtia trygyrw wste na ektelesei thn synarthsh ths pyrosveshs
    firefighting(x,y);
}


 if (table[x+R%3-1][y+R/3-1] == base) // an synanthsei thn vash gemizei ta apothemata tou kai diorthwnei tis vlaves tou
{
  refill();
}

 if (current_gas != 0 && current_water !=0 && damage == 0) // an exei apothemata kausimou kai nerou, kai den exei zhmia mporei na kinithei
{
  do{// analoga me to speed kathe oxhmatos, tha dianyei sygkekrimeno plithos tetragwnwn

    if (table[x][y].ID==1 || table[x][y].ID==2) // an einai aircraft, dhladh aeroplano i elikoptero
  {
    int MA; // mia voithitiki metavliti gia ton elegxo twn gyrw tetragwnwn

    do
      {
        MA = rand() % 9; // h synarthsh kinhshs einai tyxaia
      }
    while( table[x + MA%3 - 1][y + MA/3 - 1] == NULL || table[x + MA%3 - 1][y + MA/3 - 1] == base ); // oso den einai bash h keno trigyrw proxwraei,
                                                                                                     // gia fwtia eixame elegksei sthn arxh
    table[x][y] = table[x + MA%3 - 1][y + MA/3 - 1] ; // to oxhma proxwraei sthn random timh pou edwse h rand()%9

    table[x - MA%3 + 1][y - MA/3 + 1] = S(); // sto shmeio pou htan prin, thetoume oti egine keno
  }

    else if (table[x][y].ID == 3 || table[x][y].ID == 4 || table[x][y].ID == 5) // an einai oxhma kshras, dhladh SUV, diaswstiko, h h skala
  {

    int MG; // allh mia voithitiki metavliti gia ton elegxo twn gyrw tetragwnwn

    do
      {
        MG = (rand() % 5) - 2; // synarthsh kinhshs <- tyxaia
      }
    while ( table[x+MG%2][y+MG/2] == NULL || table[x+MG%2][y+MG/2] == base ); // oso den einai bash h keno trigyrw proxwraei, gia fwtia eixame elegksei sthn arxh
        table[x][y] = table[x + MG%2][y + MG/2]; // proxwraei sto shmeio pou dwthike apo th rand
	table[x - MG%2][y - MG/2] = S(); // sto shmeio pou htan prin thetei pali to keno
  }


    speed_timer++; // edw exoume enan metrhth o opoios auksanete kata 1 se kathe kinhsh kata 1 tetragwno
  }while(table[x][y].speed != speed_timer); //opote otan ginei isos me thn timh ths taxythtas tou oxhmatos pou kinoume teleiwnei h do...while
}
 else // an den exei apothemata kausimou(thewroume oti exei pronohsei kai exei arketo apothema gia na epistrepsei)
   //eite apothemata nerou, eite parousiasei vlavh ektelei th synarthsh epistrofhs sthn vash gia anefodiasmo / episkeuh
  return_to_base();


}







void position_status ()
{
  char check_answer_for_repeat;
  bool another_check = false;
do
  {

  cout << "\nΔιαλέξτε ένα τετράγωνο για να λάβετε τις πληροφορίες σχετικά με αυτό" << endl;
  cout << "Οι επιτρεπτές τιμές για το x είναι 0 έως και 199. Ομοίως και για το y:" << endl;
  cout << "Δώστε πρώτα την τιμή του x και ύστερα του y" << endl;
do
  {
    cin >> x >> y ;

    if (!(x>=0 && x<200 && y>=0 && y<200))
	cout << "Δώσατε λάθος τιμές, δοκιμάστε πάλι:" << endl;
  }
 while(!(x>=0 && x<200 && y>=0 && y<200));

      switch (table[x][y].ID)
	{
	case 1:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι στο οποίο υπάρχει ελικόπτερο." << endl;
	  cout << "Η ηλικία του ελικοπτέρου είναι " << hel.age << endl;
	  cout << "Διαθέτει " << hel.current_gas << "λίτρα καυσίμου.";
	  cout << "και " << hel.current_water << "λίτρα νερού για πυρόσβεση." << endl;
	  break;
	case 2:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι στο οποίο υπάρχει αεροπλάνο." << endl;
	  cout << "Η ηλικία του αεροπλάνου είναι " << air.age << endl;
	  cout << "Διαθέτει " << air.current_gas << "λίτρα καυσίμου.";
	  cout << "και " << air.current_water << "λίτρα νερού για πυρόσβεση." << endl;
	  break;
	case 3:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι στο οποίο υπάρχει SUV." << endl;
	  cout << "Η ηλικία του αυτοκινήτου είναι " << s.age << endl;
	  cout << "Διαθέτει " << s.current_gas << "λίτρα καυσίμου.";
	  cout << "και " << s.current_water << "λίτρα νερού για πυρόσβεση." << endl;
	  break;
	case 4:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι στο οποίο υπάρχει διασωστικο." << endl;
	  cout << "Η ηλικία του διασωστικού είναι " << re.age << endl;
	  cout << "Διαθέτει " << re.current_gas << "λίτρα καυσίμου.";
	  cout << "και " << re.current_water << "λίτρα νερού για πυρόσβεση." << endl;
	  break;
	case 5:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι στο οποίο υπάρχει πυροσβεστικό με σκάλα." << endl;
	  cout << "Η ηλικία του πυροσβεστικού(σκάλα) είναι " << l.age << endl;
	  cout << "Διαθέτει " << l.current_gas << "λίτρα καυσίμου.";
	  cout << "και " << l.current_water << "λίτρα νερού για πυρόσβεση." << endl;
	  break;
	case 6:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι της βάσης." << endl;
	  if (table[x][y].On_Fire == 0)
	    {cout << "και δεν υπάρχει φωτιά." << endl;}
	  else if (table[x][y].On_Fire == 1)
	    {cout << "και υπάρχει μικρή φωτιά." << endl;}
	  else if (table[x][y].On_Fire == 2)
	    {cout << "και υπάρχει μεγάλη φωτιά." << endl;}
	  break;
	case 7:
	  cout << "\nΔιαλέξατε ένα τετραγωνάκι το οποίο έχει φωτιά, και έχει";
          cout << " καταστραφεί οτιδήποτε προϋπήρχε στη θεση αυτή" << endl;
	  break;
	}


      cout << "\n Θα θέλατε να επαναλάβετε την διαδικασία για κάποια νέα θέση;" << endl ;
      cout << "Press y for yes or n for no:" << endl ;
      do{
	cin >> check_answer_for_repeat ;
	if ( check_answer_for_repeat != 'Y' && check_answer_for_repeat != 'y' &&check_answer_for_repeat != 'N' &&check_answer_for_repeat != 'n' )
	  cout << "Wrong entry, try Y/y for yes, or N/n for no:" << endl;
      }while( check_answer_for_repeat != 'Y' && check_answer_for_repeat != 'y' &&check_answer_for_repeat != 'N' &&check_answer_for_repeat != 'n' );


	if (check_answer_for_repeat == 'y' || check_answer_for_repeat == 'Y')
	  {another_check = true ;}

  }while( another_check );

}




void refill() // synarthsh pou ekteleitai otan kapoio oxhma ftasei sth bash
{

  current_gas = gas_capacity;
  current_water = water_capacity;
  damage = 0;

}
