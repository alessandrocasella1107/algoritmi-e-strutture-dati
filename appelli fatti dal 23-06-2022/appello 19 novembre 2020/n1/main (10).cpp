#include <iostream>
#include "GrafoNonOrientato.h"
#include <vector>
using namespace std;

void potenziale(const GrafoNonOrientato& g, vector<int>& pot);

int main(){
    GrafoNonOrientato g(5);
    
    
    g(1,2, true); g(0,2, true); g(0,4,true); g(0,3,true);
    
    vector<int>pot={5,3,6,1,2};
    
    potenziale(g, pot);
}


void potenziale(const GrafoNonOrientato& g, vector<int>& pot){
    
    vector<int>adiacenti;
    vector<int>stato;
    
    int i=0;
    int cont=0;
    int indice;
    int pot_maggiore=0, pot_attuale=0, nodo=0;;
    
    while(i<g.n()){
        for(int j=0; j<g.n(); j++){
            if(g(i,j)){
                adiacenti.push_back(j);
            }
        }
        /*for(int j=0;j<adiacenti.size();j++){
            cout<<"elementi lista "<<i<<" "<<adiacenti[j]<<endl;
        }*/
        
        
        for(int j=0;j<adiacenti.size();j++){
            indice=adiacenti[j];
            //cout<<"pot "<<pot[indice]<<endl;
            cont+=pot[indice];
        }
        
        if(pot[i]>(cont/adiacenti.size())){
            stato.push_back(1);
        }
        else{
            stato.push_back(0);
        }
        
        
        cont=0;
        adiacenti.clear();
        
        i++;
    }
    
    
    for(int j=0;j<stato.size();j++){
        if(stato[j]==1){
            pot_attuale=pot[j];
        }
        if(pot_attuale>pot_maggiore){
            pot_maggiore=pot_attuale;
            nodo=j;
        }
        
    }
    

    
    
    
    
    cout<<"nodo: "<<nodo<<" , potenziale: "<<pot_maggiore<<endl;
}