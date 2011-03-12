#include "GMatrix.h"

GMatrix::GMatrix(){
	n = 0;
	tab = NULL;
};

GMatrix::GMatrix(const char* filename){
	ifstream in(filename);
	in>>n;
	
	tab = new int*[n];
	for(int i=0;i<n;i++)
		tab[i] = new int[n];
		
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			in>>tab[i][j];
};

GMatrix::~GMatrix(){
	for(int i=0;i<n;i++)
		delete [] tab[i];
	delete [] tab;
	tab = NULL;
}

int ** GMatrix::getTab(){
	return tab;
}
