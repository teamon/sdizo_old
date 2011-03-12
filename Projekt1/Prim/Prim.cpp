#include <iostream>
#include "Prim.h"

using namespace std;
using namespace prim;

void PrimMatrix(GMatrix &matrix){
    cout << "PrimMatrix" << endl;
    
    int N = matrix.getN();
    Node * nodes = new Node[N];
    bool set[N];
    
    for(int i = 0; i < N; i++)
		set[i] = false;
	
	int ** tab = matrix.getTab();
	int node = 0, min = 0, min_w;
    
    while(!set[node]){
		set[node] = true;
		min_w = INT_MAX;
		for(int i = 0; i < N; i++){
			if((tab[node][i] > 0) && (nodes[i].weight > nodes[node].weight)){
				nodes[i].weight = tab[node][i];
				nodes[i].parent = node;
				if( !set[i] && (nodes[i].weight < min_w) ){
					min = i;
					min_w = nodes[i].weight;
				} 
			}
		}
		node = min;
	}
    printNodes(nodes,N);
}

void PrimList(GList &list){

}

void printNodes(Node * nodes, int N){
	for(int i=0; i<N; i++)
		cout << "[" << i << "] : p = " << nodes[i].parent << " w = " << nodes[i].weight << endl;
}
