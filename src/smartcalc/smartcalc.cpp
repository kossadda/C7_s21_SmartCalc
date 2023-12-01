#include "smartcalc.h"
#include "ui_smartcalc.h"

extern "C" {
#include "../C_part/parser.c"
}

smartcalc::smartcalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::smartcalc)
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
}

smartcalc::~smartcalc()
{
    delete ui;
}

void smartcalc::push_nums()
{
    if(ui->history->text().contains("=")) {
        on_push_CE_clicked();
    }
    QPushButton *button = (QPushButton *)sender();
    ui->resfield->setText(ui->resfield->text() + button->text());
}

void smartcalc::on_push_dot_clicked()
{
    if(!ui->resfield->text().contains(".") && ui->resfield->text().length() > 0) {
        ui->resfield->setText(ui->resfield->text() + ".");
    }
}

void smartcalc::on_push_bkt1_clicked()
{
    ui->history->setText(ui->history->text() + "(");
}

void smartcalc::on_push_bkt2_clicked()
{
    QString field = ui->resfield->text();
    ui->history->setText(ui->history->text() + field + ")");
    on_push_C_clicked();
}

void smartcalc::on_push_erase_clicked()
{
    QString field = ui->resfield->text();
    field.chop(1);
    ui->resfield->setText(field);
}

void smartcalc::on_push_C_clicked()
{
    ui->resfield->setText("");
}

void smartcalc::on_push_CE_clicked()
{
    ui->history->setText("");
    on_push_C_clicked();
}

void smartcalc::on_push_pl_min_clicked()
{
    if(ui->resfield->text().contains("-")) {
        QString field = ui->resfield->text();
        field.remove(0, 1);
        ui->resfield->setText(field);
    } else {
        if(ui->resfield->text().length() > 0) {
            ui->resfield->setText("-" + ui->resfield->text());
        }
    }
}

void smartcalc::on_push_sum_clicked()
{
    QString field = ui->resfield->text();
    QString istory = ui->history->text();
    if(field.length() == 0 && istory.length() > 0) {
        istory.chop(1);
        ui->history->setText(istory + "+");
    }
    if(ui->history->text().length() > 0 && field.contains("-")) {
        field = "(" + field + ")";
    }
    if(field.length() > 0) {
        ui->history->setText(istory + field + "+");
        on_push_C_clicked();
    }
}

void smartcalc::on_push_sub_clicked()
{
    QString field = ui->resfield->text();
    QString istory = ui->history->text();
    if(field.length() == 0 && istory.length() > 0) {
        istory.chop(1);
        ui->history->setText(istory + "-");
    }
    if(ui->history->text().length() > 0 && field.contains("-")) {
        field = "(" + field + ")";
    }
    if(field.length() > 0) {
        ui->history->setText(istory + field + "-");
        on_push_C_clicked();
    }
}

void smartcalc::on_push_mult_clicked()
{
    QString field = ui->resfield->text();
    QString istory = ui->history->text();
    if(field.length() == 0 && istory.length() > 0) {
        istory.chop(1);
        ui->history->setText(istory + "*");
    }
    if(ui->history->text().length() > 0 && field.contains("-")) {
        field = "(" + field + ")";
    }
    if(field.length() > 0) {
        ui->history->setText(istory + field + "*");
        on_push_C_clicked();
    }
}

void smartcalc::on_push_div_clicked()
{
    QString field = ui->resfield->text();
    QString istory = ui->history->text();
    if(field.length() == 0 && istory.length() > 0) {
        istory.chop(1);
        ui->history->setText(istory + "/");
    }
    if(ui->history->text().length() > 0 && field.contains("-")) {
        field = "(" + field + ")";
    }
    if(field.length() > 0) {
        ui->history->setText(istory + field + "/");
        on_push_C_clicked();
    }
}

void smartcalc::on_push_eq_clicked()
{
    if(ui->resfield->text().length() > 0) {
        ui->history->setText(ui->history->text() + ui->resfield->text());
    } else {
        QString temp = ui->history->text();
        temp.chop(1);
        ui->history->setText(temp);
    }
    QByteArray byteArray = ui->history->text().toUtf8();
    char* charArray = byteArray.data();
    double result = notation(charArray);
    ui->resfield->setText(QString::number(result, 'f', 7));
    if(!ui->history->text().contains("=")) {
        ui->history->setText(ui->history->text() + "=");
    }
}

