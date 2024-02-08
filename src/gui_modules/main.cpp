#include "s21_smartcalc.h"
#include "s21_deposit.h"
#include "s21_credit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_NUMERIC, "C");
    s21_smartcalc w;
    w.show();
    return a.exec();
}
