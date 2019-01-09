#include <cmath>

#include <cmath>

#include <cmath>

#include <cmath>

#include <cmath>

#include <cmath>
#include "activationFunctions.h"

float sqr(float x) {
    return x * x;
}

ActivationFunction::ActivationFunction() = default;

ActivationFunction::~ActivationFunction() = default;

Linear::Linear() = default;

Linear::~Linear() = default;

float Linear::process(float x) {
    return x;
}

float Linear::derivative(float x) {
    return 1;
}

Sigmoid::Sigmoid() = default;

Sigmoid::~Sigmoid() = default;

float Sigmoid::process(float x) {
    return 1 / (1 + std::exp(-x));
}

float Sigmoid::derivative(float x) {
    return std::exp(-x) / sqr(1 + std::exp(-x));
}

BipolarSigmoid::BipolarSigmoid() = default;

BipolarSigmoid::~BipolarSigmoid() = default;

float BipolarSigmoid::process(float x) {
    return (2 / (1 + std::exp(-x)) - 1);
}

float BipolarSigmoid::derivative(float x) {
    return 2 * std::exp(-x) / sqr(1 + std::exp(-x));
}

