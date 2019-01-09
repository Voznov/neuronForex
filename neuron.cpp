#include <vector>
#include <cstdlib>
#include <climits>
#include "neuron.h"
#include "activationFunctions.h"
#include "NNerrors.h"

Neuron::Neuron() {
    isInputNeuron = true;
}

Neuron::Neuron(ActivationFunction *_aFunction, vector<Neuron *> _parents) {
    if (_aFunction == nullptr)
        throw ERROR_NEURON_NULL_A_FUNCTION;

    isInputNeuron = false;

    aFunction = _aFunction;

    for (Neuron *parent : _parents) {
        addParent(parent);
        parent->addChild(this);
    }

    weightNeutral = randomWeight();
}

Neuron::~Neuron() = default;

float Neuron::randomWeight() {
    return rand() / (float) INT_MAX;
}

void Neuron::addParent(Neuron *_parent) {
    addParent(_parent, randomWeight());
}

void Neuron::addParent(Neuron *_parent, float value) {
    if (_parent == nullptr)
        throw ERROR_NEURON_NULL_REFERENCE;

    parents.push_back(_parent);
    weights.push_back(value);
    deltaWeights.push_back(0);
}

void Neuron::addChild(Neuron *_child) {
    if (_child == nullptr)
        throw ERROR_NEURON_NULL_REFERENCE;

    children.push_back(_child);
}

float Neuron::process(float x) {
    return aFunction->process(x);
}

float Neuron::derivative(float x) {
    return aFunction->derivative(x);
}

float Neuron::calculateResult(float _result) {
    if (!isInputNeuron)
        throw ERROR_NEURON_WRONG_METHOD;

    result = _result;

    return result;
}

float Neuron::calculateResult() {
    if (isInputNeuron)
        throw ERROR_NEURON_WRONG_METHOD;

    float sumInput = weightNeutral;
    for (int i = 0; i < parents.size(); ++i)
        sumInput += parents[i]->result * weights[i];

    result = process(sumInput);

    return result;
}

void Neuron::calculateDelta(float trainingSpeed, float _result) {
    if (isInputNeuron || !children.empty())
        throw ERROR_NEURON_WRONG_METHOD;

    error = (_result - result) * derivative(sumInput);

    deltaWeightNeutral = trainingSpeed * error;
    for (int i = 0; i < parents.size(); ++i)
        deltaWeights[i] = trainingSpeed * error * parents[i]->result;
}

void Neuron::calculateDelta(float trainingSpeed) {
    if (isInputNeuron || children.empty())
        throw ERROR_NEURON_WRONG_METHOD;

    float deltaResult = 0;
    for (auto &i : children)
        deltaResult += i->error * i->findWeight(this);

    error = deltaResult * derivative(sumInput);

    deltaWeightNeutral = trainingSpeed * error;
    for (int i = 0; i < parents.size(); ++i)
        deltaWeights[i] = trainingSpeed * error * parents[i]->result;
}

void Neuron::changeWeights() {
    if (isInputNeuron)
        throw ERROR_NEURON_WRONG_METHOD;

    weightNeutral += deltaWeightNeutral;
    deltaWeightNeutral = 0;

    for (int i = 0; i < weights.size(); ++i) {
        weights[i] += deltaWeights[i];
        deltaWeights[i] = 0;
    }
}

float Neuron::findWeight(Neuron *_parent) {
    if (_parent == nullptr)
        throw ERROR_NEURON_NULL_REFERENCE;

    for (int i = 0; i < parents.size(); ++i)
        if (parents[i] == _parent)
            return weights[i];

    throw ERROR_NEURON_BAD_CONNECTION;
}
