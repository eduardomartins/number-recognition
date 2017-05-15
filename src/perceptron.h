#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QList>
#include <QObject>

#include <math.h>


class Perceptron// : public QObject
{
   // Q_OBJECT

public:

    explicit Perceptron(int size = 0);//, QObject *parent = 0);

    explicit Perceptron(double weights[], int size);//, QObject *parent = 0);

    void setWeights(double weights[], int size);

    double *weight(void);

    double *weight(void) const;

    double activate(double inputs[]);

    void trainning(double inputs[], double learningRate, double expected);

    Perceptron& operator=(const Perceptron &other);


signals:

public slots:

private:

    double *weights;

    int size;
};
#endif // PERCEPTRON_H
