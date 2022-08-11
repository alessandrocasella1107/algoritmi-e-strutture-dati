#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool es2(vector<string>S,vector<int>Val){
    vector <bool> scelta(S.size(), false);
    int val=0;
    int totale=0;
    
    for(int i=0; i<S.size();i++){
        totale+=Val[i];
    }
    if(totale%2==1){
        return false;
    }
    
    vector<bool> possibili(totale+1, false);
    possibili[0]=true;
    
    for(int i=0; i<S.size(); i++){
        int val=Val[i];
        cout<<"val "<<val<<endl;
        for(int j=totale; j>=0; j--){
            if(possibili[j]){
                possibili[j+val]=true;
                cout<<j+val<<endl;
                if(possibili[totale/2]){
                    return true;
                }
            }
        }
    }
     return false;
}



int main(){
    
    vector<string> S={"ab", "cde", "xyz", "q", "q42", "8a8b", "ccc"};
    
    vector<int> Val={11,11,12,8,7,34,23};
    
    if(es2(S,Val)){
        cout<<"ok"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    
}