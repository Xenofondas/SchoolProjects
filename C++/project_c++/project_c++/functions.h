#pragma once
#include "ship.h"
#include "map.h"
#include <algorithm>

void printcrap();

void elegxos_xarth(map table[100][100],vector <ship*> &ploia); //Arxikos elegxos

void elgxos_fin(map table[100][100],vector <ship*> &ploia); //Telikos elegxos

void insert_ship(vector <ship*> &ploia);//Synarthsh gia eisgwgh neou ploiou

void menu(map table[100][100],vector <ship*> &ploia);

void print_ship(vector <ship*> &ploia);

void print_map(map table[100][100]);

void add_treasure(map table[100][100]);

void add_limani(map table[100][100]);

void print_world(vector <ship*> ploia);

void print_bestShip(vector <ship*> ploia);

void kataksi_ploiwn(vector <ship*> ploia);