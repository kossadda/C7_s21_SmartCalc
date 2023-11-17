#include "s21_smartcalc.h"
#include "ui_s21_smartcalc.h"
#include <QString>

extern "C" {
#include "../functions/parser.c"
}

int history_line = 1;
int history_length = 60;
int length = 0;

s21_smartcalc::s21_smartcalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_smartcalc)
{
    ui->setupUi(this);
    connect(ui->push_0, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_1, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_2, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_3, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_4, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_5, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_6, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_7, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_8, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_9, SIGNAL(clicked()), this, SLOT(push_numbers()));
    connect(ui->push_sum, SIGNAL(clicked()), this, SLOT(main_operations()));
    connect(ui->push_sub, SIGNAL(clicked()), this, SLOT(main_operations()));
    connect(ui->push_mult, SIGNAL(clicked()), this, SLOT(main_operations()));
    connect(ui->push_div, SIGNAL(clicked()), this, SLOT(main_operations()));

    ui->push_sum->setCheckable(true);
    ui->push_sub->setCheckable(true);
    ui->push_mult->setCheckable(true);
    ui->push_div->setCheckable(true);
}

s21_smartcalc::~s21_smartcalc()
{
    delete ui;
}

void s21_smartcalc::push_numbers()
{
    if(ui->history->text().contains('=')) {
        on_push_CE_clicked();
    }
    QPushButton *button = (QPushButton *)sender();
    if (button)
    {
        QString currentText = ui->resfield->text();
        currentText += button->text();
        ui->resfield->setText(currentText);
    }
}

void s21_smartcalc::historyLine()
{
    history_length = history_line * 70;
    if(history_line > 2) {
        ui->history->setText("");
        history_line = 1;
    }
    if(ui->history->text().length() > history_length) {
        ui->history->setText(ui->history->text() + "<br>");
        history_line++;
    }
}

void s21_smartcalc:: false_check()
{
    ui->push_sum->setChecked(false);
    ui->push_sub->setChecked(false);
    ui->push_mult->setChecked(false);
    ui->push_div->setChecked(false);
}

void s21_smartcalc::main_operations()
{
    historyLine();

    QPushButton *button = (QPushButton *)sender();

    button->setChecked(true);
    if(ui->resfield->text().length() > 0) {
        if(ui->push_sum->isChecked()) {
            ui->history->setText(ui->history->text() + ui->resfield->text() + " + ");
        } else if(ui->push_sub->isChecked()) {
            ui->history->setText(ui->history->text() + ui->resfield->text() + " - ");
        } else if(ui->push_mult->isChecked()) {
            ui->history->setText(ui->history->text() + ui->resfield->text() + " * ");
        } else if(ui->push_div->isChecked()) {
            ui->history->setText(ui->history->text() + ui->resfield->text() + " / ");
        }
    } else {
        QString temp = ui->history->text();
        temp.chop(3);
        ui->history->setText(temp);
        if(ui->push_sum->isChecked()) {
            ui->history->setText(ui->history->text() + " + ");
        } else if(ui->push_sub->isChecked()) {
            ui->history->setText(ui->history->text() + " - ");
        } else if(ui->push_mult->isChecked()) {
            ui->history->setText(ui->history->text() + " * ");
        } else if(ui->push_div->isChecked()) {
            ui->history->setText(ui->history->text() + " / ");
        }
    }
    ui->resfield->setText("");
    false_check();
}


void s21_smartcalc::on_push_eq_clicked()
{
    if(ui->resfield->text().length() == 0) {
        QString temp = ui->history->text();
        temp.chop(3);
        ui->history->setText(temp);
    }
    QString equal = "";
    int count = 0;
    for(const QChar &c : ui->history->text()) {
        if(c == '=') count++;
    }
    if(count == 0) equal = " = ";
    ui->history->setText(ui->history->text() + ui->resfield->text() + equal);

    QString temp2 = ui->history->text();
    temp2.chop(3);
    QByteArray byteArray = temp2.toUtf8();
    double result = parser((char *)byteArray.constData());
    ui->resfield->setText(QString::number(result, 'g', 9));
}


void s21_smartcalc::on_push_dot_clicked()
{
    if(!(ui->resfield->text().contains('.'))) {
        ui->resfield->setText(ui->resfield->text() + ".");
    }
}


void s21_smartcalc::on_push_C_clicked()
{
    ui->resfield->setText("");
}


void s21_smartcalc::on_push_erase_clicked()
{
    QString currentText = ui->resfield->text();

    if (!currentText.isEmpty()) {
        currentText.chop(1);
        ui->resfield->setText(currentText);
    }
}


void s21_smartcalc::on_push_CE_clicked()
{
    ui->resfield->setText("");
    ui->history->setText("");
}


void s21_smartcalc::on_push_pl_min_clicked()
{
    long double temp = ui->resfield->text().toDouble();
    temp *= -1;
    ui->resfield->setText(QString::number(temp, 'g', 16));
}

