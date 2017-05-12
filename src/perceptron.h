#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QList>
#include <QObject>

#include <math.h>


class Perceptron : public QObject
{
    Q_OBJECT

public:

    Perceptron(QObject *parent = 0);

    Perceptron(const QList<double> &weights, QObject *parent = 0);

    static void setLearningRate(double rate);

    double activate(const QList<double> &inputs);

    double trainning(const QList<double> &inputs, double expected);

signals:

public slots:

private:

    static double learning_rate;
    QList<double> *weights;
};

#endif // PERCEPTRON_H
