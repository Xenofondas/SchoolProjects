#pragma once
class map
{
public:
	map(void);
	~map(void);
	
	
	void setEntasi();
	void setLimani();
	void setTreasure();
	bool getTreasure() const;
	static int doSomething();
	//static int table[100][100];
	int getCurrentEntasi() const;
	bool getLimani() const;
	void setNewEntasi(int);
	
private:
   
	int entasi; //timh apo 1-10 pou deixnei thn entash toy keroy
	bool limani;  //deixnei an yparxei limani
	bool treasure; //deixnei an yparxei thisauros
	int i;
		 
};


