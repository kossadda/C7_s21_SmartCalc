#include "s21_smartcalc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21_smartcalc w;
    w.show();
    return a.exec();
}
