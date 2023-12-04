#include "s21_smartcalc.h"
#include "s21_deposit.h"
#include "s21_credit.h"
#include "ui_s21_deposit.h"

s21_deposit::s21_deposit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_deposit)
{
    ui->setupUi(this);
    ui->depositBox->addItem("Депозитный");
    ui->depositBox->addItem("Инженерный");
    ui->depositBox->addItem("Кредитный");

    connect(ui->depositBox, SIGNAL(activated(int)), this, SLOT(change_deposit(int)));
}

s21_deposit::~s21_deposit()
{
    delete ui;
}

void s21_deposit::change_deposit(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    if(index == 1) {
        this->close();
        s21_smartcalc *depositWindow = new s21_smartcalc();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    } else if(index == 2) {
        this->close();
        s21_credit *depositWindow = new s21_credit();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    }
}

