#include <iostream>
#include <vector>

using namespace std;

struct Soluzione{
    vector<string>V;
    vector<vector<string>>T;
    int k1;
    int k2;
    
    vector<string>sol;
    
    Soluzione(vector<string>V, vector<vector<string>>, int k1, int k2): V(V), T(T), k1(k1), k2(k2){};
};

bool siPuoInserire(string& v1, string&v2, const Soluzione& s);
bool solve(Soluzione&s); 
bool canAdd(int x, const Soluzione& s); 
bool isComplete(Soluzione&s);
void add(Soluzione & s, int x); 
void remove(Soluzione & s);


int main(){
    vector<string> V={"a","b","c","d","e","f","g","h"};
    vector<vector<string>> T={{"a","b","f","c"},{"b","h","d"},{"b","a","c"},{"d","h"},{"e","f","g","h"}};
    int k1=2;
    int k2=5;
    Soluzione s(V,T,k1,k2);
    
    if(solve(s))
        cout<<"ok"<<endl;
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
        string v1,v2;
        v1=s.sol[0];
        v2=s.V[x];
        if(v1==v2){
            return false;
        }
        
        if(!(siPuoInserire(v1,v2,s))) return false;
        else if(s.sol.size()==2){
            v1=s.sol[1];
            if(!(siPuoInserire(v1,v2,s))) return false;
        }
        else return true;
    }
}

bool siPuoInserire(string& v1, string&v2, const Soluzione& s){
    int cont=0;
    
    for(int i=0;i<s.T.size();i++){
        for(int j=0;j<s.T[i].size();j++){
            if(v1==s.T[i][j]||v2==s.T[i][j]){
                cont++;
                if(cont==2){
                    return false;
                }
            }
        }
        cont=0;
    }
    
    return true;
    
}

bool isComplete(Soluzione & s){
    if(s.sol.size()>=s.k1&& s.sol.size()<=s.k2){
        for(int i = 0; i < s.sol.size(); i++){
            for( int j = 0; j < s.sol[i].size(); j++){
                cout << s.sol[i][j] << " ";
            } cout << endl;
        }
        return true;}
    return false;
}















