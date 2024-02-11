#include <QApplication>

#include "./../include/credit.h"
#include "./../include/deposit.h"
#include "./../include/smartcalc.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_NUMERIC, "C");
  QIcon icon(":calculator.png");
  smartcalc w;
  w.setWindowIcon(icon);
  w.show();
  return a.exec();
}
