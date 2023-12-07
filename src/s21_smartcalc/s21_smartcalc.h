#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

#include <QMainWindow>
#include <QPushButton>
#include "graphics.h"

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
    void on_graphWindowClosed();
    int countDigits(double number);
    void on_x_clicked();
    void on_plot_clicked();

    void clear_result();

    void push_nums();
    void on_push_eq_clicked();
    void on_push_sqrt_clicked();
    void on_push_log_clicked();
    void on_push_ln_clicked();
    void on_push_sin_clicked();
    void on_push_cos_clicked();
    void on_push_tan_clicked();
    void on_push_asin_clicked();
    void on_push_acos_clicked();
    void on_push_atan_clicked();
    void on_push_mod_clicked();
    void on_push_opn_brack_clicked();
    void on_push_cls_brack_clicked();
    void on_push_div_clicked();
    void on_push_mul_clicked();
    void on_push_sub_clicked();
    void on_push_sum_clicked();
    void on_push_e_clicked();
    void on_push_pi_clicked();
    void on_push_exp_clicked();
    void on_push_c_clicked();
    void on_push_del_clicked();
    void on_push_unar_clicked();
    void on_push_dot_clicked();
    void on_turn_back_clicked();
    void on_move_frwd_clicked();
    void on_graph_clicked();

private:
    Ui::s21_smartcalc *ui;
    QPushButton *pushButton;
    QPushButton *pushButton1;
    QStringList history;
    graphics *graphWindow;
    bool clear_after = false;
    int history_count = -1;
    void dummyFunction() {}
};
#endif // S21_SMARTCALC_H
