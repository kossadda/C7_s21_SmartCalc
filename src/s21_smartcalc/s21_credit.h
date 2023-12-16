#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include <QMainWindow>

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

private:
    Ui::s21_credit *ui;
};

#endif // S21_CREDIT_H
