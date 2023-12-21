#include "s21_credit.h"
// #include "s21_deposit.h"
// #include "s21_smartcalc.h"
#include "ui_s21_credit.h"
#include "ui_s21_credit_table.h"

extern "C" {
#include "../s21_calculations/s21_credit/s21_credit.h"
#include "../s21_calculations/s21_credit/s21_credit.c"
#include "../s21_calculations/s21_credit/s21_annuity.c"
#include "../s21_calculations/s21_credit/s21_differentiated.c"
#include "../s21_calculations/s21_credit/s21_calendar.c"
#include "../s21_calculations/s21_credit/s21_supporting.c"
}

s21_credit::s21_credit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_credit)
    , tableWindow(nullptr)
{
    ui->setupUi(this);
    tableWindow = new s21_credit_table();

    early_pay = new my_widget(this);
    ui->layout_1->addWidget(early_pay);


    tableWindow->getUi()->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // ui->date_edit->setDate(QDate::currentDate());

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
    // QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    // QSize currentSize = this->size();
    // QMainWindow* newWindow = nullptr;

    // if (index == 1) {
    //     newWindow = new s21_smartcalc();
    // } else if (index == 2) {
    //     newWindow = new s21_deposit();
    // }

    // if (newWindow) {
    //     this->close();
    //     newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
    //     newWindow->show();
    // }
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

void init_redemption(another_payments *redemtion) {
    redemtion->date = (time_data *)malloc(1 * sizeof(time_data));
    redemtion->sum = (long double *)malloc(1 * sizeof(long double));
    redemtion->type = (int *)malloc(1 * sizeof(int));
    redemtion->count = 0;
}

void add_redemption(another_payments *redemtion, my_widget *early_pay, int count) {
    redemtion->date = (time_data *)realloc(redemtion->date, (count + 1) * sizeof(time_data));
    redemtion->sum = (long double *)realloc(redemtion->sum, (count + 1) * sizeof(long double));
    redemtion->type = (int *)realloc(redemtion->type, (count + 1) * sizeof(int));
    QTableWidgetItem *item1 = early_pay->getTableWidget()->item(count, 0);
    QDate one_date = QDate::fromString(item1->text(), "dd.MM.yyyy");
    redemtion->date[count].day = one_date.day();
    redemtion->date[count].month = one_date.month();
    redemtion->date[count].year = one_date.year();
    QTableWidgetItem *item2 = early_pay->getTableWidget()->item(count, 1);
    redemtion->sum[count] = item2->text().toDouble();
    QTableWidgetItem *item3 = early_pay->getTableWidget()->item(count, 2);
    if(item3->text() == "Reduce term") {
        redemtion->type[count] = REDUCE_TERM;
    } else {
        redemtion->type[count] = REDUCE_PAY;
    }
    redemtion->count++;
}

void init_parameters(initial *data, Ui::s21_credit *ui) {
    data->months = ui->time_edit->text().toInt();
    data->debt = ui->amount_edit->text().toDouble();
    data->rate = ui->percent_edit->text().toDouble();
    data->date.day = ui->date_edit->date().day();
    data->date.month = ui->date_edit->date().month();
    data->date.year = ui->date_edit->date().year();
}

void s21_credit::on_calculate_clicked()
{
    payments pay;
    initial data;
    another_payments redemtion;
    init_parameters(&data, ui);

    if(early_pay) {
        if(early_pay->getTableWidget()->rowCount()) {
            init_redemption(&redemtion);
        }
        for(int count = 0; count < early_pay->getTableWidget()->rowCount(); count++) {
            add_redemption(&redemtion, early_pay, count);
        }
    }

    if(ui->annuity->isChecked()) {
        data.payment_type = ANNUITY;
    } else {
        if(ui->differentiated->isChecked()) {
            data.payment_type = DIFFERENTIATED;
        } else {
            data.payment_type = NOT_CHOSEN;
        }
    }
    if(data.payment_type != NOT_CHOSEN) {
        calculate_credit(&data, &pay, &redemtion);

        if(tableWindow) {
            QPoint currentPosGlobal = this->mapToGlobal(QPoint(-700, 0));
            tableWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 700, 550);
            tableWindow->show();
            tableWindow->getUi()->table->setRowCount(data.current);
            add_all_to_table(data.current, pay.result, pay.total);
        }
        free_memory(data.current, &pay.result, &pay.total);
        if(redemtion.date != NULL) {
            free(redemtion.date);
            redemtion.date = NULL;
        }
        if(redemtion.sum != NULL) {
            free(redemtion.sum);
            redemtion.sum = NULL;
        }
        if(redemtion.type != NULL) {
            free(redemtion.type);
            redemtion.type = NULL;
        }
    }
}

void s21_credit::add_item_to_table(int row, int column, QString value) {
    QTableWidgetItem *item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);
    tableWindow->getUi()->table->setItem(row, column, item);
}

void s21_credit::add_all_to_table(int months, long double **result, long double *total) {
    int first_date = ui->date_edit->date().day();
    QDate current_day = ui->date_edit->date().addMonths(1);
    for(int i = 0; i < months; i++) {
        add_item_to_table(i, 0, current_day.toString("dd.MM.yyyy"));
        for(int j = 0; j < 4; j++) {
            add_item_to_table(i, j+1, QString::number(result[i][j], 'f', 2));
        }
        current_day = current_day.addMonths(1);

        if(current_day.day() != first_date) {
            if(first_date > current_day.day()) {
                current_day.setDate(current_day.year(), current_day.month(), current_day.daysInMonth());
            } else {
                current_day.setDate(current_day.year(), current_day.month(), first_date);
            }
        }
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
