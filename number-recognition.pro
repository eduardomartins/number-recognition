
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

qtHaveModule(printsupport): QT += printsupport


TEMPLATE = app
TARGET = app.bin

# Input
HEADERS += \
        src/ui_mainwindow.h \
        src/mainwindow.h \
	src/scribblearea.h \
	src/perceptron.h \
	src/ann.h

FORMS += src/mainwindow.ui

SOURCES += \
	src/mainwindow.cpp \
	src/main.cpp \
	src/scribblearea.cpp \
	src/perceptron.cpp


DESTDIR = bin
OBJECTS_DIR = bin/.obj
MOC_DIR = bin/.moc
RCC_DIR = bin/.rcc
UI_DIR = bin/.ui

debug
{
    DESTDIR = bin
    OBJECTS_DIR = bin/.obj
    MOC_DIR = bin/.moc
    RCC_DIR = bin/.rcc
    UI_DIR = bin/.ui
}

