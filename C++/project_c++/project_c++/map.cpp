#include "map.h"
#include <iostream>
#include <cstdlib>
using namespace::std;

map::map(void)
{
	
	treasure=0;
	limani=0;

}


map::~map(void)
{

}


int map::doSomething(){
cout <<endl << "It works!!" <<endl;
return 0;
};


int map::getCurrentEntasi() const
{
	return entasi;
}

void map::setEntasi()
{
	entasi=rand()%11;
}

void map::setLimani()
{
	limani=1;
}

void map::setTreasure()
{
	treasure=1;
}

bool map::getLimani() const
{

	return limani;

}

bool map::getTreasure() const
{
	return treasure;
}

void map::setNewEntasi(int e)
{
	entasi=e;
}