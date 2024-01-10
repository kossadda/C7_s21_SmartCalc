#include "s21_credit_table.h"
#include "ui_s21_credit_table.h"

s21_credit_table::s21_credit_table(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::s21_credit_table)
{
    ui->setupUi(this);
    ui->table->horizontalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0)");
    ui->table->verticalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0)");
}

s21_credit_table::~s21_credit_table()
{
    delete ui;
}

Ui::s21_credit_table* s21_credit_table::getUi() const
{
    return ui;
}
