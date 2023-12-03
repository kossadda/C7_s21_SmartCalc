#include "s21_smartcalc.h"
#include "locale.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_NUMERIC, "C");
    s21_smartcalc w;
    w.show();
    return a.exec();
}
