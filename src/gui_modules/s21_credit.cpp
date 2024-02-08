#include "s21_credit.h"
#include "ui_s21_credit.h"
#include "ui_s21_credit_table.h"
#include "s21_smartcalc.h"
#include "s21_deposit.h"

s21_credit::s21_credit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_credit)
    , tableWindow(nullptr)
{
    ui->setupUi(this);
    tableWindow = new s21_credit_table();
    tableWindow->getUi()->info_fullsum->setVisible(false);
    tableWindow->getUi()->info_gains->setVisible(false);
    tableWindow->getUi()->info_refills->setVisible(false);
    tableWindow->getUi()->info_withdrawals->setVisible(false);
    tableWindow->getUi()->info_rate->setVisible(false);
    tableWindow->getUi()->info_tax->setVisible(false);

    early_pays = new my_widget(this);
    ui->layout_1->addWidget(early_pays);

    QListView * listView = new QListView(ui->creditBox);
    listView->setStyleSheet("QListView {background-color: white;} QListView::item {border-bottom: 5px solid white; margin:3px; background-color: white; } QListView::item:selected {border-bottom: 5px solid black; margin:3px; color: black;}");
    ui->creditBox->setView(listView);

    tableWindow->getUi()->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->date_edit->setDate(QDate::currentDate());
    connect(ui->creditBox, &QComboBox::currentTextChanged, this, &s21_credit::change_mode);

    connect(ui->amount_edit, SIGNAL(textChanged(QString)), this, SLOT(onAmountEditTextChanged(QString)));
    connect(ui->time_edit, &QLineEdit::textChanged, this, &s21_credit::onTimeEditTextChanged);
    connect(ui->time_box, SIGNAL(currentIndexChanged(int)), this,SLOT(onTimeEditIndexChanged()));
    connect(ui->percent_edit, &QLineEdit::textChanged, this, &s21_credit::onInterestTextChanged);
}

s21_credit::~s21_credit()
{
    if(tableWindow) {
        delete tableWindow;
    }
    delete ui;
}

void s21_credit::change_mode(const QString index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == "Engineer") {
        newWindow = new s21_smartcalc();
        QIcon icon(":calculator.png");
        newWindow->setWindowIcon(icon);
    } else if (index == "Deposit") {
        newWindow = new s21_deposit();
        QIcon icon(":deposit.png");
        newWindow->setWindowIcon(icon);
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}

void s21_credit::onTimeEditIndexChanged()
{
    onTimeEditTextChanged(ui->time_edit->text());
}

