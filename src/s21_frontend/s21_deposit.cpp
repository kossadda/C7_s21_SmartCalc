#include "s21_deposit.h"
#include "ui_s21_deposit.h"
// #include "s21_smartcalc.h"
// #include "s21_credit.h"


s21_deposit::s21_deposit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_deposit)
{
    ui->setupUi(this);

    opers = new my_widget(this);
    opers->getUi()->clear();
    opers->getUi()->addItem("Refill");
    opers->getUi()->addItem("Withdrawal");
    ui->layout_3->addWidget(opers);

    connect(ui->depositBox, SIGNAL(activated(int)), this, SLOT(change_deposit(int)));
    connect(ui->capital, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(ui->amount_edit, SIGNAL(textChanged(const QString&)), this, SLOT(onAmountEditTextChanged(const QString&)));
    connect(ui->time_edit, SIGNAL(textChanged(const QString&)), this, SLOT(onAmountEditTextChanged(const QString&)));
}

void s21_deposit::onAmountEditTextChanged(const QString &text)
{
    QString correct_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}";
    QString wrong_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}";

    if(text.toDouble() <= 0) {
        ui->amount_edit->setStyleSheet(wrong_style);
        ui->amount_edit->setPlaceholderText("Enter correct amount");
    } else {
        ui->amount_edit->setStyleSheet(correct_style);
        ui->amount_edit->setPlaceholderText("");
    }
}

// void s21_deposit::onAmountEditTextChanged(const QString &text)
// {
//     QString correct_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}";
//     QString wrong_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}";

//     if(text.toDouble() <= 0) {
//         ui->amount_edit->setStyleSheet(wrong_style);
//         ui->amount_edit->setPlaceholderText("Enter correct amount");
//     } else {
//         ui->amount_edit->setStyleSheet(correct_style);
//         ui->amount_edit->setPlaceholderText("");
//     }
// }

void s21_deposit::onCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->payment_period->removeItem(ui->payment_period->count() - 1);
    } else {
        ui->payment_period->addItem("By end term");
    }
}

s21_deposit::~s21_deposit()
{
    delete ui;
}

void s21_deposit::change_deposit(int index)
{
    // QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    // QSize currentSize = this->size();
    // QMainWindow* newWindow = nullptr;

    // if (index == 1) {
    //     newWindow = new s21_smartcalc();
    // } else if (index == 2) {
    //     newWindow = new s21_credit();
    // }

    // if (newWindow) {
    //     this->close();
    //     newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
    //     newWindow->show();
    // }
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
    return error_code;
}

void s21_deposit::free_memory(deposit_init data, investment *pay, operations *op)
{
    for(int i = 0; i < data.current + 1; i++) {
        if(pay->result[i]) {
            free(pay->result[i]);
            pay->result[i] = NULL;
        }
    }
    if(pay->result) {
        free(pay->result);
        pay->result = NULL;
    }
    if(pay->total) {
        free(pay->total);
        pay->total = NULL;
    }
    if(opers->getTableWidget()->rowCount() > 0) {
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
    int valid_data = 0;


    // else if(ui->time_edit->text().toDouble() <= 0) {
    //     valid_data = 1;
    //     ui->time_edit
    //     QMessageBox::information(this, "Validation", "Enter a valid date.");
    // } else if(! opers->containsOnlyDigits(ui->percent_edit->text()) && ui->percent_edit->text().toDouble() <= 0) {
    //     valid_data = 1;
    //     QMessageBox::information(this, "Validation", "Enter the correct interest rate.");
    // }


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


        free_memory(data, &pay, &op);
    }
}

