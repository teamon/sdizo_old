#ifndef __PRIM_NODE_H_
#define __PRIM_NODE_H_

#include <limits.h>

namespace prim {
	class Node {
    public:
		int weight, parent;
        Node():weight(INT_MAX), parent(INT_MAX){};
    };
}; 

#endif
