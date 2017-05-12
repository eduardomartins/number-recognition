#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QList>
#include <QObject>

#include <math.h>


typedef struct {
    double *array;
    int size;

} Weight;



class Perceptron : public QObject
{
    Q_OBJECT

public:

    Perceptron(int size = 0, QObject *parent = 0);

    Perceptron(const Weight &weights, QObject *parent = 0);

    Weight weight(void);

    Weight weight(void) const;

    double activate(const Weight &inputs);

    void trainning(const Weight &inputs, double learningRate, double expected);

    Perceptron& operator=(const Perceptron &other);


signals:

public slots:

private:

    Weight weights;
};
#endif // PERCEPTRON_H
