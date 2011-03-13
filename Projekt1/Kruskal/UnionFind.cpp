#include "UnionFind.h"

UnionFind::UnionFind(int n){
    data = new int[n];
    count = new int[n];
    for(int i=0; i<n; i++){
        data[i] = i;
        count[i] = 1;
    }
}

UnionFind::~UnionFind(){
    delete[] data;
    delete[] count;
}

int UnionFind::find(int x){
    if(data[x] == x) return x;
    int xp = find(data[x]);
    data[x] = xp;
    return xp;
}

bool UnionFind::join(int a, int b){
    int ap = find(a);
    int bp = find(b);
    
    if(ap == bp) return false;
    
    if(count[ap] <= count[bp]) {
        count[bp] += count[ap];
        data[ap] = bp;
    } else {
        count[ap] += count[bp];
        data[bp] = ap;
    }
    return true;
}
