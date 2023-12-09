#include "s21_credit.h"
#include "s21_deposit.h"
#include "s21_smartcalc.h"
#include "ui_s21_credit.h"

s21_credit::s21_credit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_credit)
{
    ui->setupUi(this);
    ui->creditBox->addItem("Кредитный");
    ui->creditBox->addItem("Инженерный");
    ui->creditBox->addItem("Депозитный");

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

    ui->time_box->addItem("лет");
    ui->time_box->addItem("месяцев");

    connect(ui->creditBox, SIGNAL(activated(int)), this, SLOT(change_credit(int)));
}

s21_credit::~s21_credit()
{
    delete ui;
}

void s21_credit::change_credit(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == 1) {
        newWindow = new s21_smartcalc();
    } else if (index == 2) {
        newWindow = new s21_deposit();
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}
