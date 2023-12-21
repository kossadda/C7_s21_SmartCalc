#include "s21_smartcalc.h"
#include "s21_deposit.h"
#include "s21_credit.h"
#include "ui_s21_deposit.h"

s21_deposit::s21_deposit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_deposit)
{
    ui->setupUi(this);

    connect(ui->depositBox, SIGNAL(activated(int)), this, SLOT(change_deposit(int)));

    ui->sum_box->addItem(" ₽ - RUB");
    ui->sum_box->addItem(" $ - USD");
    ui->sum_box->addItem(" € - EUR");
    ui->sum_box->addItem(" ¥ - CNY");
    ui->sum_box->addItem(" ₹ - INR");
    ui->sum_box->addItem(" ₸ - KZT");
    ui->sum_box->addItem(" ¥ - JPY");
    ui->sum_box->addItem(" ₣ - CHF");
    ui->sum_box->addItem(" ฿ - THB");
    ui->sum_box->addItem(" ₾ - GEL");

    ui->time_box->addItem("дней");
    ui->time_box->addItem("месяцев");
    ui->time_box->addItem("лет");

    ui->payment_period->addItem("В конце срока");
    ui->payment_period->addItem("каждый день");
    ui->payment_period->addItem("каждую неделю");
    ui->payment_period->addItem("раз в месяц");
    ui->payment_period->addItem("раз в квартал");
    ui->payment_period->addItem("раз в полгода");
    ui->payment_period->addItem("раз в год");
}


s21_deposit::~s21_deposit()
{
    if(myWidget) delete myWidget;
    delete ui;
}

void s21_deposit::change_deposit(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == 1) {
        newWindow = new s21_smartcalc();
    } else if (index == 2) {
        newWindow = new s21_credit();
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}
