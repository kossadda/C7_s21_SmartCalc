#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class s21_smartcalc;
}
QT_END_NAMESPACE

class s21_smartcalc : public QMainWindow
{
    Q_OBJECT

public:
    s21_smartcalc(QWidget *parent = nullptr);
    ~s21_smartcalc();

private slots:
    void change_window(int index);
    void change_deposit(int index);
    void change_credit(int index);

    void push_nums();
    void on_push_eq_clicked();
    int countDigits(double number);

private:
    Ui::s21_smartcalc *ui;
};
#endif // S21_SMARTCALC_H
