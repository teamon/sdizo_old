#ifndef __PRIM_NODE_H_
#define __PRIM_NODE_H_

namespace prim {
	class Node {
    public:
		int weight, parent;
        Node():weight(-1), parent(-1){};
    };
}; 

#endif
