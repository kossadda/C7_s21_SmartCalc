#ifndef S21_DEPOSIT_H
#define S21_DEPOSIT_H

#include <QMainWindow>

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

private:
    Ui::s21_deposit *ui;
};

#endif // S21_DEPOSIT_H
