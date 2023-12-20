#include "s21_credit.h"
#include "s21_deposit.h"
#include "s21_smartcalc.h"
#include "ui_s21_credit.h"
#include "ui_s21_credit_table.h"

extern "C" {
#include "../s21_calculations/s21_credit/s21_credit.h"
#include "../s21_calculations/s21_credit/s21_credit.c"
#include "../s21_calculations/s21_credit/s21_annuity.c"
#include "../s21_calculations/s21_credit/s21_differentiated.c"
#include "../s21_calculations/s21_credit/s21_calendar.c"
}

s21_credit::s21_credit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_credit)
    , tableWindow(nullptr)
{
    ui->setupUi(this);
    tableWindow = new s21_credit_table();

    early_pay = new my_widget(this);
    ui->verticalLayout->addWidget(early_pay);


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

void s21_credit::free_memory(int rows, long double ***result, long double **total) {
    for(int i = 0; i < rows; i++) {
        free((*result)[i]);
        (*result)[i] = NULL;
    }
    free(*result);
    free(*total);
    *result = NULL;
    *total = NULL;
}

void s21_credit::on_calculate_clicked()
{
    payments pay;
    initial data;
    data.months = ui->credit_time->text().toInt();
    data.debt = ui->amount->text().toDouble();
    data.rate = ui->percent->text().toDouble();
    data.date.day = ui->date_credit->date().day();
    data.date.month = ui->date_credit->date().month();
    data.date.year = ui->date_credit->date().year();

    if(ui->annuity->isChecked()) {
        data.payment_type = ANNUITY;
    } else {
        if(ui->differentiated->isChecked()) {
            data.payment_type = DIFFERENTIATED;
        } else {
            data.payment_type = NOT_CHOSEN;
        }
    }
    if(data.payment_type != 3) {
        calculate_credit(&data, &pay);

        if(tableWindow) {
            QPoint currentPosGlobal = this->mapToGlobal(QPoint(-700, 0));
            tableWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 700, 550);
            tableWindow->show();
            tableWindow->getUi()->table->setRowCount(data.current);
            add_all_to_table(data.current, pay.result, pay.total);
        }
        free_memory(data.current, &pay.result, &pay.total);
    }
}

void s21_credit::add_item_to_table(int row, int column, QString value) {
    QTableWidgetItem *item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);
    tableWindow->getUi()->table->setItem(row, column, item);
}

void s21_credit::add_all_to_table(int months, long double **result, long double *total) {
    int additional_month = 0;
    QDate current_day = ui->date_credit->date().addMonths(1);
    for(int i = 0; i < months + additional_month; i++) {
        add_item_to_table(i, 0, current_day.toString("dd.MM.yyyy"));
        for(int j = 0; j < 4; j++) {
            add_item_to_table(i, j+1, QString::number(result[i][j], 'f', 2));
        }
        current_day = current_day.addMonths(1);
    }
    for(int i = 0; i < 3; i++) {
        QString number = QString::number(static_cast<double>(total[i]), 'f', 2);
        if(i == 0) {
            tableWindow->getUi()->total_info->setText("Total paid: " + number);
        } else if (i == 1) {
            tableWindow->getUi()->debt_info->setText("Debt paid: " + number);
        } else {
            tableWindow->getUi()->interest_info->setText("Interest paid: " + number);
        }
    }
}
