#include "s21_deposit.h"
#include "ui_s21_deposit.h"
#include "ui_s21_credit_table.h"

s21_deposit::s21_deposit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_deposit)
{
    ui->setupUi(this);
    ui->payment_period->setCurrentIndex(2);


    tableWindow = new s21_credit_table();
    tableWindow->getUi()->debt_info->setVisible(false);
    QStringList header_labels;
    header_labels << "Date" << "Interest accrued" << "Balance change" << "Pay" << "Balance";
    tableWindow->getUi()->table->setHorizontalHeaderLabels(header_labels);
    tableWindow->getUi()->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);




    taxWindow = new QTableWidget();
    taxWindow->setStyleSheet(tableWindow->getUi()->table->styleSheet());
    taxWindow->setColumnCount(6);
    QStringList tax_labels;
    tax_labels << "Year" << "Income" << "Deduction" << "Income-deduction" << "Tax amount" << "Pay before";
    taxWindow->setHorizontalHeaderLabels(tax_labels);
    taxWindow->horizontalHeader()->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
    taxWindow->verticalHeader()->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
    taxWindow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    taxWindow->setFixedHeight(150);
    tableWindow->getUi()->tax_layout->addWidget(taxWindow);




    opers = new my_widget(this);

    opers->getUi_type()->clear();
    opers->getUi_type()->addItem("Refill");
    opers->getUi_type()->addItem("Withdrawal");
    ui->layout_3->addWidget(opers);

    connect(ui->capital, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(ui->amount_edit, SIGNAL(textChanged(QString)), this, SLOT(onAmountEditTextChanged(QString)));
    connect(ui->time_edit, SIGNAL(textChanged(QString)), this, SLOT(onTimeEditTextChanged(QString)));
    connect(ui->time_box, SIGNAL(currentIndexChanged(int)), this,SLOT(onTimeEditIndexChanged()));
    connect(ui->percent_edit, SIGNAL(textChanged(QString)), this, SLOT(onInterestTextChanged(QString)));
}

s21_deposit::~s21_deposit()
{
    if(tableWindow) {
        delete tableWindow;
    }

    delete ui;
}

void s21_deposit::onTimeEditIndexChanged()
{
    onTimeEditTextChanged(ui->time_edit->text());
}

int s21_deposit::onAmountEditTextChanged(const QString &text)
{
    int valid = 1;

    QString correct_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}";
    QString wrong_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}";

    if((text.length() > 0 && text.toDouble() <= 0) || text.length() > 12) {
        ui->amount_edit->setStyleSheet(wrong_style);
    } else if(opers->check_fraction_length(text, 2)) {
        ui->amount_edit->setStyleSheet(wrong_style);
    } else {
        ui->amount_edit->setStyleSheet(correct_style);
        valid = 0;
    }

    return valid;
}

int s21_deposit::onTimeEditTextChanged(const QString &text)
{
    int valid = 1;

    QString correct_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}";
    QString wrong_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}";

    if(opers->containsOnlyDigits(text) == 1) {
        ui->time_edit->setStyleSheet(wrong_style);
    } else if(ui->time_box->currentIndex() == 0 && text.toInt() > 50) {
        ui->time_edit->setStyleSheet(wrong_style);
    } else if(ui->time_box->currentIndex() == 1 && text.toInt() > 600) {
        ui->time_edit->setStyleSheet(wrong_style);
    } else if(ui->time_box->currentIndex() == 2 && text.toInt() > 18250) {
        ui->time_edit->setStyleSheet(wrong_style);
    } else if(text.length() > 0 && text.toDouble() <= 0) {
        ui->time_edit->setStyleSheet(wrong_style);
    } else {
        ui->time_edit->setStyleSheet(correct_style);
        valid = 0;
    }

    return valid;
}

int s21_deposit::onInterestTextChanged(const QString &text)
{
    int valid = 1;

    QString correct_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}";
    QString wrong_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}";

    if(text.length() > 0 && (text.toDouble() <= 0 || text.toDouble() > 999) && text != "0") {
        ui->percent_edit->setStyleSheet(wrong_style);
    } else if(opers->check_fraction_length(text, 3)) {
        ui->percent_edit->setStyleSheet(wrong_style);
    } else {
        ui->percent_edit->setStyleSheet(correct_style);
        valid = 0;
    }

    return valid;
}

