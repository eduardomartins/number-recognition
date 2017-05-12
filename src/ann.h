#ifndef ANN_H
#define ANN_H

#include <QList>
#include <QDebug>
#include <QtGlobal>
#include <QSettings>

#include "perceptron.h"

const int totalEntryLayer = 400;

const int totalInnerLayer = 300;

const int totalEndLayer = 10;


/*void saveState(){
    settings.beginWriteArray("ServerItems");


    for (int i = 0; i < myvalue.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("ServerItem", list.at(i).myvalue);
    }

    settings.endArray();

}*/



double random_double(){
    return (double) ((qrand() % 100) + 1)/ 100.0;
}


void ann(){

    QSettings settings;

    // load intial weights

    QList<double> initial;


    // Load entry layer
    QList<Perceptron> entryLayer;

    settings.beginGroup("Entry layer");

    settings.beginReadArray(QString("index"));

    for (int i = 0; i < totalEntryLayer; ++i) {

        settings.setArrayIndex(i);

        initial[i] = settings.value("weight", random_double()).toDouble();

        entryLayer[i]Perceptron(initial);

        qDebug() << entryLayer[i];
    }

    settings.endArray();


    // Load inner layer
    QList<Perceptron> innerLayer;

    settings.beginGroup("Inner layer");

    for(int j = 0; j < totalInnerLayer; j++){

        settings.beginReadArray(QString("index-%1").arg(QString::number(j)));

        for (int i = 0; i < totalEntryLayer; ++i) {

            settings.setArrayIndex(i);

            initial[i] = settings.value("weight", random_double()).toDouble();
        }

        settings.endArray();

        innerLayer[j] = Perceptron(initial);

        qDebug() << innerLayer[j];

    }

    settings.endGroup();

    // Load inner layer
    QList<Perceptron> endLayer;

    settings.beginGroup("End layer");

    for(int j = 0; j < totalEndLayer; j++){

        settings.beginReadArray(QString("index-%1").arg(QString::number(j)));

        for (int i = 0; i < totalInnerLayer; ++i) {

            settings.setArrayIndex(i);

            initial[i] = settings.value("weight", random_double()).toDouble();
        }

        settings.endArray();

        endLayer[j] = Perceptron(initial);

        qDebug() << endLayer[j];

    }

    settings.endGroup();

}

#endif // ANN_H
