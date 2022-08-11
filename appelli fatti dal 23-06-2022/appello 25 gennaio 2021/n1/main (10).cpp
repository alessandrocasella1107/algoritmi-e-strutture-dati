#include "AlberoB.h"
#include <iostream>
#include <vector>
using namespace std;
void esercizio1(AlberoB<int>& a, int x);
bool dfs(AlberoB<int>& a, int x, vector<int>& percorso);
int main(){



	AlberoB<int> a(5);
	
	AlberoB<int> b(6);
	AlberoB<int> c(12);
	a.insFiglio(SIN,b);
	a.insFiglio(DES,c);


	AlberoB<int> d(10);
	b.insFiglio(SIN,d);
	

	AlberoB<int> f(42);
	AlberoB<int> g(32);
	c.insFiglio(SIN,f);
	c.insFiglio(DES,g);
	
	int x=42;
	//vector<int> nodofoglia=nodo_foglia(a,x);
	esercizio1(a, x);

	
	
}



bool dfs(AlberoB<int>& a, int x, vector<int>& percorso) {
	if(a.nullo())
		return false;
	percorso.push_back(a.radice());
	if(a.foglia() && a.radice() == x)
		return true;
	else if(dfs(a.figlio(SIN), x, percorso) || dfs(a.figlio(DES), x, percorso))
		return true;
	else {
		percorso.pop_back();
		return false;
	}
}

void esercizio1(AlberoB<int>& a, int x) {
	vector<int> percorso;

	if(dfs(a, x, percorso)) {
		cout << percorso[0];
		for(int i = 1; i < percorso.size(); i++) {
			cout << " -> " << percorso[i];
		}
		cout << endl;
	}
	else
		cout << "-1" << endl;

}



















    
    