int s21_credit::onAmountEditTextChanged(const QString &text)
{
    int valid = WRONG_EXPR;

    static const QRegularExpression regex("^[0-9]{1,12}(\\.[0-9]{1,2})?$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->amount_edit->setStyleSheet(early_pays->correct_style);
    } else if(match.hasMatch() && text.toDouble() && !(text[0] == '0' && text[1] != '.')) {
        ui->amount_edit->setStyleSheet(early_pays->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->amount_edit->setStyleSheet(early_pays->wrong_style);
    }

    return valid;
}

int s21_credit::onTimeEditTextChanged(const QString &text)
{
    int valid = WRONG_EXPR;

    QRegularExpression regex("^[0-9]+$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->time_edit->setStyleSheet(early_pays->correct_style);
    } else if(ui->time_box->currentIndex() == 0 && text.toInt() > 50) {
        ui->time_edit->setStyleSheet(early_pays->wrong_style);
    } else if(ui->time_box->currentIndex() == 1 && text.toInt() > 600) {
        ui->time_edit->setStyleSheet(early_pays->wrong_style);
    } else if(match.hasMatch() && text.toInt() && text[0] != '0') {
        ui->time_edit->setStyleSheet(early_pays->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->time_edit->setStyleSheet(early_pays->wrong_style);
    }

    return valid;
}

int s21_credit::onInterestTextChanged(const QString &text)
{
    int valid = WRONG_EXPR;

    QRegularExpression regex("^[0-9]+(\\.[0-9]{1,3})?$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->percent_edit->setStyleSheet(early_pays->correct_style);
    } else if(match.hasMatch() && text.toDouble() && text.toDouble() <= 999 && !(text[0] == '0' && text[1] != '.')) {
        ui->percent_edit->setStyleSheet(early_pays->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->percent_edit->setStyleSheet(early_pays->wrong_style);
    }

    return valid;
}


void s21_credit::free_memory(credit_init data, payments *pay, early_pay *redemption) {
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
    if(early_pays->getTableWidget()->rowCount() > 0) {
        if(redemption->date != NULL) {
            free(redemption->date);
            redemption->date = NULL;
        }
        if(redemption->sum != NULL) {
            free(redemption->sum);
            redemption->sum = NULL;
        }
        if(redemption->type != NULL) {
            free(redemption->type);
            redemption->type = NULL;
        }
    }
}

void s21_credit::add_redemption(early_pay *redemption, my_widget *early_pays, int count) {
    redemption->date = (time_data *)realloc(redemption->date, (count + 1) * sizeof(time_data));
    redemption->sum = (long double *)realloc(redemption->sum, (count + 1) * sizeof(long double));
    redemption->type = (int *)realloc(redemption->type, (count + 1) * sizeof(int));
    QTableWidgetItem *item1 = early_pays->getTableWidget()->item(count, 0);
    QDate one_date = QDate::fromString(item1->text(), "dd.MM.yyyy");
    redemption->date[count].day = one_date.day();
    redemption->date[count].month = one_date.month();
    redemption->date[count].year = one_date.year();
    QTableWidgetItem *item2 = early_pays->getTableWidget()->item(count, 1);
    redemption->sum[count] = item2->text().toDouble();
    QTableWidgetItem *item3 = early_pays->getTableWidget()->item(count, 2);
    if(item3->text() == "Reduce term") {
        redemption->type[count] = REDUCE_TERM;
    } else {
        redemption->type[count] = REDUCE_PAY;
    }
    redemption->count++;
}

void s21_credit::init_parameters(credit_init *data, Ui::s21_credit *ui) {
    data->months = ui->time_edit->text().toInt();
    data->debt = ui->amount_edit->text().toDouble();
    data->rate = ui->percent_edit->text().toDouble();
    data->date.day = ui->date_edit->date().day();
    data->date.month = ui->date_edit->date().month();
    data->date.year = ui->date_edit->date().year();
    if(ui->annuity->isChecked()) {
        data->payment_type = ANNUITY;
    } else {
        if(ui->differentiated->isChecked()) {
            data->payment_type = DIFFERENTIATED;
        } else {
            data->payment_type = NOT_CHOSEN;
        }
    }
    if(ui->time_box->currentIndex() == 0) {
        data->months *= 12;
    }
}

int s21_credit::init_redemption(early_pay *redemption)
{
    int error_code = NOT_ALLOCATED;
    redemption->date = (time_data *)malloc(1 * sizeof(time_data));
    int error_code_date = CHECK_NULL(redemption->date);
    redemption->sum = (long double *)malloc(1 * sizeof(long double));
    int error_code_sum = CHECK_NULL(redemption->sum);
    redemption->type = (int *)malloc(1 * sizeof(int));
    int error_code_type = CHECK_NULL(redemption->type);
    error_code = error_code_date + error_code_sum + error_code_type;
    redemption->count = 0;
    redemption->current = 0;
    return error_code;
}

int s21_credit::validation()
{
    int valid_data = CORRECT_EXPR;

    if(ui->amount_edit->text().length() == 0) {
        ui->amount_edit->setStyleSheet(early_pays->wrong_style);
        ui->amount_edit->setPlaceholderText("Enter amount");
        valid_data++;
    }
    if(ui->time_edit->text().length() == 0) {
        ui->time_edit->setStyleSheet(early_pays->wrong_style);
        ui->time_edit->setPlaceholderText("Enter term");
        valid_data++;
    }
    if(ui->percent_edit->text().length() == 0) {
        ui->percent_edit->setStyleSheet(early_pays->wrong_style);
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

void s21_credit::on_calculate_clicked()
{
    payments pay;
    credit_init data;
    early_pay redemption;
    init_parameters(&data, ui);

    if(early_pays) {
        if(early_pays->getTableWidget()->rowCount() > 0) {
            init_redemption(&redemption);
        }
        for(int count = 0; count < early_pays->getTableWidget()->rowCount(); count++) {
            add_redemption(&redemption, early_pays, count);
        }
    }
    if(!validation() && data.payment_type != NOT_CHOSEN) {
        if(early_pays->getTableWidget()->rowCount() == 0) {
            calculate_credit(&data, &pay, NULL);
        } else {
            calculate_credit(&data, &pay, &redemption);
        }

        if(tableWindow) {
            QPoint currentPosGlobal = this->mapToGlobal(QPoint(-800, 0));
            tableWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 800, 600);
            tableWindow->show();
            tableWindow->getUi()->table->setRowCount(data.current + 1);
            add_all_to_table(data.current + 1, pay.result, pay.total);
        }
        free_memory(data, &pay, &redemption);
    }
}

void s21_credit::add_item_to_table(int row, int column, QString value, int style) {
    QTableWidgetItem *item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);
    if(style) {
        item->setData(Qt::BackgroundRole, QBrush(QColor(0, 128, 0, 128)));
    }
    tableWindow->getUi()->table->setItem(row, column, item);
}

int s21_credit::check_date_between(const QDate& previous, const QDate& current, int* redemp_count) {
    QDate one_date;
    QTableWidgetItem *redem_item = early_pays->getTableWidget()->item(*redemp_count, 0);
    one_date = QDate::fromString(redem_item->text(), "dd.MM.yyyy");
    return (one_date >= previous && one_date < current) ? 1 : 0;
}

void s21_credit::add_datarow_to_table(const QDate& date, QString row_head, long double **result, int iteration, int style) {
    QTableWidgetItem *header_item = new QTableWidgetItem(row_head);
    tableWindow->getUi()->table->setVerticalHeaderItem(iteration, header_item);
    add_item_to_table(iteration, 0, date.toString("dd.MM.yyyy"), style);
    for(int j = 0; j < 4; j++) {
        add_item_to_table(iteration, j+1, QString::number(result[iteration][j], 'f', 2), style);
    }
}

void s21_credit::add_all_to_table(int months, long double **result, long double *total) {
    int redemp_count = 0;
    int first_date = ui->date_edit->date().day();
    QDate prev = ui->date_edit->date();
    QDate current_day = ui->date_edit->date().addMonths(1);
    QDate one_date;

    for(int i = 0; i < months; i++) {
        if(redemp_count != early_pays->getTableWidget()->rowCount()) {
            while(check_date_between(prev, current_day, &redemp_count)) {
                QTableWidgetItem *redem_item = early_pays->getTableWidget()->item(redemp_count, 0);
                one_date = QDate::fromString(redem_item->text(), "dd.MM.yyyy");
                add_datarow_to_table(one_date, "", result, i, 1);
                redemp_count++;
                i++;
                if(redemp_count == early_pays->getTableWidget()->rowCount()) {
                    break;
                }
            }
        }
        add_datarow_to_table(current_day, QString::number(i + 1 - redemp_count), result, i, 0);

        prev = current_day;
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
