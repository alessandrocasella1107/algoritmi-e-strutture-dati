#include <iostream>
#include "grafoPesato.h"

using namespace std;

bool es1(const GrafoPesato& g);

int main(){

	GrafoPesato g(5);
	g(0,1, true,2); g(0,2, true,4); g(0,3, true,8); g(1,4, true,6); g(3,4, true,5); g(4,2, true,4);
	
	if(es1(g)){
	    cout<<"ok"<<endl;
	}
	else{
	    cout<<"no"<<endl;
	}
	 
}

bool es1(const GrafoPesato& g){
    
    int somma_uscenti=0;
    int somma_uscenti_adicenti=0;
    vector<int> adiacenti;
    
    for(int i=0;i<g.n();i++){
        //cout<<"nodo: "<<i<<endl;
        for(int j=0;j<g.n();j++){
            if(g(i,j)){
                somma_uscenti+=g.w(i,j);
                //cout<<j<<endl;
                adiacenti.push_back(j);
            }
        }
            
        for(int x=0; x<adiacenti.size();x++){
            for(int y=0; y<g.n(); y++){
                if(g(adiacenti[x],y)){
                    somma_uscenti_adicenti+=g.w(adiacenti[x],y);
                }
            }
            //cout<<somma_uscenti_adicenti<<" "<<somma_uscenti<<endl;
            if(somma_uscenti_adicenti>somma_uscenti){
                return false;
            }
            somma_uscenti_adicenti=0;
        }
        somma_uscenti=0;
        adiacenti.clear();
    }
    
    return true;
    
}