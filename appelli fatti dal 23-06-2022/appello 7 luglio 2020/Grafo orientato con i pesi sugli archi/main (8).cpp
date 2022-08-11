

#include <iostream>
#include <vector>
#include <list>
#include "grafoPesato.h"
using namespace std;

bool adiacenti_minori(const GrafoPesato&g);


int main()
{
    GrafoPesato g(5);
	g(0,1, true,2); g(0,2, true,4); g(0,3,true,8); g(1,4,true,6); g(3,4, true, 5); g(4,2,true, 4);
	if(adiacenti_minori(g)){
	    cout<<"ok"<<endl;
	}
	else{
	    cout<<"no"<<endl;
	}
	//adiacenti_minori(g);
    return 0;
}


bool adiacenti_minori(const GrafoPesato&g){
    int i=0;
    bool cond=true;
    int cont=0;
    int cont2=0;
    vector<int>adiacenti;
    
    while(i<g.n()){
        //cout<<"entra nodo "<<i<<endl;
        for(int j=0; j<g.n(); j++){
            if(g(i,j)){
                cont+=g.w(i,j);
                adiacenti.push_back(j);
                //cout<<j<<endl;
            }
        }
        
        //cout<<"nodo "<<i<<"ha "<<cont<<endl;
        
        for(int l=0;l<adiacenti.size();l++){
            
            int k=adiacenti[l];
            //cout<<" il k è "<<k<<endl;
            
            for(int j=0; j<g.n(); j++){
                if(g(k,j)){
                    cont2+=g.w(k,j);
                }
            }
            
            if(cont2>cont){
                cond=false;
            }
            
            //cout<<"nodo adiacente "<<k<<"ha "<<cont2<<endl;
            
            cont2=0;
        }
        
        //cout<<"finito"<<endl;
        i++;
        cont=0;
        adiacenti.clear();
    }
    
   // return cond;
}