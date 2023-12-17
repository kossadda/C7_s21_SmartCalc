#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include <QMainWindow>
#include "s21_credit_table.h"
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

private:
    Ui::s21_credit *ui;
    s21_credit_table *tableWindow;
};

#endif // S21_CREDIT_H
