#include <iostream>
#include <vector>
using namespace std;

struct Soluzione{
    vector<vector<int>> V;
    int k;
    
    vector<vector<int>> sol;
    
    Soluzione(vector<vector<int>> V, int k): V(V), k(k){}
};

bool solve(Soluzione&s); 
bool canAdd(int x, const Soluzione& s); 
bool isComplete(Soluzione&s);
void add(Soluzione & s, int x); 
void remove(Soluzione & s);
bool siPuoInserire(vector<int>& v1, vector<int>& v2);


int main(){
    vector<vector<int>> V={{42,3,1,5}, {8,26,3,5},{2,8,21,83},{7,21,83,5},{22,23,24,42}};
    int k=3;
    
    Soluzione s(V,k);
    
    if(solve(s))
        cout<<"0k"<<endl;
    else
        cout<<"no"<<endl;
}

bool solve(Soluzione& s){
    int x=0;
    while(x<s.V.size()){
        if(canAdd(x,s)){
            add(s,x);
            if(isComplete(s)){
                return true;
            }
            else if(solve(s)) return true;
            
            remove(s);
            x++;
        }
        else
            x++;
    }
    return false;
}

void remove(Soluzione& s){
    s.sol.pop_back();
}

void add(Soluzione& s, int x){
    s.sol.push_back(s.V[x]);
}

bool canAdd(int x, const Soluzione& s){
    if(s.sol.size()==0) return true;
    else{
        vector<int> v1,v2,v3;
        v1=s.sol[0];
        v2=s.V[x];
        
        if(!(siPuoInserire(v1,v2))) return false;
        else if(s.sol.size()==2){
            v1=s.sol[1];
            if(!(siPuoInserire(v1,v2))) return false;
        }
        else return true;
    }
}


bool siPuoInserire(vector<int>& v1, vector<int>& v2){
    int cont=0;
    for(int k=0; k<v1.size();k++){
        for(int j=0; j<v2.size(); j++){
            if(v1[k]==v2[j]){
                cont++;
                if(cont>1){
                    return false;
                }
            }
        }
    }
    return true;
}

bool isComplete(Soluzione & s){
    if(s.sol.size()==s.k){
        for(int i = 0; i < s.sol.size(); i++){
            for( int j = 0; j < s.sol[i].size(); j++){
                cout << s.sol[i][j] << " ";
            } cout << endl;
        }
        return true;}
    return false;
}














