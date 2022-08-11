
#ifndef GESTOREVALORI_H
#define GESTOREVALORI_H

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class GestoreValori{

    protected:
        int a;
        char b;
        vector<int>intero;
        vector<char>carattere;
    
    public:
       GestoreValori(vector<int>intero, vector<char>carattere): intero(intero), carattere(carattere) {};
        
        
    void inserisciCoppia(){
        cin>>a;
        cin>>b;
        
        intero.push_back(a);
        carattere.push_back(b);
    }
    
    void numCoppie(){
        cout<<intero.size()<<endl;
    }
    
    virtual void getRisultato(){
        cout<<-1<<endl;
    }
        
    
    
};



/*class GestoreValoriA: public GestoreValori{
    public:
        GestoreValoriA(vector<int>intero, vector<char>carattere): GestoreValori(intero,carattere){};
        int accopiati_ad_a(){
            int cont=0;
            for(int i=0;i<carattere.size();i++){
                if(carattere[i]=='a'){
                    cont+=intero[i];
                }
            }
            return cont;
        };
};*/



class GestoreValoriB: public GestoreValori{
    public:
        GestoreValoriB(vector<int>intero, vector<char>carattere): GestoreValori(intero,carattere){};
        /*int accopiati_ad_a(){
            int cont=0;
            int n=0;
            for(int i=0;i<carattere.size();i++){
                if(carattere[i]=='b'){
                    cont+=intero[i];
                    n++;
                }
            }
            return cont/n;
        }*/
        
        void getRisultato(){
            int cont=0;
            int n=0;
            for(int i=0;i<carattere.size();i++){
                if(carattere[i]=='b'){
                    cont+=intero[i];
                    n++;
                }
            }
            cout<<cont/n<<endl;
        }
        
};







#endif