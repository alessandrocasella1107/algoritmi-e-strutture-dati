#include "AlberoB.h"
#include <iostream>

using namespace std;
void dfs(const AlberoB<int>& a,int& x, int& y, int& livello_x, int& livello_y);
bool related_nodes(AlberoB<int>& a, int& x, int& y);
int main(){



	AlberoB<int> a(-4);

	AlberoB<int> b(-8);
	AlberoB<int> c(42);
	a.insFiglio(SIN,b);
	a.insFiglio(DES,c);


	AlberoB<int> d(10);
	AlberoB<int> e(16);
	b.insFiglio(SIN,d);
	b.insFiglio(DES,e);//

	AlberoB<int> f(23);
	AlberoB<int> g(11);
	c.insFiglio(SIN,f);
	c.insFiglio(DES,g);


	AlberoB<int> h(81);
	d.insFiglio(SIN,h);
	
	
	int x=10;
	int y=11;

	if(related_nodes(a,x,y)){
	    cout<<"ok"<<endl;
	}
	else{
	    cout<<"no"<<endl;
	}
	

	
}

void dfs(const AlberoB<int>& a,int& x, int& y, int& livello_x, int& livello_y){

    if(!a.figlio(SIN).nullo()){
        if(a.figlio(SIN).radice()==x||a.figlio(SIN).radice()==y){
            livello_y=a.padre().radice();
        }
        else{
            dfs(a.figlio(SIN),x,y,livello_x,livello_y);
        }
    } 
    
    if(!a.figlio(DES).nullo()){
        if(a.figlio(DES).radice()==x||a.figlio(DES).radice()==y){
            livello_x=a.padre().radice();
        }
        else{
            dfs(a.figlio(DES),x,y,livello_x,livello_y);
        }
    }
    
    
    
    
    
    
    
}


bool related_nodes(AlberoB<int>& a, int& x, int& y){
    int livello_x=0;
    int livello_y=0;
    

    dfs(a,x,y,livello_x,livello_y);
    

    if (livello_y==livello_x){
        return true;
    }
    else{
        return false;
    }
}





