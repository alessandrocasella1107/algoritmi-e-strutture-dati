#include <iostream>
#include "grafoPesato.h"
#include <vector>

using namespace std;
void cond(const GrafoPesato& g);

int main(){
	GrafoPesato g(4);
	g(0,1, true,2); g(1,2, true,3); g(2,1,true,2); g(1,3,true,1); g(2,3,true,2);
	
	cond(g);
}


void cond(const GrafoPesato& g){
    
    bool cond=true;
    vector<int>dep={6,6,6,4};
    int archi_entranti=0;
    int i=0;
    
    while(i<g.n()){
        for(int j=0;j<g.n();j++){
            if(g(j,i)){
                archi_entranti+=g.w(j,i);
                
                if(dep[j]<dep[i]){
                    cond=false;
                }
            }
        }
        
        cout<<"archi entranti: "<<archi_entranti<<" deposito nodo "<<dep[i]<<endl;
        if(archi_entranti>=dep[i]){
            cond=false;
        }
        
        
        archi_entranti=0;
        i++;
        
    }
    
    if(cond){
        cout<<"ok"<<endl;
    }
    else cout<<"no"<<endl;
    
    
}















    
    