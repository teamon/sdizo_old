#include <iostream>
#include "Prim.h"

using namespace std;
using namespace prim;

void PrimMatrix(GMatrix &matrix){
    cout << "PrimMatrix" << endl;
    
    int N = matrix.getN();
    Node * nodes = new Node[N];
	
	int ** tab = matrix.getTab();
	int node = 0;
    
    for(int i = 0; i < N; i++){
		if(tab[node][i] > 0){
			nodes[i].weight = tab[node][i];
			nodes[i].parent = 0; 
		}
    }
}

void PrimList(GList &list){

}

void printNodes(Node * nodes, int N){
	for(int i=0; i<N; i++)
		cout << "[" << i << "] : p = " << nodes[i].parent << " w = " << nodes[i].weight << endl;
}
