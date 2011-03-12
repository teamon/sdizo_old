#include <iostream>
#include "Prim.h"

using namespace std;
using namespace prim;

void PrimMatrix(GMatrix &matrix){
	int N = matrix.getN();
    Node * nodes = new Node[N];
    
    bool set[N];
    for(int i = 0; i < N; i++)
		set[i] = false;
		
	int ** tab = matrix.getTab();
	int node = 0, min = 0, min_w =  INT_MAX;
    nodes[0].weight = 0;
    
    while(!set[node]){
		
		min_w =  INT_MAX;
		set[node] = true;
		
		for(int i = 0; i< N; i++){
			if((nodes[node].parent != i) && (tab[node][i] > 0)){
				if(nodes[i].weight > tab[node][i]){
					nodes[i].weight = tab[node][i];
					nodes[i].parent = node;
				}
				if(!set[i] && (tab[node][i] < min_w) ){
					min = i;
					min_w = tab[node][i];
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


