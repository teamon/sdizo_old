#include <iostream>
#include "Prim.h"
#include <set>

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


