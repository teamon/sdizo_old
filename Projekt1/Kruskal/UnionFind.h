#ifndef __UNION_FIND_H_
#define __UNION_FIND_H_


class UnionFind {
public:
    UnionFind(int n);
    ~UnionFind();
    
    int find(int x);
    bool join(int a, int b);

protected:
    int *data, *count;
};

#endif
