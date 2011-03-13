#include <iostream>
#include <list>
#include <string.h>
#include "Prim/Prim.h"
#include "Kruskal/Kruskal.h"


using namespace std;

int main (int argc, char const *argv[]){
    cout << "Projekt 1" << endl;
    
    string s = string(argv[1]);
        
    if(s == "kmatrix"){
		GMatrix matrix = GMatrix(argv[2]);
		KruskalMatrix(matrix);
	} else if(s == "pmatrix"){
    	GMatrix matrix = GMatrix(argv[2]);
		PrimMatrix(matrix);
	} else if(s == "klist"){
	    GList glist = GList(argv[2], true);
		KruskalList(glist);
    } else if(s == "plist"){
        GList glist = GList(argv[2], false);
        PrimList(glist);
	}
    return 0;
}
