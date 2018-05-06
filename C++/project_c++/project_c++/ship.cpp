#include "ship.h"
#include "pirates.h"
#include <vector>



ship::ship(int e,int m_a,int stuck_tr)
	:eidos(e),max_antoxi(m_a),stuck_treasure(stuck_tr)
{
	setTrex_antoxi(m_a); //Arxikopoioume thn trexousa antoxh tou kathe ploiou
	p_k=0;
	set_plkin(0);
	setS_z(0);
}


ship::~ship(void)
{
}



void ship::movement()        //H methodos metakinishs
{
	
	
}

void ship::leitourgia(int,map table[100][100],vector <ship*> ploia) //H methodos leitourgias
{
}


int ship::getX_pos() const
{
	return x_pos;


}

int ship::getY_pos() const
{
	return y_pos;
}

void ship::getCoordinates()
{
	

}

void ship::setCoordinates()
{
	x_pos=rand()%100; 
	y_pos=rand()%100;


}

void ship::setNewCoordinates(int x,int y)
{
	x_pos=x;
	y_pos=y;
	//cout<<endl<<x_pos;
	//cout<<endl<<y_pos;

}

int ship::geteidos() const
{
	return eidos;
}

int ship::getMaxAtoxi() const //epistrefei thn megisth antoxh
{
	return max_antoxi;
}

void ship::setTrex_antoxi(int x)
{
	trex_antoxi=x;
	

}

int ship::getTrex_antoxi() const //epistrefei thn trecousa antoxh tou ploiou
{
	return trex_antoxi;
}

void ship::printObj(ship *a)
{
	cout <<a->eidos;

}

void ship::setStuckTr(int x) 
{
	stuck_treasure=x;

}

int ship::getStuckTr()  const //epistreuei to apothema thisaurou tou ploiou
{
	return stuck_treasure;
}

void ship::setX_pos(int x)
{
	x_pos=x;
}

void ship::setY_pos(int y)
{
	y_pos=y;
}

void ship::operator--() //Meiwsh tou trexontos thisaurou kata 5 monades
{
	this->trex_antoxi=this->trex_antoxi- 4;
}

void ship::operator++() //Auxisi tou trexontos thisaurou kata 5 monades
{
	this->stuck_treasure=this->stuck_treasure + 5;
}

void ship::set_aa(int k)
{
	a_a=k;
}

int ship::get_aa() const
{
	return a_a;
}

void ship::set_plkin(int k)
{
	pl_kin=k;
}

int ship::get_plkin() const
{
	return pl_kin;
}

void ship::inc_plkin(int x)
{
	pl_kin+=x;
}

void ship::setS_z(int z)
{
	s_z=z;
}

int ship::getS_z() const 
{
	return s_z;
}

void ship::count_damage(int c)
{
	s_z+=c;
}

 ostream &operator<<(ostream &out,ship* pl) 
{
	out<<"To apothema thisaurou tou einai: "<<pl->getStuckTr()<<"\nH trexousa antoxi tou einai:"
		<< pl->getTrex_antoxi()<<"\nExei kinithei kata:"<< pl->get_plkin()<<" theseis"<<endl;
	return out;
 }

int ship::pl_epith=0;

void ship::inc_plEp(int ep)
{
	pl_epith+=ep;
}

int ship::get_plEp()
{
	return pl_epith;
}