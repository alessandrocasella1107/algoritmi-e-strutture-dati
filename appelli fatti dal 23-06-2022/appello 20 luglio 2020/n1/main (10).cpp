#include<iostream>

using namespace std;

#include "AlberoB.h"
bool nodi_liberi(const AlberoB<int>&a);


int main(){

    AlberoB<int> a(4);

    AlberoB<int> b(3);
    AlberoB<int> c(2);
    a.insFiglio(SIN, b);
    a.insFiglio(DES, c);

    AlberoB<int> d(6);
    b.insFiglio(SIN, d);


    AlberoB<int> e(8);
    AlberoB<int> f(1);
    c.insFiglio(SIN, e);
    c.insFiglio(DES, f);
    
    AlberoB<int> g(4);
    AlberoB<int> h(4);
    e.insFiglio(SIN, g);
    e.insFiglio(DES, h);
    
    if(nodi_liberi){
        cout<<"ok"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    
}

void dfs(const AlberoB<int>& a, int& somma_lib, int& somma_vin, bool sempre_sin, bool sempre_des) {
	if(sempre_sin || sempre_des) somma_lib += a.radice();
	else somma_vin += a.radice();


	if(!a.figlio(SIN).nullo()) {
		dfs(a.figlio(SIN), somma_lib, somma_vin, sempre_sin, false);
	}
	if(!a.figlio(DES).nullo()) {
		dfs(a.figlio(DES), somma_lib, somma_vin, false, sempre_des);
	}
}

bool nodi_liberi(const AlberoB<int>& a) {
	int somma_lib = 0;
	int somma_vin = 0;

	dfs(a, somma_lib, somma_vin, true, true);

	if (somma_lib == somma_vin)
	   return true;
}