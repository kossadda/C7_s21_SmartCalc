#include "my_widget.h"
#include "ui_my_widget.h"

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
    ui->table->horizontalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0);");
    ui->table->verticalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0);");
    ui->table->setSortingEnabled(true);
    ui->table->sortByColumn(0, Qt::AscendingOrder);
    ui->pay_date->setDate(QDate::currentDate());

    connect(ui->pay_sum, SIGNAL(textChanged(QString)), this, SLOT(onOperEditTextChanged(QString)));
}

my_widget::~my_widget()
{
    delete ui;
}

int my_widget::containsOnlyDigits(const QString &str)
{
    int no_digits = 0;

    for (const QChar &ch : str) {
        if (!ch.isDigit()) {
            no_digits = 1;
        }
    }

    return no_digits;
}

void my_widget::on_add_to_table_clicked()
{
    if(ui->pay_sum->text().length() && ui->pay_sum->text().toDouble() > 0) {
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

int my_widget::check_fraction_length(const QString &text, int length)
{
    int normal_length = 0;

    int dot = 0;
    int after_dot_count = 0;

    for (const QChar &ch : text) {
        if (ch == '.') {
            dot = 1;
        } else if(dot == 1) {
            after_dot_count++;
        }
    }

    if(after_dot_count > length || (text.length() > 0 && text[0] == '.')) {
        normal_length = 1;
    }

    return normal_length;
}

int my_widget::onOperEditTextChanged(const QString &text)
{
    int valid = 1;

    QString correct_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}";
    QString wrong_style = "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}";

    if((text.length() > 0 && text.toDouble() <= 0) || text.length() > 12) {
        ui->pay_sum->setStyleSheet(wrong_style);
    } else if(check_fraction_length(text, 2)) {
        ui->pay_sum->setStyleSheet(wrong_style);
    } else {
        ui->pay_sum->setStyleSheet(correct_style);
        valid = 0;
    }

    return valid;
}

void my_widget::on_clean_table_clicked()
{
    ui->table->setRowCount(ui->table->rowCount() - 1);
}

QTableWidget* my_widget::getTableWidget()
{
    return ui->table;
}

QComboBox* my_widget::getUi_type()
{
    return ui->pay_type;
}
