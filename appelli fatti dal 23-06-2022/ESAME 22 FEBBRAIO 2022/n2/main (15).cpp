
#include<iostream>
#include <list>
#include <algorithm>
using namespace std;







class FakeList: private list<int>{
    
    public:
        list<int>lista={1,2,3,4,5,4};
        int getFakeSize(){
            return lista.size()*2;
        }
        
        void insert(int el){
            
            if(find(lista.begin(), lista.end(), el)==lista.end()){
                lista.push_front(el);
                return;
            }
            else{
                lista.push_back(el);
            }
            
        }
        
        void fakeSort(bool s){
            list<int> contrario;
            int i=0;
            int n=lista.size();
            if(s){
                lista.sort();
            }
            else{
                lista.sort();
                while(i<n){
                    contrario.push_back(lista.back());
                    lista.pop_back();
                    i++;
                }
                lista=contrario;
            }
            
        }
        
        
        
        
        void fakeClear(bool c){
            /*if(c){
                lista.clear();
            }*/
            lista.clear();
        }
        
        void print(){
            for (list<int>::iterator i = lista.begin(); i != lista.end(); i++) {
                cout << *i << " ";
            }
            cout << endl;
        }

};








int main(){
    
    FakeList g;
    bool c=true;
    bool s=false;
    int el=1;
    g.getFakeSize();
    cout<<g.getFakeSize()<<endl;
    //g.fakeClear(c);
    //cout<<g.getFakeSize();
    g.print();
    g.fakeSort(s);
    //g.insert(el);
    g.print();
}



