#ifndef ANN_H
#define ANN_H

#include <QDebug>
#include <QtGlobal>
#include <QSettings>

#include "perceptron.h"

#define ENTRY_LAYER 400
#define INNER_LAYER 300
#define END_LAYER 10

#include <QObject>
#include <QVector>

namespace settingsVar
{

const double learnnigRate = 0.3;

const int epocas = 30;

}


inline double random_double(){
    return ((qrand() % 100) + 1.0)/ 100.0;
}

class PerceptronLayer: public QObject
{
    Q_OBJECT
public:

    PerceptronLayer(int size, QObject *parent = nullptr):
        QObject(parent)
    {
        layer = new QVector<Perceptron>(size);
    }


    PerceptronLayer(int size, int index, QObject *parent = nullptr):
        QObject(parent)
    {
        layer = new QVector<Perceptron>(size);
        layer_index = index;
    }


    void setLayerIndex(int index)
    {
        layer_index = index;
    }

    /*Perceptron &operator[](size_t index)
    {
        return layer[index];
    }

    const Perceptron &operator[](size_t index) const
    {
        return layer[index];
    }*/

    void setup()
    {
        settings.beginGroup(QString("layer-%1").arg(QString::number(layer_index)));

        int weight_size = settings.value(QString('size'), 0).toInt();

        double weights[weight_size];

        Perceptron *data = layer->data();

        for(int j = 0; j < layer->size(); j++)
        {
            settings.beginReadArray(QString("index-%1").arg(QString::number(j)));

            for (int i = 0; i < weight_size; ++i)
            {
                settings.setArrayIndex(i);
                weights[i] = settings.value("weight", random_double()).toDouble();
            }

            settings.endArray();
            data[j] = Perceptron(weights, weight_size);

        }
        settings.endGroup();
    }

private:

    int layer_index;
    QSettings settings;
    QVector<Perceptron> *layer;
};

class ANN: QObject {

    Q_OBJECT

public:

    static ANN & getInstance()
    {
        static ANN instance;
        return instance;
    }

    ANN(ANN const&)             = delete;
    void operator=(ANN const&)  = delete;

    ~ANN()
    {
        delete entryLayer;
        delete innerLayer;
        delete endLayer;
    }


private:

    PerceptronLayer *entryLayer;
    PerceptronLayer *innerLayer;
    PerceptronLayer *endLayer;

    ANN(QObject *parent = nullptr)
        : QObject(parent)
    {

        entryLayer = new PerceptronLayer(ENTRY_LAYER, 0);

        innerLayer = new PerceptronLayer(INNER_LAYER, 1);

        endLayer = new PerceptronLayer(END_LAYER, 2);

    }

};


#endif // ANN_H
