#include <iostream>
#include "Grafo.h"
#include <vector>
using namespace std;
bool sottoinsieme(const Grafo& g, int& k,int& s );
int main(){

	Grafo g(4);
	g(1,0, true); g(1,3, true); g(2,3,true); g(2,0,true);//g(2,1,true); stampa no
	int k=2;
	int s=4;
	
	if(sottoinsieme(g,k,s)){
	    cout<<"okkk"<<endl;
	}
	else{
	    cout<<"no"<<endl;
	}
	//sottoinsieme(g,k,s);
	
	return 0;
}

bool sottoinsieme(const Grafo& g, int& k,int& s ){
    int i=0;
    vector<int> U;
    
    
    while(i<g.n()){
        for(int j=0; j<g.n();j++){
            if(g(i,j)){
                U.push_back(i);
                break;
            }
        }
        i++;
    }
    
    //cout<<U.size()<<endl;
    
    /*for(int l=0;l<U.size();l++){
        cout<<U[l]<<endl;
        
    } stampa */
    
    if(U.size()>k){
        return false;
    }
    
    
    for(int l=0; l<U.size();l++){
        for(int j=0; j<g.n();j++){
            if(g(j,U[l])){
                //cout<<j<<" "<<U[l]<<endl;
                return false;
            }
        }
    }
    
    
    int cont=0;
    for(int l=0; l<U.size();l++){
        cont+=U[l];
    }
    if(cont==s){
        return false;
    }
    
    return true;
    
}