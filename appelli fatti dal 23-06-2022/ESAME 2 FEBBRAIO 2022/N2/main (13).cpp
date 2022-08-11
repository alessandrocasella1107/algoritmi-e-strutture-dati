#include "GestoreValori.h"

#include <iostream>

using namespace std;


int main()
{
    
    GestoreValori * g=new GestoreValoriA({},{});
    GestoreValori * b=new GestoreValoriB({},{});
    
    /*g->inserisciCoppia();
    g->inserisciCoppia();
    g->numCoppie();
    g->cerca();*/
    
    
    b->inserisciCoppia();
    b->inserisciCoppia();
    b->numCoppie();
    b->cerca();
    
    return 0;
}



