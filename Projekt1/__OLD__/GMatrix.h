#ifndef __GMATRIX_H_
#define __GMATRIX_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class GMatrix {
	private :
		int ** tab;
		int n;
	public :
		GMatrix();
		GMatrix(const char*);
		~GMatrix();
		int ** getTab();
		int getN();
};


#endif
