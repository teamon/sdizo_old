#include "GList.h"

GList::GList(){
	n = 0;
	tab = NULL;
} 

GList::GList(const char * filename){
	ifstream in(filename);
	
	in>>n;
	
	tab = new list< Edge >[n];
	int start,end,weight;
	while(!in.eof()){
		in >> start >> end >> weight;
		tab[start].push_back(Edge(end,weight));
		tab[end].push_back(Edge(start,weight));
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
