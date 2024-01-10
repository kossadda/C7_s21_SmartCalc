#include "my_widget.h"
#include "ui_my_widget.h"
#include <QApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QVBoxLayout>

class DateTableWidgetItem : public QTableWidgetItem {
public:
    bool operator<(const QTableWidgetItem &other) const override {
        QDateTime date1 = QDateTime::fromString(text(), "dd.MM.yyyy");
        QDateTime date2 = QDateTime::fromString(other.text(), "dd.MM.yyyy");
        return date1 < date2;
    }
};

my_widget::my_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_widget)
{
    ui->setupUi(this);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->horizontalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0)");
    ui->table->verticalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0)");

    ui->table->setSortingEnabled(true);
    ui->table->sortByColumn(0, Qt::AscendingOrder);
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
        DateTableWidgetItem *item_1 = new DateTableWidgetItem();
        DateTableWidgetItem *item_2 = new DateTableWidgetItem();
        DateTableWidgetItem *item_3 = new DateTableWidgetItem();
        item_1->setText(ui->pay_date->date().toString("dd.MM.yyyy"));
        item_2->setText(ui->pay_sum->text());
        item_3->setText(ui->pay_type->currentText());
        item_1->setTextAlignment(Qt::AlignCenter);
        item_2->setTextAlignment(Qt::AlignCenter);
        item_3->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(ui->table->rowCount() - 1, 0, item_1);
        ui->table->setItem(item_1->row(), 1, item_2);
        ui->table->setItem(item_1->row(), 2, item_3);
    }
}

void my_widget::on_clean_table_clicked()
{
    ui->table->setRowCount(ui->table->rowCount() - 1);
}

QTableWidget* my_widget::getTableWidget()
{
    return ui->table;
}
