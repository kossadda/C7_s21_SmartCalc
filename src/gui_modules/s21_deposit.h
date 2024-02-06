#ifndef S21_DEPOSIT_H
#define S21_DEPOSIT_H

#include <QMainWindow>
#include "my_widget.h"
#include "s21_credit_table.h"
#include <QCheckBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

extern "C" {
#include "./../s21_smartcalc.h"
}

class s21_smartcalc;
class s21_credit;

namespace Ui {
class s21_deposit;
}

class s21_deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit s21_deposit(QWidget *parent = nullptr);
    ~s21_deposit();
    void change_mode(const QString index);


private slots:
    void onCheckBoxStateChanged(int state);
    int onAmountEditTextChanged(const QString &text);
    int onTimeEditTextChanged(const QString &text);
    int onInterestTextChanged(const QString &text);
    void onTimeEditIndexChanged();
    void on_calculate_clicked();
    void init_deposit_data(deposit_init *data);
    int init_operations(operations *op);
    void add_operation(operations *op, int count);
    void free_memory(deposit_init data, investment *pay, operations *op);
    int validation();

    void add_all_to_table(deposit_init data, investment *pay);
    void add_datarow_to_table(const QDate& date, QString row_head, long double **result, int iteration, int style);
    int check_date_between(const QDate& previous, const QDate& current, int* oper_count);
    void add_item_to_table(int row, int column, QString value, int style);

private:
    Ui::s21_deposit *ui;
    s21_credit_table *tableWindow;
    my_widget *opers;
    QCheckBox *checkBox;
    QTableWidget *taxWindow;
};

#endif // S21_DEPOSIT_H
