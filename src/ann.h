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


namespace settingsVar
{

const double learnnigRate = 0.3;
const int epocas = 30;

}


const int totalEndLayer = END_LAYER;

const int totalEntryLayer = ENTRY_LAYER;

const int totalInnerLayer = INNER_LAYER;


double random_double(){
    return ((qrand() % 100) + 1.0)/ 100.0;
}


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

    static void setup(){
        // load intial weights

        int i;
        Weight buffer;
        QSettings settings;

        double bias[1], entry[ENTRY_LAYER], inner[ENTRY_LAYER];

        // Load entry layer

        settings.beginGroup("Entry layer");

        settings.beginReadArray(QString("index"));

        for (int i = 0; i < totalEntryLayer; ++i) {

            settings.setArrayIndex(i);

            bias[i] = settings.value("weight", random_double()).toDouble();

            buffer.size = 1;
            buffer.array = bias;

            entryLayer[i] = Perceptron(buffer);

            qDebug() << bias[i];
        }

        settings.endArray();


        // Load inner layer

        settings.beginGroup("Inner layer");


        for(int j = 0; j < totalInnerLayer; j++){

            settings.beginReadArray(QString("index-%1").arg(QString::number(j)));

            for (i = 0; i < totalEntryLayer; ++i) {

                settings.setArrayIndex(i);

                entry[i] = settings.value("weight", random_double()).toDouble();

                qDebug() << entry[i];
            }

            buffer.size = i;

            buffer.array = entry;

            settings.endArray();

            innerLayer[j] = Perceptron(buffer);


        }

        settings.endGroup();

        // Load inner layer

        settings.beginGroup("End layer");

        for(int j = 0; j < totalEndLayer; j++){

            settings.beginReadArray(QString("index-%1").arg(QString::number(j)));

            for (i = 0; i < totalInnerLayer; ++i) {

                settings.setArrayIndex(i);

                inner[i] = settings.value("weight", random_double()).toDouble();

                qDebug() << inner[i];
            }

            settings.endArray();

            buffer.array = inner;
            buffer.size = i;

            endLayer[j] = Perceptron(buffer);

        }

        settings.endGroup();

    }

private:

    ANN(QObject *parent = nullptr): QObject(parent){

        entryLayer = new Perceptron[ENTRY_LAYER];

        innerLayer = new Perceptron[INNER_LAYER];

        endLayer = new Perceptron[END_LAYER];

    }

    Perceptron *entryLaye;

    Perceptron *innerLayer;

    Perceptron *endLayer;

}

#endif // ANN_H