void s21_deposit::onCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->payment_period->removeItem(ui->payment_period->count() - 1);
    } else {
        ui->payment_period->addItem("By end term");
    }
}

void s21_deposit::init_deposit_data(deposit_init *data)
{
    data->amount = ui->amount_edit->text().toDouble();
    data->capital_time = (ui->payment_period->currentIndex() + 1) * (-1);
    data->capital = (ui->capital->isChecked()) ? CAPITAL : NOT_CAPITAL;
    data->date.day = ui->date_edit->date().day();
    data->date.month = ui->date_edit->date().month();
    data->date.year = ui->date_edit->date().year();
    data->rate = ui->percent_edit->text().toDouble();
    data->term = ui->time_edit->text().toInt();
    if(ui->time_box->currentIndex() == 2) {
        data->term_type = DAYS_PERIOD;
    } else {
        data->term_type = MONTHS_PERIOD;
        if(ui->time_box->currentIndex() == 0) {
            data->term *= 12;
        }
    }
}

void s21_deposit::add_operation(operations *op, int count)
{
    op->date = (time_data *)realloc(op->date, (count + 1) * sizeof(time_data));
    op->sum = (long double *)realloc(op->sum, (count + 1) * sizeof(long double));
    op->type = (int *)realloc(op->type, (count + 1) * sizeof(int));
    QTableWidgetItem *item1 = opers->getTableWidget()->item(count, 0);
    QDate one_date = QDate::fromString(item1->text(), "dd.MM.yyyy");
    op->date[count].day = one_date.day();
    op->date[count].month = one_date.month();
    op->date[count].year = one_date.year();
    QTableWidgetItem *item2 = opers->getTableWidget()->item(count, 1);
    op->sum[count] = item2->text().toDouble();
    QTableWidgetItem *item3 = opers->getTableWidget()->item(count, 2);
    if(item3->text() == "Refill") {
        op->type[count] = REFILL;
    } else {
        op->type[count] = WITHDRAWALS;
    }
    op->count++;
}

int s21_deposit::init_operations(operations *op)
{
    int error_code = NOT_ALLOCATED;
    op->date = (time_data *)malloc(1 * sizeof(time_data));
    int error_code_date = CHECK_NULL(op->date);
    op->sum = (long double *)malloc(1 * sizeof(long double));
    int error_code_sum = CHECK_NULL(op->sum);
    op->type = (int *)malloc(1 * sizeof(int));
    int error_code_type = CHECK_NULL(op->type);
    error_code = error_code_date + error_code_sum + error_code_type;
    op->count = 0;
    op->current = 0;
    op->min_balance = 0;
    return error_code;
}

void s21_deposit::free_memory(deposit_init data, investment *pay, operations *op)
{
    if(pay) {
        if(pay->result) {
            for(int i = 0; i < data.current + 1; i++) {
                if(pay->result[i]) {
                    free(pay->result[i]);
                    pay->result[i] = NULL;
                }
            }
            free(pay->result);
            pay->result = NULL;
        }
        if(pay->taxes) {
            for(int i = 0; i < pay->taxes_count; i++) {
                if(pay->taxes[i]) {
                    free(pay->taxes[i]);
                    pay->taxes[i] = NULL;
                }
            }
            free(pay->taxes);
            pay->taxes = NULL;
        }
        if(pay->total) {
            free(pay->total);
            pay->total = NULL;
        }
    }
    if(op) {
        if(op->date != NULL) {
            free(op->date);
            op->date = NULL;
        }
        if(op->sum != NULL) {
            free(op->sum);
            op->sum = NULL;
        }
        if(op->type != NULL) {
            free(op->type);
            op->type = NULL;
        }
    }
}

int s21_deposit::validation()
{
    int valid_data = 1;

    if(ui->amount_edit->text().length() && ui->time_edit->text().length() && ui->percent_edit->text().length()) {
        int valid_oper = 0;
        int valid_amount = onAmountEditTextChanged(ui->amount_edit->text());
        int valid_time = onTimeEditTextChanged(ui->time_edit->text());
        int valid_interest = onInterestTextChanged(ui->percent_edit->text());

        if((opers->getUi_sum()->text().length() > 0 && opers->getUi_sum()->text().toDouble() <= 0) || opers->getUi_sum()->text().length() > 12) {
            valid_oper = 1;
        } else if(opers->check_fraction_length(opers->getUi_sum()->text(), 2)) {
            valid_oper = 1;
        }

        valid_data = valid_amount + valid_time + valid_interest + valid_oper;
    }

    return valid_data;
}

