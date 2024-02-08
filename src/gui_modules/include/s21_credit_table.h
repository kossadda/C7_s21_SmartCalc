#ifndef S21_CREDIT_TABLE_H
#define S21_CREDIT_TABLE_H

#include <QWidget>

namespace Ui {
class s21_credit_table;
}

class s21_credit_table : public QWidget
{
    Q_OBJECT

public:
    explicit s21_credit_table(QWidget *parent = nullptr);
    ~s21_credit_table();

    Ui::s21_credit_table* getUi() const;

private:
    Ui::s21_credit_table *ui;
};

#endif // S21_CREDIT_TABLE_H
