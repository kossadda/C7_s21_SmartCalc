#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QMainWindow>
#include <QCheckBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "./my_widget.h"
#include "./credit_table.h"

extern "C" {
#include "./../../modules/smartcalc.h"
}

class smartcalc;
class credit;

namespace Ui {
class deposit;
}

class deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();
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
    Ui::deposit *ui;
    credit_table *tableWindow;
    my_widget *opers;
    QCheckBox *checkBox;
    QTableWidget *taxWindow;
};

#endif // DEPOSIT_H
