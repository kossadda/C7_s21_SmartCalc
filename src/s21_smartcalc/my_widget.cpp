#include "my_widget.h"
#include "ui_my_widget.h"

my_widget::my_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_widget)
{
    ui->setupUi(this);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pay_date->setDate(QDate::currentDate());
}

my_widget::~my_widget()
{
    delete ui;
}

bool containsOnlyDigits(const QString &str)
{
    for (const QChar &ch : str) {
        if (!ch.isDigit()) {
            return false;
        }
    }
    return true;
}

void my_widget::on_add_to_table_clicked()
{
    if(ui->pay_sum->text().length() && containsOnlyDigits(ui->pay_sum->text())) {
        ui->table->setRowCount(ui->table->rowCount() + 1);
        QTableWidgetItem *item_1 = new QTableWidgetItem(ui->pay_date->date().toString("dd.MM.yyyy"));
        item_1->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(ui->table->rowCount() - 1, 0, item_1);
        QTableWidgetItem *item_2 = new QTableWidgetItem(ui->pay_sum->text());
        item_2->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(ui->table->rowCount() - 1, 1, item_2);
        QTableWidgetItem *item_3 = new QTableWidgetItem(ui->pay_type->currentText());
        item_3->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(ui->table->rowCount() - 1, 2, item_3);
    }
}


void my_widget::on_clean_table_clicked()
{
    ui->table->setRowCount(ui->table->rowCount() - 1);
}

