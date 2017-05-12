#include "perceptron.h"


Perceptron::Perceptron(int size, QObject *parent)
    : QObject(parent)
{
    weights.size = size;
    weights.array = new double[size];
}

Perceptron::Perceptron(const Weight &weight, QObject *parent)
    : QObject(parent)

{
    this->weights = weight;
}


double Perceptron::activate(const Weight &input){
    double result = 0;

    // Activate function
    for(int i = 0; i < weights.size;i++)
        result += input.array[i] * weights.array[i];

    return result;
}


void Perceptron::trainning(const Weight &input, double learningRate, double expected){
    double error = 0.5 * pow((expected - activate(input)), 2.0);
    int i;

    // Update weights
    for(i = 0; i < weights.size;i++)
        weights.array[i] += learningRate * error * input.array[i];

    weights.size = i;

}

Weight Perceptron::weight(void)
{
    return weights;
}


Weight Perceptron::weight(void) const
{
    return weights;
}



Perceptron& Perceptron::operator=(const Perceptron &other)
{
    weights.array = other.weight().array;
    weights.size = other.weight().size;
    return *this;

}

