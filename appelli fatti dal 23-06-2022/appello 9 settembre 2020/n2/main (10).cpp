#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool esercizio2(vector<string>& S, vector<int>& Val){
    vector<bool> chosen(S.size(), false);
    int val=0;
    int totale=0;
    for(int i=0;i<S.size();i++){
        totale+=Val[i];
    }
    
    if(totale%2==1){
        return false;
    } //se il totale è dispari non può essere uguale in due insiemi
    
    vector<bool> possibili(totale+1, false);
    possibili[0]=true;
    
    for(int i=0; i<S.size();i++){
        int val= Val[i];
        for(int j=totale; j>=0; j--){
            if(possibili[j]){
                possibili[j+val]=true;
                if (possibili[totale/2])
                    return true;
            }
        }
        
    }
    return false;
    
}


int main(){
    vector<string> S={"ab","cd1","xyz","q","q42","8a8b","ccc"};
    vector<int> Val={11,11,12,8,7,34,23};
    
    if(esercizio2(S, Val)){
        cout<<"ok"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    
}