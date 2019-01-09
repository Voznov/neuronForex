#include <iostream>
#include <fstream>
#include "NN.h"
#include "neuron.h"
#include "activationFunctions.h"
#include "NNerrors.h"

using namespace std;

NN::NN() = default;

NN::~NN() = default;

void NN::readFromFile(string _filename) {
    ifstream fin(_filename, ios_base::in | ios_base::binary);
    if (!fin.is_open())
        throw ERROR_NN_WORK_WITH_FILE;

    fin.getline(version, _versionLength);
    fin.getline(createDate, _createDateLength);
    int linesSize;
    fin >> neuronsCount >> linesSize;
    for (int i = 0; i < linesSize; ++i) {
        int sizeOfLine;
        fin >> sizeOfLine;
        for (int j = 0; j < sizeOfLine; ++j) {
            //TODO: read neuron
        }
    }
}

void NN::writeToFile(string _filename) {
    //TODO: write NN
}
