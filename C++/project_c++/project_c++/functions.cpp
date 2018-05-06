#include <iostream>
#include <cstdlib>
#include "ship.h"
#include <ctime>
#include "map.h"
#include "pirates.h"
#include "functions.h"
#include "trade_ship.h"
#include "fregata.h"
#include "service_ship.h"
#include "explorer.h"


using namespace::std;


void printcrap()
{
	cout <<endl << "It works!!" << endl;
	
}


void elegxos_xarth(map table[100][100],vector <ship*> &ploia) //Synarthsh pou elegxei ton kairo stis theseis pou 
{                                                     //yparxoun ploia
	int i,x,y;

	for(i=0; i<ploia.size(); i++){

		x=ploia[i]->getX_pos();
		y=ploia[i]->getY_pos();
		if(x>=0 && x<=100 && y>=0 && y<=100){


		if(table[x][y].getCurrentEntasi()>7){    // An h entash tou kairou einai megalyterh apo 7 monades 
			ploia[i]->setTrex_antoxi(ploia[i]->getTrex_antoxi()-3); //tote dhmiourgeite zhmia sto ploio.
			ploia[i]->count_damage(3);
		}


		if(table[x][y].getTreasure()==1){    // An yparxei thisauros  
			++*ploia[i];         //auxanete to apothema thisaurou tou ploiu kata 5 monades 
		}


		if(table[x][y].getLimani()==1){    // An yparxei limani  
			pirates *p1 =  dynamic_cast < pirates * > ( ploia[i] );      
			if (p1!=0)   // An einai peiratiko
			{
				//ploia[i]->setTrex_antoxi(ploia[i]->getTrex_antoxi()-4); // prokaleite zhmia
				--*ploia[i]; //Yperfortomenos telesths --
				ploia[i]->count_damage(4);
			}
			else
			{
				ploia[i]->setTrex_antoxi(ploia[i]->getTrex_antoxi()+4);
			}
		
		}
		}	
	}

}

void elgxos_fin(map table[100][100],vector <ship*> &ploia)
{
	int i,j;
	int r;
	/*for(vector<ship*>::iterator it=ploia.begin();  it!=ploia.end() ;it++){ // prospelash me iterator
		
		if((*it)->getTrex_antoxi()<=0){ // Elegxoume an yparxoun ploia me antoxh mikroterh apo 0
			cout<<"To ploio "<<(*it)->get_aa()<<" katastrafhke!"<<endl;
			//delete(&ploia[i]);
			
			//delete * it;
			//it=ploia.erase(it);					
		}
		++it;
	}*/

	for(i=0; i<ploia.size(); i++){
			if(ploia[i]->getTrex_antoxi()<1){
				
				cout<<"to ploio "<<ploia[i]->get_aa()<<" katastrafhke!"<<endl;
				delete ploia[i];
				ploia.erase(ploia.begin()+i);
				
			}
		}
	
	
		for(i=0; i<100; i++){
			for(j=0; j<100; j++){

				r=rand()%2;
				
			switch(r){  // Alazoume tyxaia thn entash pros ta panw h pros ta katw

				case 0:
					if(table[i][j].getCurrentEntasi()<10){
					table[i][j].setNewEntasi(table[i][j].getCurrentEntasi()+1);
					
					}
					break;
				
				case 1:

					if(table[i][j].getCurrentEntasi()>0){
					table[i][j].setNewEntasi(table[i][j].getCurrentEntasi()-1);
					
					}
					break;

				default:
					break;
				}
				

			}
		}


		
		}
	
