#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Soluzione{
    
    vector<vector<string>> S;
    vector<string> U;
    int k;
    
    vector<int> sol;
    
    Soluzione(vector<vector<string>> S, vector<string> U, int k): S(S), U(U), k(k) {}
};

bool solve(Soluzione&s); 
bool canAdd(int x, const Soluzione& s); 
bool isComplete(Soluzione&s);
void add(Soluzione & s, int x); 
void remove(Soluzione & s);


bool solve(Soluzione& s){
    int x=0;
    while(x<s.S.size()){
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


void add(Soluzione& s,int x){
    s.sol.push_back(x);
}
void remove(Soluzione& s){
    s.sol.pop_back();
}

bool canAdd(int x, const Soluzione& s){
    if(s.sol.size()==0) return true;
    if(s.sol.size()==s.k) return false;
    
    if(x <= s.sol.back()) return false;
	else return true;
    
}

bool isComplete(Soluzione& s) {
	for(int i = 0; i < s.U.size(); i++) {
		int trovato = false;
		for(int j = 0; j < s.sol.size() && !trovato; j++) {
			vector<string>& sub = s.S[s.sol[j]];

			for(int k = 0; k < sub.size() && !trovato; k++) {
				if(s.U[k] == sub[k])
					trovato = true;
					
			}

		}
		if(!trovato)
			return false;
	}

	return true;
}


int main(){
    vector<string> U={"a","b","xq","e","f"};
    vector<vector<string>> S={{"xq", "e", "f" },{"b", "e", "f"},{"a","b"},{"xq","f"},{"a", "xq", "e" } };
    int k=3;
    Soluzione s(S,U,k);
    if(solve(s)){
        cout<<"ok"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}



