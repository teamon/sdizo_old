#ifndef __PRIM_NODE_H_
#define __PRIM_NODE_H_

#include <limits.h>

namespace prim {
	class Node {
    public:
		int i, weight, parent;
        Node():i(0),weight(INT_MAX), parent(INT_MAX){};
    };
}; 

#endif
