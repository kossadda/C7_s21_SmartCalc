#include "s21_credit.h"
#include "s21_deposit.h"
#include "s21_smartcalc.h"
#include "ui_s21_credit.h"
#include "ui_s21_credit_table.h"

extern "C" {
#include "../calculations/s21_credit/main.c"
}

s21_credit::s21_credit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_credit)
    , tableWindow(nullptr)
{
    ui->setupUi(this);
    tableWindow = new s21_credit_table();

    tableWindow->getUi()->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // ui->date_credit->setDate(QDate::currentDate());

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
    if(tableWindow) {
        delete tableWindow;
    }
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

void s21_credit::on_calculate_clicked()
{
    long double amount = ui->amount->text().toDouble();
    int months = ui->credit_time->text().toInt();
    long double rate = ui->percent->text().toDouble();
    int month_min_count = (months > 12) ? months : 12;
    int days_of_months[month_min_count] = {0};
    long double results[months][4] = {0};
    long double summary_res[3] = {0};

    QDate current_day = ui->date_credit->date();
    for(int i = 0; i < month_min_count; i++) {
        days_of_months[i] = current_day.daysInMonth();
        current_day = current_day.addMonths(1);
    }
    calculate_credit(amount, months, days_of_months, rate, results);
    if(tableWindow) {
        QPoint currentPosGlobal = this->mapToGlobal(QPoint(-700, 0));
        tableWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 700, 550);
        tableWindow->show();
        tableWindow->getUi()->table->setRowCount(months + 2);
        current_day = ui->date_credit->date();
        QTableWidgetItem *first_date = new QTableWidgetItem(current_day.toString("dd.MM.yyyy"));
        QTableWidgetItem *first_date_info = new QTableWidgetItem("Issuance of credit");
        first_date->setTextAlignment(Qt::AlignCenter);
        first_date_info->setTextAlignment(Qt::AlignCenter);
        tableWindow->getUi()->table->setItem(0, 0, first_date);
        tableWindow->getUi()->table->setItem(0, 1, first_date_info);
        current_day = current_day.addMonths(1);

        for(int i = 0; i < months; i++) {
            QTableWidgetItem *dates = new QTableWidgetItem(current_day.toString("dd.MM.yyyy"));
            dates->setTextAlignment(Qt::AlignCenter);
            tableWindow->getUi()->table->setItem(i + 1, 0, dates);
            for(int j = 0; j < 4; j++) {
                QTableWidgetItem *data = new QTableWidgetItem(QString::number(static_cast<double>(results[i][j]), 'f', 2));
                data->setTextAlignment(Qt::AlignCenter);
                tableWindow->getUi()->table->setItem(i + 1, j + 1, data);
                if(j < 3) {
                    summary_res[j] += results[i][j];
                }
            }
            current_day = current_day.addMonths(1);
        }
        for(int i = 0; i < 3; i++) {
            QString number;
            if(i == 0) {
                number += "Total paid\n";
            } else if(i == 1) {
                number += "Debt paid\n";
            } else if(i == 2) {
                number += "Interest paid\n";
            }
            number += QString::number(static_cast<double>(summary_res[i]), 'f', 2);
            QTableWidgetItem *sums = new QTableWidgetItem(number);
            sums->setTextAlignment(Qt::AlignCenter);
            tableWindow->getUi()->table->setItem(months + 1, i + 1, sums);
        }
        int row_height = 30;
        for (int row = 0; row < months + 2; row++) {
            if(row == months + 1) {
                row_height = 60;
            }
            tableWindow->getUi()->table->setRowHeight(row, row_height);
        }
    }
}

