#include "s21_smartcalc.h"
#include "s21_deposit.h"
#include "s21_credit.h"
#include "ui_s21_smartcalc.h"

extern "C" {
#include "../calculations/functions/main.c"
#include "../calculations/functions/validation.c"
#include "../calculations/functions/notation.c"
#include "../calculations/functions/checks.c"
#include "../calculations/functions/comparison.c"
#include "../calculations/functions/math_operations.c"
#include "../calculations/functions/cpp_addition/unar_operation.c"
}

s21_smartcalc::s21_smartcalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_smartcalc)
{
    ui->setupUi(this);

    connect(ui->push_0, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_1, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_2, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_3, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_4, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_5, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_6, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_7, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_8, SIGNAL(clicked()), this, SLOT(push_nums()));
    connect(ui->push_9, SIGNAL(clicked()), this, SLOT(push_nums()));

    ui->comboBox->addItem("Инженерный");
    ui->comboBox->addItem("Депозитный");
    ui->comboBox->addItem("Кредитный");

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(change_window(int)));
}

s21_smartcalc::~s21_smartcalc()
{
    delete ui;
}

int s21_smartcalc::countDigits(double number)
{
    int integer = static_cast<int>(number);
    std::string integer_string = std::to_string(integer);
    return integer_string.length();
}

void s21_smartcalc::change_window(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    if(index == 1) {
        this->close();
        s21_deposit *smartWindow = new s21_deposit();
        smartWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        smartWindow->show();
    } else if(index == 2) {
        this->close();
        s21_credit *smartWindow = new s21_credit();
        smartWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        smartWindow->show();
    }
}

void s21_smartcalc::change_deposit(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    if(index == 1) {
        this->close();
        s21_smartcalc *depositWindow = new s21_smartcalc();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    } else if(index == 2) {
        this->close();
        s21_credit *depositWindow = new s21_credit();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    }
}

void s21_smartcalc::change_credit(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    if(index == 1) {
        this->close();
        s21_smartcalc *depositWindow = new s21_smartcalc();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    } else if(index == 2) {
        this->close();
        s21_deposit *depositWindow = new s21_deposit();
        depositWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        depositWindow->show();
    }
}

void s21_smartcalc::push_nums()
{
    QPushButton *button = (QPushButton *)sender();
    ui->result->setText(ui->result->text() + button->text());
}

void s21_smartcalc::on_push_eq_clicked()
{
    QByteArray byteArray = ui->result->text().toUtf8();
    char* charArray = byteArray.data();
    double res = calculation(charArray);
    ui->result->setText(QString::number(res, 'g', countDigits(res) + 7));
}


void s21_smartcalc::on_push_sqrt_clicked()
{
    ui->result->setText(ui->result->text() + "sqrt(");
}


void s21_smartcalc::on_push_log_clicked()
{
    ui->result->setText(ui->result->text() + "log(");
}


void s21_smartcalc::on_push_ln_clicked()
{
    ui->result->setText(ui->result->text() + "ln(");
}


void s21_smartcalc::on_push_sin_clicked()
{
    ui->result->setText(ui->result->text() + "sin(");
}


void s21_smartcalc::on_push_cos_clicked()
{
    ui->result->setText(ui->result->text() + "cos(");
}


void s21_smartcalc::on_push_tan_clicked()
{
    ui->result->setText(ui->result->text() + "tan(");
}


void s21_smartcalc::on_push_asin_clicked()
{
    ui->result->setText(ui->result->text() + "asin(");
}


void s21_smartcalc::on_push_acos_clicked()
{
    ui->result->setText(ui->result->text() + "acos(");
}


void s21_smartcalc::on_push_atan_clicked()
{
    ui->result->setText(ui->result->text() + "atan(");
}


void s21_smartcalc::on_push_mod_clicked()
{
    ui->result->setText(ui->result->text() + " mod ");
}


void s21_smartcalc::on_push_opn_brack_clicked()
{
    ui->result->setText(ui->result->text() + "(");
}


void s21_smartcalc::on_push_cls_brack_clicked()
{
    ui->result->setText(ui->result->text() + ")");
}


void s21_smartcalc::on_push_div_clicked()
{
    ui->result->setText(ui->result->text() + "/");
}


void s21_smartcalc::on_push_mul_clicked()
{
    ui->result->setText(ui->result->text() + "*");
}


void s21_smartcalc::on_push_sub_clicked()
{
    ui->result->setText(ui->result->text() + "-");
}


void s21_smartcalc::on_push_sum_clicked()
{
    ui->result->setText(ui->result->text() + "+");
}


void s21_smartcalc::on_push_e_clicked()
{
    ui->result->setText(ui->result->text() + "2.71828");
}


void s21_smartcalc::on_push_pi_clicked()
{
    ui->result->setText(ui->result->text() + "3.14159");
}


void s21_smartcalc::on_push_exp_clicked()
{
    ui->result->setText(ui->result->text() + "^");
}


void s21_smartcalc::on_push_c_clicked()
{
    ui->result->setText("");
}


void s21_smartcalc::on_push_del_clicked()
{
    QString temp = ui->result->text();
    temp.chop(1);
    ui->result->setText(temp);
}


void s21_smartcalc::on_push_unar_clicked()
{
    QString field = ui->result->text();
    QByteArray byteArray = field.toUtf8();
    char* charArray = byteArray.data();
    charArray = unar_operation(charArray);
    ui->result->setText(QString::fromUtf8(charArray));
}


void s21_smartcalc::on_push_dot_clicked()
{
    QString field = ui->result->text();
    QByteArray byteArray = field.toUtf8();
    char* charArray = byteArray.data();
    int position = number_position(charArray, field.length() - 1);
    int dot_find = 0;
    for(int i = position; i < field.length(); i++) {
        if(field.indexOf('.', i) != -1) {
            dot_find = 1;
        }
    }
    if(!dot_find) {
        ui->result->setText(field + ".");
    }
}

