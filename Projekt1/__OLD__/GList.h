#ifndef _GLIST_H_
#define _GLIST_H_

#include <iostream>
#include <fstream>
#include <list>

#include "Edge.h"
#include "GMatrix.h"

using namespace std;

class GList {
	private :
		int n;
        int p;
		list< Edge > * tab;
	public :
		GList();
		GList(const char*, bool oneway);
        GList(GMatrix * matrix);
		~GList();
		list< Edge > * getTab();
		int getN();
		int getP();
}; 

#endif
