#include "./../include/credit_table.h"

#include "./ui_credit_table.h"

credit_table::credit_table(QWidget* parent)
    : QWidget(parent), ui(new Ui::credit_table) {
  ui->setupUi(this);
  ui->table->horizontalHeader()->setStyleSheet(
      "background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
  ui->table->verticalHeader()->setStyleSheet(
      "background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
}

credit_table::~credit_table() { delete ui; }

Ui::credit_table* credit_table::getUi() const { return ui; }
