#include "./../include/s21_smartcalc.h"
#include "./../include/s21_deposit.h"
#include "./../include/s21_credit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_NUMERIC, "C");
    QIcon icon(":calculator.png");
    s21_smartcalc w;
    w.setWindowIcon(icon);
    w.show();
    return a.exec();
}
