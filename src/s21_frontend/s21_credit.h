#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include <QMainWindow>
#include "s21_credit_table.h"
#include "my_widget.h"

extern "C" {
#include "../s21_backend/s21_main.h"
}

namespace Ui {
class s21_credit;
}

class s21_credit : public QMainWindow
{
    Q_OBJECT

public:
    explicit s21_credit(QWidget *parent = nullptr);
    ~s21_credit();

private slots:
    void change_credit(int index);
    void on_calculate_clicked();
    void add_item_to_table(int row, int column, QString value);
    void add_all_to_table(int months, long double **result, long double *total);
    void free_memory(credit_init data, payments *pay, early_pay *redemption);
    int check_date_between(const QDate& previous, const QDate& current, int* redemp_count);
    void add_datarow_to_table(const QDate& date, QString row_head, long double **result, int iteration);
    void add_redemption(early_pay *redemption, my_widget *early_pays, int count);
    void init_parameters(credit_init *data, Ui::s21_credit *ui);

private:
    Ui::s21_credit *ui;
    s21_credit_table *tableWindow;
    my_widget *early_pays;
};

#endif // S21_CREDIT_H