void insert_ship(vector <ship*> &ploia)
{
	int select;

	cout<<"Dwse tupo ploiou(1.fregata 2.emporiko 3.episkeuastiko 4.exereunitiko)"<<endl;
	do{
		  cout << "Please give your choice(1-5): ";
          cin>>select;

         }while(select<1 || select >5);

	int k=ploia.size();

	switch(select){
		case 1: 
			ploia.push_back(new fregata(1,20,50));
			ploia[k]->setCoordinates();
			ploia[k]->set_aa(k);
			break;

		case 2:
			ploia.push_back(new trade_ship(2,20,50));
			ploia[k]->setCoordinates();
			ploia[k]->set_aa(k);
			break;

		case 3:
			ploia.push_back(new service_ship(3,20,50));
			ploia[k]->setCoordinates();
			ploia[k]->set_aa(k);
			break;
				
		case 4:
			ploia.push_back(new explorer(4,20,50));
			ploia[k]->setCoordinates();
			ploia[k]->set_aa(k);
			break;
			}
	cout<<"To megethos einai "<<ploia.size()<<endl;

}

void menu(map table[100][100],vector <ship*> &ploia)
{
	int ch;

	cout<<"The simulation is paused."<<endl<<endl;
	cout<<"1.Eisagwgh neou ploiou"<<endl;
	cout<<"2.Ektypwsh plhroforias gia ena ploio"<<endl;
	cout<<"3.Ektypwsh pleiroforias gia mia thesh sto xarth"<<endl;
	cout<<"4.Eisagwgh thisaurouv se mia thesh sto xarth"<<endl;
	cout<<"5.Eisagwgh limaniou se mia thesh sto xarth"<<endl;
	cout<<"6.Ektypwsh ploiou me ton perisotero thisuro"<<endl;
	cout<<"Pathste 0 gia synexeia ths proswmeiwshs"<<endl;

	  do{
		  cout << "Please give your choice(1-5): ";
          cin>>ch;
         }while(ch<0 || ch >7);
	

	switch (ch)
	{
	case 1:
		
			insert_ship(ploia);
			menu(table,ploia);
			break;
		
	case 2:
		
			print_ship(ploia);
			menu(table,ploia);
			break;
	case 3:
			print_map(table);
			menu(table,ploia);
			break;
		
	case 4:
			add_treasure(table);
			menu(table,ploia);
			break;
		
	case 5:
			add_limani(table);
			menu(table,ploia);
			break;
	case 6:
			print_bestShip(ploia);
			menu(table,ploia);
			break;
	case 0:
			cout<<"H prwsomeiwsh tha synexistei"<<endl;
			break;

	default:
		break;
	}


}


void print_ship(vector <ship*> &ploia)
{
	int num,e,i;
	bool flag;
	cout<<"Dwse ton arithmo tou ploiou"<<endl;
	
	do{
		  
          cin>>num;
	}while(num<0 || num >ploia.size());
	flag=0;

	for(i=0; i<ploia.size(); i++){
		//cout<<"                              "<<ploia[i]->get_aa()<<num<<endl;
		if(ploia[i]->get_aa()==num){
			flag=1;
				
			e=ploia[i]->geteidos();
			switch (e)
			{
			case 1:
				cout<<"To ploio"<<ploia[num]->get_aa()<<"einai peiratiko"<<endl;
				cout<<ploia[num];
				break;
			case 2:
				cout<<"To ploio"<<ploia[num]->get_aa()<<"einai emporiko"<<endl;
				cout<<ploia[num];
				break;
			case 3:
				cout<<"To ploio"<<ploia[num]->get_aa()<<"einai episkeuastiko"<<endl;
				cout<<ploia[num];
				break;

			case 4:
				cout<<"To ploio"<<ploia[num]->get_aa()<<"einai exereunitiko"<<endl;
				cout<<ploia[num];
				break;

			}
			break;
		}
			
	}
	if(flag==0)
		cout<<"To ploio "<<num<<" exei katatrsafei!"<<endl;

	system("PAUSE");
}

void print_map(map table[100][100])
{
	int x,y;

	do{
		cout << "Dwse syntetagmenh x: ";
          cin>>x;
	}while(x<0 || x >100);

	do{
		  cout << "Dwse syntetagmenh y: ";
          cin>>y;
	}while( y<0 || y >100);

	cout<<"H entash tou kairou sth thesh auth einai "<<table[x][y].getCurrentEntasi()<<endl;
	
	if(table[x][y].getLimani()==1)
		{
			cout<<"Sth thesh auth uparxei limani!"<<endl;
	}
	
	if(table[x][y].getTreasure()==1)
		{
			cout<<"Sth thesh auth uparxei thisauros!"<<endl;
	}

}

