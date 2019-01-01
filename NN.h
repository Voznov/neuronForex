#ifndef _NN_H_INCLUDED
#define _NN_H_INCLUDED

#include <vector>
#include <cstring>
#include "neuron.h"

using namespace std;

class NN
{
private:
	vector<vector<Neuron*> > lines;
	char version[10];
	char createDate[15];
	int neuronsCount = 0;
public:
	NN();
	~NN();
	void readFromFile(string _filename);
	void writeToFile(string _filename);
	float run(float* _inputs, int _inputsCount);
	void goErrorBack(float* _results, int _resultsCount);
};
#endif //_NN_H_INCLUDED
