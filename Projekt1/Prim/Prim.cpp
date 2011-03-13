#include <iostream>
#include "Prim.h"
#include <set>
#include <stdio.h>

using namespace std;
using namespace prim;


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


        
		set[min] = true;
		total += nodes[min].weight;

        
		for (int i = 0; i < n; ++i){
    		if ((weight[min][i] != 0) && (nodes[i].weight > weight[min][i])) {
    			nodes[i].weight = weight[min][i];
    			nodes[i].parent = min;
			}
    	}
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
    
   
    
    bool gset[N];
    
    for(int i = 0; i < N; i++){
        gset[i] = false;
        Node * x = &nodes[i];
        x->i = i;
       
        heap.insert(x);
    }
    
   
    
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
                if(w < nodes[v].weight){
                    heap.erase(heap.find(&nodes[v]));
                    nodes[v].weight = w;
                    heap.insert(&nodes[v]);
                    nodes[v].parent = u->i;
                }
            }
        }
    }
    
    
    int total = 0;
    for(int i = 0; i < N; i++){
        total += nodes[i].weight;
    }
    
    cout<<"Total : "<<total << endl;
	
}

void printNodes(Node * nodes, int N){
	for(int i=0; i<N; i++)
		cout << "[" << i << "] : p = " << nodes[i].parent << " w = " << nodes[i].weight << endl;
}
