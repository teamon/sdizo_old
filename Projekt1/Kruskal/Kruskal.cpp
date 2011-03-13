#include <iostream>
#include "Kruskal.h"
#include <list>
#include <algorithm>

#include "../Edge.h"
#include "UnionFind.h"

using namespace std;
// using namespace kruskal;

void KruskalMatrix(GMatrix &matrix){
	
	
   GList gl = GList(&matrix);
   KruskalList(gl);
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
    
    int total = 0;
    
    for(int i=0; i<P; i++){
        KEdge e = edges[i];
        if(uf.join(e.a, e.b)){
            // cout << "Joined " << e.a << " with " << e.b << endl;
            total += e.weight;
        }
    }
    
    cout << "Total : " << total << endl;
    
}
