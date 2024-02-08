#include "./../include/my_widget.h"
#include "./ui_my_widget.h"

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
    correct_style("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}"),
    wrong_style("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 0, 0, 100);color:black;border: 1px solid black;}"),
    ui(new Ui::my_widget)
{
    ui->setupUi(this);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->horizontalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0);");
    ui->table->verticalHeader()->setStyleSheet("background-color: rgb(226, 226, 226); color: rgb(0, 0, 0);");
    ui->table->setSortingEnabled(true);
    ui->table->horizontalHeader()->setSortIndicatorShown(false);
    ui->table->horizontalHeader()->setSectionsClickable(false);
    ui->table->sortByColumn(0, Qt::AscendingOrder);
    ui->pay_date->setDate(QDate::currentDate());

    connect(ui->pay_sum, SIGNAL(textChanged(QString)), this, SLOT(onOperEditTextChanged(QString)));
}

my_widget::~my_widget()
{
    delete ui;
}

void my_widget::on_add_to_table_clicked()
{
    if(ui->pay_sum->text().length() && onOperEditTextChanged(ui->pay_sum->text()) == 0) {
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

int my_widget::onOperEditTextChanged(const QString &text)
{
    int valid = 1;

    QRegularExpression regex("^[0-9]{1,12}(\\.[0-9]{1,2})?$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        ui->pay_sum->setStyleSheet(this->correct_style);
    } else if(match.hasMatch() && text.toDouble() && text[0] != '0') {
        ui->pay_sum->setStyleSheet(this->correct_style);
        valid = CORRECT_EXPR;
    } else {
        ui->pay_sum->setStyleSheet(this->wrong_style);
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

QLineEdit* my_widget::getUi_sum()
{
    return ui->pay_sum;
}
