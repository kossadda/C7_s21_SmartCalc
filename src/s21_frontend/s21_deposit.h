#ifndef S21_DEPOSIT_H
#define S21_DEPOSIT_H

#include <QMainWindow>
#include "my_widget.h"
#include "s21_credit_table.h"
#include <QCheckBox>
#include <QMessageBox>

extern "C" {
#include "../s21_backend/s21_main.h"
}

namespace Ui {
class s21_deposit;
}

class s21_deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit s21_deposit(QWidget *parent = nullptr);
    ~s21_deposit();


private slots:
    void change_deposit(int index);
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

private:
    Ui::s21_deposit *ui;
    my_widget *opers;
    QCheckBox *checkBox;
};

#endif // S21_DEPOSIT_H
