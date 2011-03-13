#include "GList.h"

GList::GList(){
	n = 0;
	tab = NULL;
} 

GList::GList(const char * filename, bool oneway = false){
	ifstream in(filename);
	in >> n >> p;
	
	tab = new list< Edge >[n];
	int start,end,weight;
	for(int i = 0; i < p; i++){
		in >> start >> end >> weight;
		tab[start].push_back(Edge(end,weight));
		if(!oneway) tab[end].push_back(Edge(start,weight));
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

int GList::getP(){
	return p;
}
