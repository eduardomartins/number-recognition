#include "perceptron.h"


Perceptron::Perceptron(int size)
//: QObject(parent)
{
    this->weights = new double[size];
}

Perceptron::Perceptron(double weight[], int size)
//: QObject(parent)

{
    this->weights = weight;
    this->size = size;
}


void Perceptron::setWeights(double weights[], int size){
    this->weights = weights;
    this->size = size;
}


double Perceptron::activate(double input[]){
    double result = 0;

    // Activate function
    for(int i = 0; i < size;i++)
        result += input[i] * weights[i];

    return result;
}


void Perceptron::trainning(double input[], double learningRate, double expected){
    double error = 0.5 * pow((expected - activate(input)), 2.0);

    // Update weights
    for(int i = 0; i < size;i++)
        weights[i] += learningRate * error * input[i];


}

double *Perceptron::weight(void)
{
    return weights;
}


double *Perceptron::weight(void) const
{
    return weights;
}



Perceptron& Perceptron::operator=(const Perceptron &other)
{
    weights = other.weight();
    return *this;

}

