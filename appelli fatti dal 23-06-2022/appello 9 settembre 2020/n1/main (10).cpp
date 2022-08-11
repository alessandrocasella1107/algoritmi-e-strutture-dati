#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;
void esercizio1(const Grafo& g);

int main()
{
    Grafo g(5);
	g(0,1, true); g(0,4, true); g(1,4,true); g(2,3,true); g(3,1, true); 
	
	esercizio1(g);
    return 0;
}


void esercizio1(const Grafo& g){
    int nodo_raggiungibile=0;
    int somma=4;
    int somma_def=0;
    vector<int> nodi={0,1,2,3,4};
    while (nodo_raggiungibile<g.n()){
        
        for(int i=0;i<g.n();i++){
            if(g(i, nodo_raggiungibile)){
                somma--;
                for(int j=0;j<g.n();j++){
                    if(g(j,i)){
                        somma--;
                    }
                }
            }
        }
        
        
        cout<<nodo_raggiungibile<<" "<<somma<<endl;
        nodo_raggiungibile++;
        somma=4;
        
    }
    
}