#include <iostream>
#include <list>

#include "Prim/Prim.h"


using namespace std;

int main (int argc, char const *argv[]){
    cout << "Projekt 1" << endl;
    
    GList glist = GList(argv[1]);
    
    list<Edge > * tab = glist.getTab();
    
    int n = glist.getN();
    
    for(int i =0 ; i<n; i++){
		for(list<Edge>::iterator it = tab[i].begin(); it != tab[i].end(); it++){
			cout << i << " " <<it->peak << " " << it->weight <<endl; 
		}
	}
    

    return 0;
}
