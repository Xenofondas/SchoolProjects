#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <windows.h>
#include <stddef.h>

using namespace std;

class Systhma {
public:
   int ID;//ksexoristo ID gia kathe eidos antikeimenou
   int age;
   int On_Fire;

Systhma();
~Systhma();};

Systhma :: Systhma()
{
   ID=0;
}

Systhma :: ~Systhma()
{}

Systhma table[200][200];//to table einai o kosmos ths prosomoiosis
Systhma S;//xrisimopoieitai ws keni thesi ston kosmo



class vehicle : public Systhma {//ta oximata

public:
      int speed;
      int gas_consumption;
      int water_consumption;
      int current_gas;
      int gas_capacity;
      int current_water;
      int water_capacity;
      int withdraw;
      int posx;
      int posy;
      bool damage;
      
      void movement(int,int);
      void firefighting();
       vehicle();
      ~vehicle();

      
};

vehicle::vehicle(){};
vehicle::~vehicle(){};

class aircraft : public vehicle
{};
class helicopter : public aircraft {
      
      public : helicopter ( int, int, int,int ,int );
      
      ~helicopter();
      
      };
      
      helicopter :: helicopter ( int g, int   w,  int a,int x,int y ){
      
      current_gas = g;
      current_water = w;
      age = a;
      ID = 1;
      speed = 25;
      water_consumption = 80;
      gas_consumption = 50;
      gas_capacity = 300;
      water_capacity = 400;
      withdraw = 10;
      damage = 0;
      posx=x;
      posy=y;
      movement(x,y);
      }
      
      helicopter :: ~helicopter () {}
      
      
class airplane : public aircraft {
      
      public : airplane ( int, int, int,int ,int );
      
      ~airplane();
      
      };
      
      airplane :: airplane ( int g, int w,  int a,int x,int y ){
      
      current_gas = g;
      current_water = w;
      age = a;
      ID = 2;
      speed = 40;
      gas_consumption = 160;
      water_consumption = 150;
      gas_capacity = 320;
      water_capacity = 600;
      withdraw = 8;
      damage = 0;
      movement(x,y);
      }
      
      airplane :: ~airplane () {};
      
      
class ground : public vehicle{};

class SUV : public ground {
      
      public :
          SUV ( int, int, int,int ,int );
         ~SUV();
            };
      
      SUV :: SUV ( int g, int w,  int a,int x,int y ){
      current_gas = g;
      current_water = w;
      age = a;
      ID = 3;
      speed = 16;
      water_consumption = 50; 
      gas_consumption = 8;
      gas_capacity = 64;
      water_capacity = 200;
      withdraw = 20;
      damage = 0;
      movement(x,y);
      };
      
      SUV :: ~SUV () {};


class rescue : public ground {
      
      public :
      rescue( int, int, int,int ,int );
      
      ~rescue();
      };
      
      rescue :: rescue ( int g, int w,  int a,int x,int y ){
      
      current_gas = g;
      current_water = w;
      age = a;
      ID = 4;
      speed = 10;
      water_consumption = 50;
      gas_consumption = 10;
      gas_capacity = 100;
      water_capacity = 500;
      withdraw = 20;
      damage = 0;
      movement(x,y);};
      
      rescue :: ~rescue ()
      {};


class ladder : public ground {
      
      public : ladder ( int, int, int,int ,int );
      
      ~ladder();};
      
      
      ladder :: ladder ( int g, int w,  int a,int x,int y ){
      
      current_gas = g;
      current_water = w;
      age = a;
      ID = 5;
      speed = 8;
      water_consumption = 100;
      gas_consumption = 16;
      gas_capacity = 200;
      water_capacity = 1000;
      withdraw = 20;
      damage = 0;
      movement(x,y);}
      
      ladder :: ~ladder (){ };

class base :public Systhma//h basi ton oximatwn
{
      public:
         ~base();
         base();
      };
         base :: base()
         {
            ID=6;
            On_Fire=0;//den kaigetai amesws, alla otan On_fire=3
         };
         base::~base(){};
         base b();


class fire : public Systhma//h fotia
{
      public:
            fire();
            ~fire();
};
            fire::fire()
            {
               ID=7;
               age=0;//h fotia den eksaplonetaii me thn proti alla otan age =2
            };
            fire::~fire(){};
            
            fire f();
