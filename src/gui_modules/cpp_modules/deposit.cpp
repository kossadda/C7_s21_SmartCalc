#include "./../include/deposit.h"
#include "./../include/smartcalc.h"
#include "./../include/credit.h"
#include "./ui_deposit.h"
#include "./ui_credit_table.h"

deposit::deposit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deposit)
{
    ui->setupUi(this);
    ui->payment_period->setCurrentIndex(2);

    tableWindow = new credit_table();
    QIcon icon(":table.png");
    tableWindow->setWindowIcon(icon);

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

    ui->date_edit->setDate(QDate::currentDate());

    opers = new my_widget(this);

    opers->getUi_type()->clear();
    opers->getUi_type()->addItem("Refill");
    opers->getUi_type()->addItem("Withdrawal");
    ui->layout_3->addWidget(opers);

    QString list_style = "QListView {background-color: white;} QListView::item {border-bottom: 5px solid white; margin:3px; background-color: white; } QListView::item:selected {border-bottom: 5px solid black; margin:3px; color: black;}";
    QListView *listView = new QListView(ui->depositBox);
    listView->setStyleSheet(list_style);
    ui->depositBox->setView(listView);

    connect(ui->capital, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(ui->amount_edit, SIGNAL(textChanged(QString)), this, SLOT(onAmountEditTextChanged(QString)));
    connect(ui->time_edit, SIGNAL(textChanged(QString)), this, SLOT(onTimeEditTextChanged(QString)));
    connect(ui->time_box, SIGNAL(currentIndexChanged(int)), this,SLOT(onTimeEditIndexChanged()));
    connect(ui->percent_edit, SIGNAL(textChanged(QString)), this, SLOT(onInterestTextChanged(QString)));
    connect(ui->depositBox, &QComboBox::currentTextChanged, this, &deposit::change_mode);
}

deposit::~deposit()
{
    if(tableWindow) {
        delete tableWindow;
    }

    delete ui;
}

void deposit::change_mode(const QString index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == "Engineer") {
        newWindow = new smartcalc();
        QIcon icon(":calculator.png");
        newWindow->setWindowIcon(icon);
    } else if (index == "Credit") {
        newWindow = new credit();
        QIcon icon(":credit.png");
        newWindow->setWindowIcon(icon);
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}

void deposit::onTimeEditIndexChanged()
{
    onTimeEditTextChanged(ui->time_edit->text());
}

int deposit::onAmountEditTextChanged(const QString &text)
{
    int valid = WRONG_EXPR;

    static const QRegularExpression regex("^[0-9]{1,12}(\\.[0-9]{1,2})?$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->amount_edit->setStyleSheet(opers->correct_style);
    } else if(match.hasMatch() && text.toDouble() && !(text[0] == '0' && text[1] != '.')) {
        ui->amount_edit->setStyleSheet(opers->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->amount_edit->setStyleSheet(opers->wrong_style);
    }

    return valid;
}

int deposit::onTimeEditTextChanged(const QString &text)
{
    int valid = WRONG_EXPR;

    QRegularExpression regex("^[0-9]+$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->time_edit->setStyleSheet(opers->correct_style);
    } else if(ui->time_box->currentIndex() == 0 && text.toInt() > 50) {
        ui->time_edit->setStyleSheet(opers->wrong_style);
    } else if(ui->time_box->currentIndex() == 1 && text.toInt() > 600) {
        ui->time_edit->setStyleSheet(opers->wrong_style);
    } else if(ui->time_box->currentIndex() == 2 && text.toInt() > 18250) {
        ui->time_edit->setStyleSheet(opers->wrong_style);
    } else if(match.hasMatch() && text.toInt() && text[0] != '0') {
        ui->time_edit->setStyleSheet(opers->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->time_edit->setStyleSheet(opers->wrong_style);
    }

    return valid;
}

int deposit::onInterestTextChanged(const QString &text)
{
    int valid = WRONG_EXPR;

    QRegularExpression regex("^[0-9]+(\\.[0-9]{1,3})?$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->percent_edit->setStyleSheet(opers->correct_style);
    } else if(match.hasMatch() && text.toDouble() && text.toDouble() <= 999 && !(text[0] == '0' && text[1] != '.')) {
        ui->percent_edit->setStyleSheet(opers->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->percent_edit->setStyleSheet(opers->wrong_style);
    }

    return valid;
}

void deposit::onCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->payment_period->removeItem(ui->payment_period->count() - 1);
    } else {
        ui->payment_period->addItem("By end term");
    }
}

void deposit::init_deposit_data(deposit_init *data)
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

void deposit::add_operation(operations *op, int count)
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

int deposit::init_operations(operations *op)
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

void deposit::free_memory(deposit_init data, investment *pay, operations *op)
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
    if(opers->getTableWidget()->rowCount() > 0) {
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
}

int deposit::validation()
{
    int valid_data = CORRECT_EXPR;

    if(ui->amount_edit->text().length() == 0) {
        ui->amount_edit->setStyleSheet(opers->wrong_style);
        ui->amount_edit->setPlaceholderText("Enter amount");
        valid_data++;
    }
    if(ui->time_edit->text().length() == 0) {
        ui->time_edit->setStyleSheet(opers->wrong_style);
        ui->time_edit->setPlaceholderText("Enter term");
        valid_data++;
    }
    if(ui->percent_edit->text().length() == 0) {
        ui->percent_edit->setStyleSheet(opers->wrong_style);
        ui->percent_edit->setPlaceholderText("Enter rate");
        valid_data++;
    }
    if(valid_data == CORRECT_EXPR) {
        int valid_amount = onAmountEditTextChanged(ui->amount_edit->text());
        int valid_time = onTimeEditTextChanged(ui->time_edit->text());
        int valid_interest = onInterestTextChanged(ui->percent_edit->text());

        valid_data = valid_amount + valid_time + valid_interest;
        ui->amount_edit->setPlaceholderText("");
        ui->time_edit->setPlaceholderText("");
        ui->percent_edit->setPlaceholderText("");
    }

    return valid_data;
}

void deposit::on_calculate_clicked()
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
            add_all_to_table(data, &pay);
        }
        free_memory(data, &pay, &op);
    }
}

