#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class smartcalc; }
QT_END_NAMESPACE

class smartcalc : public QMainWindow
{
    Q_OBJECT

public:
    smartcalc(QWidget *parent = nullptr);
    ~smartcalc();

private:
    Ui::smartcalc *ui;

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
};
#endif // SMARTCALC_H
