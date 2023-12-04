#include "s21_smartcalc.h"
#include "s21_deposit.h"
#include "s21_credit.h"
#include "ui_s21_smartcalc.h"

extern "C" {
#include "../calculations/functions/main.c"
#include "../calculations/functions/validation.c"
#include "../calculations/functions/notation.c"
#include "../calculations/functions/checks.c"
#include "../calculations/functions/comparison.c"
#include "../calculations/functions/math_operations.c"
}

s21_smartcalc::s21_smartcalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_smartcalc)
{
    ui->setupUi(this);

    connect(ui->push_0, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_1, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_2, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_3, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_4, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_5, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_6, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_7, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_8, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_9, SIGNAL(clicked()), this, SLOT(push_nums()));

    ui->comboBox->addItem("Инженерный");
    ui->comboBox->addItem("Депозитный");
    ui->comboBox->addItem("Кредитный");

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(change_window(int)));
}

s21_smartcalc::~s21_smartcalc()
{
    delete ui;
}

int s21_smartcalc::countDigits(double number)
{
    int integer = static_cast<int>(number);
    std::string integer_string = std::to_string(integer);
    return integer_string.length();
}

void s21_smartcalc::change_window(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    if(index == 1) {
        this->close();
        s21_deposit *smartWindow = new s21_deposit();
        smartWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        smartWindow->show();
    } else if(index == 2) {
        this->close();
        s21_credit *smartWindow = new s21_credit();
        smartWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        smartWindow->show();
    }
}

void s21_smartcalc::change_deposit(int index)
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

void s21_smartcalc::change_credit(int index)
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
        s21_deposit *depositWindow = new s21_deposit();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    }
}

void s21_smartcalc::push_nums()
{
    QPushButton *button = (QPushButton *)sender();
    ui->result->setText(ui->result->text() + button->text());
}

void s21_smartcalc::on_push_eq_clicked()
{
    QByteArray byteArray = ui->result->text().toUtf8();
    char* charArray = byteArray.data();
    double res = calculation(charArray);
    ui->result->setText(QString::number(res, 'g', countDigits(res) + 10));
}

