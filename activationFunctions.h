#ifndef _A_FUNCION_H_INCLUDED
#define _A_FUNCION_H_INCLUDED

float sqr(float x);

class ActivationFunction {
public:
    ActivationFunction();

    virtual ~ActivationFunction();

    virtual float process(float x) = 0;

    virtual float derivative(float x) = 0;
};

class Linear : public ActivationFunction {
public:
    Linear();

    ~Linear() override;

    float process(float x) override;

    float derivative(float x) override;
};

class Sigmoid : public ActivationFunction {
public:
    Sigmoid();

    ~Sigmoid() override;

    float process(float x) override;

    float derivative(float x) override;
};

class BipolarSigmoid : public ActivationFunction {
public:
    BipolarSigmoid();

    ~BipolarSigmoid() override;

    float process(float x) override;

    float derivative(float x) override;
};

#endif //_A_FUNCION_H_INCLUDED
