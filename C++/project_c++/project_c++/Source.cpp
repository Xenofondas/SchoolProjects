#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include "ship.h"
#include <time.h>
#include "map.h"
#include "pirates.h"
#include "functions.h"
#include "trade_ship.h"
#include "service_ship.h"
#include "explorer.h"
#include "fregata.h"
#include "sebek.h"

using namespace::std;


int main(){
	int i,j,k=0;
	
	///*********************************Dhmiourgia Xarth*****************************************//
	
	map table[100][100]; //Xarths
	map p; //  Keno antikeimeno 


	for(i=0; i<100; i++){
		
		for(j=0; j<100; j++){
		   
			table[i][j]=p;
		   //table[i][j].ID=k++;
		   table[i][j].setEntasi();
		
		}
	}

	for(i=0; i<50; i++){
		for(j=0; j<50; j++){
		
			table[rand()%100][rand()%100].setTreasure(); // Orizw tyxaia 2500 theseis thisaurou	
		
		}
	}
	
	for(i=0; i<50; i++){
		for(j=0; j<50; j++){
		
		table[rand()%100][rand()%100].setLimani(); // Orizw tyxaia 100 theseis limaniwn		
		
		}
	}

	///*********************************Dhmiourgia ploiwn*****************************************//
	vector <ship*> ploia;
	
	for(i=0; i<250; i++){
	    
		ploia.push_back(new fregata(1,20,50)) ;    //Kataskeuazw peiratika ploia
		ploia[i]->setCoordinates(); // orizw tuxaies theseis ston pinaka
		ploia[i]->set_aa(i);
	}	
	
	for(i=250; i<500; i++){
	
		ploia.push_back(new trade_ship(2,20,50)) ;  //Kataskeuazw emporika ploia
		ploia[i]->setCoordinates();
		ploia[i]->set_aa(i);
	
	}

	for(i=500; i<750; i++){
		ploia.push_back(new service_ship(3,20,50)) ;     //Kataskeuazw exerevnitika ploia
		ploia[i]->setCoordinates(); // orizw tuxaies theseis 
		ploia[i]->set_aa(i);
	}	
	
	for(i=750; i<1000; i++){
		ploia.push_back(new explorer(4,20,50)) ;  //Kataskeuazw episkeuastika ploia
		ploia[i]->setCoordinates();
		ploia[i]->set_aa(i);
	
	}
	

	//*******************************************************************************************//
	

	

	cout<<"********************************Prosomeiwsh************************************"<<endl<<endl;
	cout<<"Gia ekkinhsh ths prosomeiwshs pasthste kapio plhktro"<<endl;
	cout<<"kata th diarkeia ths prosomeiwshs pieste p gia paush ths prosomeiwshs"<<endl<<endl;
	system("PAUSE");




	
	int d=0;
    bool fl=0;
	
	while(fl==0)
	{
		system("cls");
		print_world(ploia);
		cout<<"Ston xarth vriskontai  "<<ploia.size()<<" ploia."<<endl;
		//cout<<"Exoun ginei "<<ship::get_plEp()<<" epitheseis apo peiratika ploia."<<endl;
		//Sleep(1000);

		if(_kbhit() && _getch()=='p'){
			menu(table,ploia);
		}

		
		elegxos_xarth(table,ploia);
		
		
		for(i=0; i<ploia.size(); i++){
			ploia[i]->movement(); // Kinhsh 
			ploia[i]->leitourgia(1,table,ploia);
		}
		cout<<"Eginan "<<ship::get_plEp()<<" epitheseis apo peiratika ploia."<<endl;
		Sleep(1000);
		elgxos_fin(table,ploia);
		
		

		for(i=0; i<ploia.size(); i++){
			if(ploia[i]->getStuckTr()>1150)
				fl=1;

		}




		d++;
		cout<<"To megethos einai "<<ploia.size()<<endl;
		cout<<"***************************************************************************************"<<endl;
		//Sleep(2000);
	}; 
	
	
	
	cout<<"Termatisan "<<ploia.size()<<" ploia!"<<endl;
	
	cout<<"H prosomoivsh termatistike."<<endl;
	
	
	
	printcrap();
	system("PAUSE");
	
}


	