void deposit::add_item_to_table(int row, int column, QString value, int style)
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

int deposit::check_date_between(const QDate& previous, const QDate& current, int* oper_count)
{
    QDate one_date;
    QTableWidgetItem *redem_item = opers->getTableWidget()->item(*oper_count, 0);
    one_date = QDate::fromString(redem_item->text(), "dd.MM.yyyy");
    return (one_date >= previous && one_date < current) ? 1 : 0;
}

void deposit::add_datarow_to_table(const QDate& date, QString row_head, long double **result, int iteration, int style)
{
    QTableWidgetItem *header_item = new QTableWidgetItem(row_head);
    tableWindow->getUi()->table->setVerticalHeaderItem(iteration, header_item);
    add_item_to_table(iteration, 0, date.toString("dd.MM.yyyy"), style);
    for(int j = 0; j < 4; j++) {
        add_item_to_table(iteration, j+1, QString::number(result[iteration][j], 'f', 2), style);
    }
}

void deposit::add_all_to_table(deposit_init data, investment *pay)
{
    long double all_tax = 0;
    long double all_refill = 0;
    long double all_withdrawals = 0;
    long double deposit_with_profit = 0;
    long double effective_rate = 0;
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
                QTableWidgetItem *redem_item_1 = opers->getTableWidget()->item(oper_count, 1);
                QTableWidgetItem *redem_item_2 = opers->getTableWidget()->item(oper_count, 2);
                int style = 1;
                if(redem_item_2->text() == "Withdrawal") {
                    style = 2;
                    all_withdrawals += redem_item_1->text().toDouble();
                } else {
                    all_refill += redem_item_1->text().toDouble();
                }
                one_date = QDate::fromString(redem_item->text(), "dd.MM.yyyy");
                add_datarow_to_table(one_date, "", pay->result, i, style);
                oper_count++;
                i++;
                if(oper_count == opers->getTableWidget()->rowCount()) {
                    break;
                }
            }
        }
        add_datarow_to_table(current_day, QString::number(i + 1 - oper_count), pay->result, i, 0);

        begin = end_period;
        prev = current_day;
    }

    for(int i = 0; i < 2; i++) {
        QString number = QString::number(static_cast<double>(pay->total[i]), 'f', 2);
        if(i == 0) {
            tableWindow->getUi()->debt_info->setText("Interest accrued: " + number);
        } else {
            tableWindow->getUi()->interest_info->setText("Balance: " + number);
        }
    }

    taxWindow->setRowCount(pay->taxes_count);
    for(int i = 0; i < pay->taxes_count; i++) {
        all_tax += pay->taxes[i][4];
        for(int j = 0; j < 6; j++) {
            QString item_text;
            if(j == 5) {
                if(pay->taxes[i][4]) {
                    item_text = "Pay by 01.12." + QString::number(static_cast<double>(pay->taxes[i][0] + 1), 'f', 0);
                }
            } else {
                item_text = QString::number(static_cast<double>(pay->taxes[i][j]), 'f', (!j) ? 0 : 2);
            }
            QTableWidgetItem *tax_item = new QTableWidgetItem(item_text);
            tax_item->setTextAlignment(Qt::AlignCenter);
            taxWindow->setItem(i, j, tax_item);
        }
    }
    if(data.capital) {
        deposit_with_profit = pay->total[1];
        QDate end_deposit(last_day.year, last_day.month, last_day.day);
        effective_rate = pay->total[0] / ui->amount_edit->text().toDouble() * 365 / ui->date_edit->date().daysTo(end_deposit) * 100;
        tableWindow->getUi()->total_info->setText("Effective rate: " + QString::number(static_cast<double>(effective_rate), 'f', 2) + " %");
        tableWindow->getUi()->total_info->setVisible(true);
    } else {
        deposit_with_profit = pay->total[0] + pay->total[1] + all_withdrawals;
        tableWindow->getUi()->total_info->setVisible(false);
    }
    tableWindow->getUi()->info_rate->setText("Tax: " + QString::number(static_cast<double>(all_tax), 'f', 2));
    tableWindow->getUi()->info_gains->setText("Capital gains: " + QString::number(static_cast<double>(pay->total[0]/ui->amount_edit->text().toDouble()*100), 'f', 2) + " %");
    tableWindow->getUi()->info_tax->setText("Gain with tax: " + QString::number(static_cast<double>(pay->total[0] - all_tax), 'f', 2));
    tableWindow->getUi()->info_refills->setText("Refills: " + QString::number(static_cast<double>(all_refill), 'f', 2));
    tableWindow->getUi()->info_withdrawals->setText("Withdrawals: " + QString::number(static_cast<double>(all_withdrawals), 'f', 2));
    tableWindow->getUi()->info_fullsum->setText("Amount+interest: " + QString::number(static_cast<double>(deposit_with_profit), 'f', 2));
}
