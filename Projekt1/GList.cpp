#include "GList.h"

GList::GList(){
	n = 0;
	tab = NULL;
} 

GList::GList(const char * filename){
	ifstream in(filename);
	
	in>>n;
	
	
	tab = new list< Edge >[n];
	int x,peak,weight;
	for(int i = 0;i<n;i++){
		in>>x;
		//tab[i] = new list < Edge >;
		for(int j=0;j<x;j++)
			in>>peak>>weight;
			tab[i].push_back(Edge(peak,weight));
	} 
}

GList::~GList(){
	delete [] tab;
	tab = NULL;
}

list< Edge > * GList::getTab(){
	return tab;
}

int GList::getN(){
	return n;
}
