#ifndef _NN_H_INCLUDED
#define _NN_H_INCLUDED

#include <vector>
#include <cstring>
#include "neuron.h"

using namespace std;

class NN {
private:
    const static int _versionLength = 10;
    const static int _createDateLength = 15;
    vector<vector<Neuron *> > lines;
    char version[_versionLength];
    char createDate[_createDateLength];
    int neuronsCount = 0;
public:
    NN();

    ~NN();

    void readFromFile(string _filename);

    void writeToFile(string _filename);

    float run(float *_inputs, int _inputsCount);

    void goErrorBack(float *_results, int _resultsCount);
};

#endif //_NN_H_INCLUDED
