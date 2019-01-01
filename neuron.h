#ifndef _NEURON_H_INCLUDED
#define _NEURON_H_INCLUDED

#include <vector>
#include "activationFunctions.h"

using namespace std;

class Neuron
{
private:
	vector<Neuron*> parents;
	vector<Neuron*> children;

	float result;
	float sumInput;
	float error;

	vector<float> weights;
	vector<float> deltaWeights;
	float weightNeutral;
	float deltaWeightNeutral;

	float findWeight(Neuron* _parent);

	bool isInputNeuron;
	ActivationFunction* aFunction;

	void addParent(Neuron* _parent);
	void addParent(Neuron* _parent, float value);
	void addChild(Neuron* _child);
	void addChild(Neuron* _child, float value);
	
	float process(float x);
	float derivative(float x);

	float randomWeight();

public:
	Neuron(); //for input neurons
	Neuron(ActivationFunction* _aFunction, vector<Neuron*> _parents);
	~Neuron();

	float calculateResult(float _result); //for input neurons
	float calculateResult();
	
	void calculateDelta(float trainingSpeed, float _result); //for output neurons
	void calculateDelta(float trainingSpeed);

	void changeWeights();
};

#endif //_NEURON_H_INCLUDED
