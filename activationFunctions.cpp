#include <cmath>
#include "activationFunctions.h"

double sqr(double x)
{
	return x * x;
}

ActivationFunction::ActivationFunction()
{
}

ActivationFunction::~ActivationFunction()
{
}

Linear::Linear()
{
}

Linear::~Linear()
{
}

double Linear::process(double x)
{
	return x;
}

double Linear::derivative(double x)
{
	return 1;
}

Sigmoid::Sigmoid()
{
}

Sigmoid::~Sigmoid()
{
}

double Sigmoid::process(double x)
{
	return 1 / (1 + exp(-x));
}

double Sigmoid::derivative(double x)
{
	return exp(-x) / sqr(1 + exp(-x));
}

BipolarSigmoid::BipolarSigmoid()
{
}

BipolarSigmoid::~BipolarSigmoid()
{
}

double BipolarSigmoid::process(double x)
{
	return (2 / (1 + exp(-x)) - 1);
}

double BipolarSigmoid::derivative(double x)
{
	return 2 * exp(-x) / sqr(1 + exp(-x));
}

