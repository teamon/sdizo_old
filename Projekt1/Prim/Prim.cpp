#include <iostream>
#include "Prim.h"
#include <set>
#include <stdio.h>

using namespace std;
using namespace prim;

void updateDistances(int target, int ** weight, int * whoTo, int * d, int n) {
	int i;
	for (int i = 0; i < n; ++i)
		if ((weight[target][i] != 0) && (d[i] > weight[target][i])) {
			d[i] = weight[target][i];
			whoTo[i] = target;
	}
}

void PrimMatrix(GMatrix &matrix){
	
	int ** weight = matrix.getTab();
	int n = matrix.getN();
	
	bool set[100];
	
    Node nodes[n];
	
	for (int i = 0; i < n; ++i){
		nodes[i].weight = INT_MAX;
		set[i] = false;
	}
		
	set[0] = true;
    // updateDistances(0,weight,whoTo,d,n);
	for (int i = 0; i < n; ++i)
		if ((weight[0][i] != 0) && (nodes[i].weight > weight[0][i])) {
			nodes[i].weight = weight[0][i];
			nodes[i].parent = 0;
	}
	
	int total = 0;
	for (int k = 1; k < n; ++k) {
		int min = -1;
		for (int i = 0; i < n; ++i)
			if (!set[i])
				if ((min == -1) || (nodes[min].weight > nodes[i].weight))
					min = i;


		printf("Adding edge %d-%d\n", nodes[min].parent , min );
		set[min] = true;
		total += nodes[min].weight;

        // updateDistances(min,weight,whoTo,d,n);s
		for (int i = 0; i < n; ++i){
    		if ((weight[min][i] != 0) && (nodes[i].weight > weight[min][i])) {
    			nodes[i].weight = weight[min][i];
    			nodes[i].parent = min;
			}
    	}
	}
	cout<<"Total : "<<total << endl;

	printNodes(nodes, n);
    
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
