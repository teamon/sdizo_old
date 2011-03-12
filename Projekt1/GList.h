#include <iostream>
#include <fstream>
#include <list>

#include "Edge.h"

using namespace std;

class GList {
	private :
		int n;
		list< Edge > * tab;
	public :
		GList();
		GList(const char*);
		~GList();
		list< Edge > * getTab();
		int getN();
}; 
