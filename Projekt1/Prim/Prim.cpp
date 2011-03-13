#include <iostream>
#include "Prim.h"
#include <set>
#include <stdio.h>

using namespace std;
using namespace prim;

void updateDistances(int target, int ** weight, int * whoTo, int * d, int n) {
	int i;
	for (i = 0; i < n; ++i)
		if ((weight[target][i] != 0) && (d[i] > weight[target][i])) {
			d[i] = weight[target][i];
			whoTo[i] = target;
	}
}

void PrimMatrix(GMatrix &matrix){
	
	int ** weight = matrix.getTab();
	int n = matrix.getN();
	char inTree[100];
	int d[100];
	int whoTo[100];
	
	for (int i = 0; i < n; ++i)
		d[i] = 100000;
	for (int i = 0; i < n; ++i)
		inTree[i] = 0;
	inTree[0] = 1;
	updateDistances(0,weight,whoTo,d,n);
	
	int total = 0;
	int treeSize;
	for (treeSize = 1; treeSize < n; ++treeSize) {
		int min = -1;
		for (int i = 0; i < n; ++i)
			if (!inTree[i])
				if ((min == -1) || (d[min] > d[i]))
					min = i;


		printf("Adding edge %d-%d\n", whoTo[min] , min );
		inTree[min] = 1;
		total += d[min];

		updateDistances(min,weight,whoTo,d,n);
	}
	cout<<"Total : "<<total << endl;
	
	
	
	
}

struct cmp {
    bool operator() (const Node * const &a, const Node * const &b){
        if(a->weight < b->weight) return true;
        else if(a->weight > b->weight) return false;
        else return a->i < b->i;
    }
};

void PrimList(GList &glist){
    int N = glist.getN();
    Node * nodes = new Node[N];
    list<Edge> * tab = glist.getTab();
    set<Node *, cmp> heap;
    heap.clear();
    
    // cout << "N: " << N << endl;
    
    bool gset[N];
    
    for(int i = 0; i < N; i++){
        gset[i] = false;
        Node * x = &nodes[i];
        x->i = i;
        // cout << "node: " << x->i << " " << x->parent << " " << x->weight << endl;
        heap.insert(x);
    }
    
    // cout << "h.size: " << heap.size() << endl;
    
    nodes[0].weight = 0;
    nodes[0].parent = 0;
    
    int v,w;
    Node * u;
    
    while(!heap.empty()){
        u = *heap.begin();
        heap.erase(heap.begin());
        gset[u->i] = true;
        
        for(list<Edge>::iterator it = tab[u->i].begin(); it != tab[u->i].end(); it++){
            v = it->peak;
            
            if(!gset[v]){
                w = it->weight;
                // cout << "w=" << w << ", nodes[v].weight=" << nodes[v].weight << endl;
                if(w < nodes[v].weight){
                    heap.erase(heap.find(&nodes[v]));
                    nodes[v].weight = w;
                    heap.insert(&nodes[v]);
                    nodes[v].parent = u->i;
                }
            }
        }
    }
    
    printNodes(nodes, N);
}

void printNodes(Node * nodes, int N){
	for(int i=0; i<N; i++)
		cout << "[" << i << "] : p = " << nodes[i].parent << " w = " << nodes[i].weight << endl;
}
