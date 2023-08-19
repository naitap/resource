/*
    EditA version 1.0
    Copyright (c) NaiTap Studio.
*/

#include "edita.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    edita EditA;
    EditA.setWindowTitle("EditA");
    EditA.show();
    return app.exec();
}
