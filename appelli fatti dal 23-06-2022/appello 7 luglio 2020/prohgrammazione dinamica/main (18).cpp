#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
struct Soluzione{
    vector<string> U;
    vector<vector<string>> S;
    int k;
    
    vector<vector<string>> sol;
    
    Soluzione(vector<vector<string>> S, vector<string> U, int k ): S(S), U(U), k(k) {}
};

bool solve(Soluzione&s); 
bool canAdd(int x, const Soluzione& s); 
bool isComplete(Soluzione&s);
void add(int x, Soluzione & s); 
void remove(Soluzione & s);

int main(){
    
    vector<string> U={"a","b","xq","e","f"};
    vector<vector<string>> S={{"xq", "f" },{"b", "f"},{"a","b"},{"xq","f"},{"a", "xq" }};
    
    int k=3;
    
    Soluzione s(S,U,k);
    
    if(solve(s)){
        cout<<"ok"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    
}



bool solve(Soluzione& s){
    int x=0;
    while(x<s.S.size()){
       // cout<<" pos "<<x<<endl;
        if(canAdd(x,s)){
            //cout<<"aggiungo "<<x<<endl;
            add(x,s);
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

void add(int x, Soluzione& s){
    s.sol.push_back(s.S[x]);
}

void remove(Soluzione& s){
    s.sol.pop_back();
}


bool canAdd(int x, const Soluzione& s){
    if(s.sol.size()==0) return true;
    else{
        for(int i=0;i<s.sol.size();i++){
            for(int j=0;j<s.sol[i].size();j++){
                for(int l=0; l<s.S[x].size();l++){
                    if(s.S[x][l]==s.sol[i][j])
                        return false;
                }
            }
        }
        return true;
    }
    
}

bool isComplete(Soluzione& s){
    int cont=0;
    
    if(s.sol.size()<=s.k){
        for(int i=0; i<s.U.size();i++){
            for(int j=0;j<s.sol.size();j++){
                for(int l=0; l<s.sol[j].size();l++){
                    if(s.sol[j][j]==s.U[i]){
                        cont+=1;
                    }
                }
            }
        }
        /*for(int i=0;i<s.sol.size();i++){
            for(int j=0; j<s.sol[i].size();j++){
                cout<<s.sol[i][j]<<endl;
            }
        }*/
        //cout<<cont<<endl;
        //cout<<"stop"<<endl;
        
        if(cont==s.U.size()){
            return true;
        }
    }
    
    return false;
}






