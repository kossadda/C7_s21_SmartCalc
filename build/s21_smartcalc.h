#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

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
    void push_numbers();
    void main_operations();
    void historyLine();
    void false_check();
    void on_push_eq_clicked();
    void on_push_dot_clicked();
    void on_push_C_clicked();
    void on_push_erase_clicked();
    void on_push_CE_clicked();
    void on_push_pl_min_clicked();
};
#endif // S21_SMARTCALC_H
