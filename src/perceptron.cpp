#include "perceptron.h"


Perceptron::Perceptron(QObject *parent)
    : QObject(parent)
    , learning_rate(0.0)
    , weights(nullptr)
{

}

Perceptron::Perceptron(const QList<double> &weights, QObject *parent)
    : QObject(parent)
    , learning_rate(0.0)
    , weights(nullptr)
{
    this->weights = weights;
}

static void Perceptron::setLearningRate(double rate)
{
    learning_rate = rate;
}

double Perceptron::activate(const QList<double> &inputs){
    double result = 0;

    // Activate function
    for(int i = 0; i < weights->size();i++)
        result += inputs.at(i) * weights->at(i);

    return result;
}


double Perceptron::trainning(const QList<double> &inputs, double expected){
    double error = 0.5 * pow((expected - activate(inputs)), 2.0);

    // Update weights
    for(int i = 0; i < weights->size();i++)
        weights[i] += learning_rate * error * inputs[i];

}
