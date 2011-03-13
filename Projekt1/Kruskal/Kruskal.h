#ifndef __KRUSKAL_H_
#define __KRUSKAL_H_

#include "../GMatrix.h"
#include "../GList.h"

class KEdge {
public :
    int a,b,weight;
    KEdge(int a, int b, int w) : a(a), b(b), weight(w){}
    KEdge() : a(0), b(0), weight(0){}

};

void KruskalMatrix(GMatrix &matrix);
void KruskalList(GList &list);
// void printNodes(prim::Node * nodes, int N);

#endif
