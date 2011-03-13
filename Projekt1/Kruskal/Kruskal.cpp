#include <iostream>
#include "Kruskal.h"
#include <list>
#include <algorithm>

#include "../Edge.h"
#include "UnionFind.h"

using namespace std;
// using namespace kruskal;

void KruskalMatrix(GMatrix &matrix){
	int ** tab = matrix.getTab();
	int N = matrix.getN();
    list<Edge> * glist = new list<Edge>[N];
	for(int i=0; i<N; i++){
		for(int j=i+1; j < N; j++){
			if(tab[i][j] != 0){
				glist[i].push_back(Edge(j,tab[i][j]));
				glist[j].push_back(Edge(i,tab[i][j]));
			}
		}
	}
}

bool cmp(const KEdge &a, const KEdge &b){
    return a.weight < b.weight;
}

void KruskalList(GList &glist){
    int N = glist.getN();
    int P = glist.getP();
    UnionFind uf = UnionFind(N);
    KEdge edges[P];
    
    list<Edge> * tab = glist.getTab();
    
    int k=0;
    for(int i=0; i<N; i++){
        for(list<Edge>::iterator it = tab[i].begin(); it != tab[i].end(); it++){
            edges[k].a = i;
            edges[k].b = it->peak;
            edges[k].weight = it->weight;
            k++;
        }
    }
    
    sort(edges, edges+P, cmp);
    
    for(int i=0; i<P; i++){
        cout << i << ": " << edges[i].a << " " << edges[i].b << "  " << edges[i].weight << endl;
    }
    
}