void s21_deposit::on_calculate_clicked()
{
    deposit_init data;
    investment pay;
    operations op;

    if(validation() == 0) {
        init_deposit_data(&data);

        if(opers) {
            if(opers->getTableWidget()->rowCount() > 0) {
                init_operations(&op);
            }
            for(int count = 0; count < opers->getTableWidget()->rowCount(); count++) {
                add_operation(&op, count);
            }
        }

        if(opers->getTableWidget()->rowCount() == 0) {
            calculate_deposit(&data, &pay, NULL);
        } else {
            calculate_deposit(&data, &pay, &op);
        }
        if(tableWindow) {
            QPoint currentPosGlobal = this->mapToGlobal(QPoint(-800, 0));
            tableWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 800, 600);
            tableWindow->show();
            tableWindow->getUi()->table->setRowCount(data.current + 1);
            add_all_to_table(data, pay.result, pay.total);
        }
        free_memory(data, &pay, &op);
    }
}

void s21_deposit::add_item_to_table(int row, int column, QString value, int style)
{
    QTableWidgetItem *item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);
    if(style == 1) {
        item->setData(Qt::BackgroundRole, QBrush(QColor(0, 128, 0, 128)));
    } else if(style == 2) {
        item->setData(Qt::BackgroundRole, QBrush(QColor(128, 0, 0, 128)));
    }
    tableWindow->getUi()->table->setItem(row, column, item);
}

int s21_deposit::check_date_between(const QDate& previous, const QDate& current, int* oper_count)
{
    QDate one_date;
    QTableWidgetItem *redem_item = opers->getTableWidget()->item(*oper_count, 0);
    one_date = QDate::fromString(redem_item->text(), "dd.MM.yyyy");
    return (one_date >= previous && one_date < current) ? 1 : 0;
}

void s21_deposit::add_datarow_to_table(const QDate& date, QString row_head, long double **result, int iteration, int style)
{
    QTableWidgetItem *header_item = new QTableWidgetItem(row_head);
    tableWindow->getUi()->table->setVerticalHeaderItem(iteration, header_item);
    add_item_to_table(iteration, 0, date.toString("dd.MM.yyyy"), style);
    for(int j = 0; j < 4; j++) {
        add_item_to_table(iteration, j+1, QString::number(result[iteration][j], 'f', 2), style);
    }
}

void s21_deposit::add_all_to_table(deposit_init data, long double **result, long double *total)
{
    int oper_count = 0;
    time_data begin;
    begin.day = ui->date_edit->date().day();
    begin.month = ui->date_edit->date().month();
    begin.year = ui->date_edit->date().year();
    time_data last_day = determine_last_day(begin, data.term_type, data.term);
    time_data end_period = begin;


    QDate prev = ui->date_edit->date();
    QDate one_date;

    for(int i = 0; i < data.current + 1; i++) {
        add_one_period(&begin, &end_period, last_day, data.capital_time, ui->date_edit->date().day());
        QDate current_day(end_period.year, end_period.month, end_period.day);

        if(oper_count != opers->getTableWidget()->rowCount()) {
            while(check_date_between(prev, current_day, &oper_count)) {
                QTableWidgetItem *redem_item = opers->getTableWidget()->item(oper_count, 0);
                QTableWidgetItem *redem_item_2 = opers->getTableWidget()->item(oper_count, 2);
                int style = 1;
                if(redem_item_2->text() == "Withdrawals") {
                    style = 2;
                }
                one_date = QDate::fromString(redem_item->text(), "dd.MM.yyyy");
                add_datarow_to_table(one_date, "", result, i, style);
                oper_count++;
                i++;
                if(oper_count == opers->getTableWidget()->rowCount()) {
                    break;
                }
            }
        }
        add_datarow_to_table(current_day, QString::number(i + 1 - oper_count), result, i, 0);

        begin = end_period;
        prev = current_day;
    }

    for(int i = 0; i < 2; i++) {
        QString number = QString::number(static_cast<double>(total[i]), 'f', 2);
        if(i == 0) {
            tableWindow->getUi()->total_info->setText("Interest accrued: " + number);
        } else {
            tableWindow->getUi()->interest_info->setText("Balance: " + number);
        }
    }

}
