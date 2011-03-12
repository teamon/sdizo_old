#include <iostream>

#include "Prim/Prim.h"

using namespace std;

int main (int argc, char const *argv[]){
    cout << "Projekt 1" << endl;
    
    GMatrix matrix = GMatrix(argv[1]);
    
    PrimMatrix(matrix);

    return 0;
}
