#include <iostream>
#include <fstream>
#include "NN.h"
#include "neuron.h"
#include "activationFunctions.h"
#include "NNerrors.h"

using namespace std;

NN::NN()
{
}

NN::~NN()
{
}

void NN::readFromFile(string _filename)
{
	ifstream fin(_filename, ios_base::in | ios_base::binary);
	if(!fin.is_open())
		throw ERROR_NN_WORK_WITH_FILE;

	fin >> version;
}
