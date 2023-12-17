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

void s21_credit::add_item_to_table(int row, int column, QString value) {
    QTableWidgetItem *item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);
    tableWindow->getUi()->table->setItem(row, column, item);
}

void s21_credit::on_calculate_clicked()
{
    int months = ui->credit_time->text().toInt();
    long double amount = ui->amount->text().toDouble();
    long double rate = ui->percent->text().toDouble();
    long double results[months + 1][4] = {0};
    long double summary_res[3] = {0};

    int days_of_months[months + 1][2] = {0};
    QDate current_day = ui->date_credit->date();
    for(int i = 0; i <= months; i++) {
        days_of_months[i][0] = current_day.daysInMonth();
        days_of_months[i][1] = current_day.isLeapYear(current_day.year());
        if(current_day.month() == 12) {
            QDate check_leap = current_day.addMonths(1);
            if(!days_of_months[i][1] && check_leap.isLeapYear(check_leap.year())) {
                days_of_months[i][0] = current_day.day();
                days_of_months[i][1] = 2;
            } else if(days_of_months[i][1]) {
                days_of_months[i][0] = current_day.day();
                days_of_months[i][1] = 3;
            }
        }
        current_day = current_day.addMonths(1);
    }

    calculate_credit(amount, months, days_of_months, rate, results, summary_res);

    if(tableWindow) {
        QPoint currentPosGlobal = this->mapToGlobal(QPoint(-700, 0));
        tableWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 700, 550);
        tableWindow->show();
        tableWindow->getUi()->table->setRowCount(months);
        current_day = ui->date_credit->date().addMonths(1);
        int additional_month = 0;

        for(int i = 0; i < months + additional_month; i++) {
            add_item_to_table(i, 0, current_day.toString("dd.MM.yyyy"));
            for(int j = 0; j < 4; j++) {
                add_item_to_table(i, j+1, QString::number(results[i][j], 'f', 2));
            }
            current_day = current_day.addMonths(1);
            if(i == months - 1 && results[i][3] > 0) {
                additional_month = 1;
                tableWindow->getUi()->table->setRowCount(months + additional_month);
            }
        }
        for(int i = 0; i < 3; i++) {
            QString number = QString::number(static_cast<double>(summary_res[i]), 'f', 2);
            if(i == 0) {
                tableWindow->getUi()->total_info->setText("<html>Total paid: " + number + "</html>");
            } else if (i == 1) {
                tableWindow->getUi()->debt_info->setText("<html>Debt paid: " + number + "</html>");
            } else {
                tableWindow->getUi()->interest_info->setText("<html>Interest paid: " + number + "</html>");
            }
        }
    }
}