void add_treasure(map table[100][100])
{
	int x,y;

	do{
		cout << "Dwse syntetagmenh x "<<endl;
          cin>>x;
	}while(x<0 || x >100);

	do{
		  cout << "Dwse syntetagmenh y "<<endl;
          cin>>y;
	}while( y<0 || y >100);

	if(table[x][y].getTreasure()==1)
	{
		cout<<"H thesh exei apo thn arxh thisauro."<<endl;
	}else
		{
			table[x][y].setTreasure();
			cout<<"Prostethike thisauros."<<endl;
	}

}

void add_limani(map table[100][100])
{
	int x,y;

	do{
		cout << "Dwse syntetagmenh x "<<endl;
          cin>>x;
	}while(x<0 || x >100);

	do{
		  cout << "Dwse syntetagmenh y "<<endl;
          cin>>y;
	}while( y<0 || y >100);

	if(table[x][y].getLimani()==1)
	{
		cout<<"H thesh exei apo thn arxh limani."<<endl;
	}else
		{
			table[x][y].setLimani();
			cout<<"Prostethike limani."<<endl;
	}


}

void print_world(vector <ship*> ploia)
{
	int i,j,k, ei;
	bool f;

	for(i=0; i<18; i++){
		
		for(j=0; j<18; j++){
			f=0;

			for(k=0; k<ploia.size(); k++){
				
				if(ploia[k]->getX_pos()==i && ploia[k]->getY_pos()==j)
				{ f=1;
					/*fregata *fr = dynamic_cast < fregata * >( ploia[k] );
					  if(fr!=0){
						  cout<<" ! ";
						  break;
					  }
				    trade_ship *tr = dynamic_cast < trade_ship * >( ploia[k] );
					  if(tr!=0){
						  cout<<" $ ";
						  break;
					  }
					service_ship *q = dynamic_cast < service_ship * >( ploia[k] );
					  if(q!=0){
						  cout<<" + ";
						  break;
					  }
					 explorer *ex = dynamic_cast < explorer * >( ploia[k] );
					  if(ex!=0){
						  cout<<" # ";
						  break;
					  }
					
					f=1;
					break;
					*/

					ei=ploia[k]->geteidos();
					switch (ei)
					{
					case 1:
						cout<<" ! ";
						break;
					case 2:
						cout<<" $ ";
						break;
					case 3:
						cout<<" + ";
						break;
					case 4:
						cout<<" @ ";
						break;

					default:
						break;
					}
					break;
				}
				
			}
			//cout<<f;

			if(f==0)
				{
					cout<<" 0 ";					
					
			}		
			
		
		}
		cout<<endl;
	}
}

void print_bestShip(vector <ship*> ploia)
{
	int i,max,a,ei,aa;

	max=ploia[1]->getStuckTr();
	for(i=0; i<ploia.size(); i++){
		
		if(ploia[i]->getStuckTr()>max){
		max=ploia[i]->getStuckTr();
		a=i;
		aa=ploia[i]->get_aa();
		}
	}


	ei=ploia[a]->geteidos();
					switch (ei)
					{
					case 1:
						cout<<"To peiratiko ploio me arithmo "<<aa<<" exei sygkentrwsei "<<max<<" monades thisaurou!"<<endl;
						break;
					case 2:
						cout<<"To emporiko ploio me arithmo "<<aa<<" exei sygkentrwsei "<<max<<" monades thisaurou!"<<endl;
						break;
					case 3:
						cout<<"To episkeuastiko ploio me arithmo "<<aa<<" exei sygkentrwsei "<<max<<" monades thisaurou!"<<endl;
						break;
					case 4:
						cout<<"To exereunitiko ploio me arithmo "<<aa<<" exei sygkentrwsei "<<max<<" monades thisaurou!"<<endl;
						break;

					default:
						break;
					}


}

