#include <iostream>
#include "Grafo.h"

using namespace std;

int nodo_non_raggiunto(const Grafo& g);




int main(){
    Grafo g(5);
    
    
    g(0,1,true), g(0,4,true), g(2,3,true), g(3,1,true);
    
    cout<<nodo_non_raggiunto(g)<<endl;
    //nodo_non_raggiunto(g);
}

int nodo_non_raggiunto(const Grafo& g){
    
    int nodo=0;
    int somma=g.n()-1;
    int somma_temp=g.n()-1;
    
    
    for(int i=0;i<g.n();i++){
        for(int j=0;j<g.n();j++){
            if(g(j,i)){
                somma_temp--;
                for(int l=0;l<g.n();l++){
                    if(g(l,j)){
                        somma_temp--;
                    }
                }
            }
        }
        if(somma_temp>somma){
            somma=somma_temp;
            nodo=i;
        }
        cout<<i<<" "<<somma_temp<<endl;
        somma_temp=4;
    }
    
    return nodo;
    
}