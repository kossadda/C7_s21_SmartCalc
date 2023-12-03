#ifndef s21_smartcalc_H
#define s21_smartcalc_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class s21_smartcalc; }
QT_END_NAMESPACE

class s21_smartcalc : public QMainWindow
{
    Q_OBJECT

public:
    s21_smartcalc(QWidget *parent = nullptr);
    ~s21_smartcalc();

private:
    Ui::s21_smartcalc *ui;

private slots:
    void push_nums();
    void on_push_dot_clicked();
    void on_push_erase_clicked();
    void on_push_pl_min_clicked();
    void on_push_C_clicked();
    void on_push_sum_clicked();
    void on_push_CE_clicked();
    void on_push_sub_clicked();
    void on_push_mult_clicked();
    void on_push_bkt1_clicked();
    void on_push_eq_clicked();
    void on_push_bkt2_clicked();
    void on_push_div_clicked();

    int countDigits(double number);
};
#endif // s21_smartcalc_H
