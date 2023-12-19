#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include <QMainWindow>
#include "s21_credit_table.h"
#include "my_widget.h"

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
    void free_memory(int rows, long double ***result, long double **total);

private:
    Ui::s21_credit *ui;
    s21_credit_table *tableWindow;
    my_widget *early_pay;
};

#endif // S21_CREDIT_H
