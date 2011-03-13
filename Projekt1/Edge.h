#ifndef __EDGE_H_
#define __EDGE_H_

class Edge {
public :
    int peak, weight;
    Edge(int p, int w) : peak(p), weight(w){}
    Edge() : peak(0), weight(0){}
};

#endif