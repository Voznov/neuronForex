#ifndef _A_FUNCION_H_INCLUDED
#define _A_FUNCION_H_INCLUDED

double sqr(double x);

class ActivationFunction
{
public:
	ActivationFunction();
	virtual ~ActivationFunction();
	virtual double process(double x) = 0;
	virtual double derivative(double x) = 0;
};

class Linear: public ActivationFunction
{
public:
	Linear();
	~Linear();
	double process(double x);
	double derivative(double x);
};

class Sigmoid: public ActivationFunction
{
public:
	Sigmoid();
	~Sigmoid();
	double process(double x);
	double derivative(double x);
};

class BipolarSigmoid: public ActivationFunction
{
public:
	BipolarSigmoid();
	~BipolarSigmoid();
	double process(double x);
	double derivative(double x);
};

#endif //_A_FUNCION_H_INCLUDED
