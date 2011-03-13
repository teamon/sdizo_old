#include <iostream>
#include "Kruskal.h"
#include <list>

#include "../Edge.h"

using namespace std;
// using namespace kruskal;

void KruskalMatrix(GMatrix &matrix){
	int ** tab = matrix.getTab();
	int N = matrix.getN();
    list<Edge> * glist = new list<Edge>[n];
	for(int i=0; i<N; i++){
		for(int j=i+1; j < N; j++){
			if(tab[i][j] != 0){
				glit[i].push_back(Edge(j,tab[i][j]));
				glit[j].push_back(Edge(i,tab[i][j]));
			}
		}
	}
}

void KruskalList(GList &list){
    
}
