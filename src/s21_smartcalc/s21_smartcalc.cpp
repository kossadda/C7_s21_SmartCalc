#include "s21_smartcalc.h"
#include "s21_deposit.h"
#include "s21_credit.h"
#include "ui_s21_smartcalc.h"

extern "C" {
#include "unar_operation.c"
}

s21_smartcalc::s21_smartcalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_smartcalc)
    , pushButton(nullptr)
    , pushButton1(nullptr)
    , graphWindow(nullptr)
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

// Сменить окно на депозитный/кредитный калькулятор
void s21_smartcalc::change_window(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == 1) {
        newWindow = new s21_deposit();
    } else if (index == 2) {
        newWindow = new s21_credit();
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}

// Сменить окно на обычный/депозитный калькулятор
void s21_smartcalc::change_deposit(int index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == 1) {
        newWindow = new s21_smartcalc();
    } else if (index == 2) {
        newWindow = new s21_credit();
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}

// Сменить окно на обычный/кредитный калькулятор
void s21_smartcalc::change_credit(int index)
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

// Определение длины целой части числа
int s21_smartcalc::countDigits(double number)
{
    if(abs(number) < 1) {
        return 0;
    }
    int integer = static_cast<int>(number);
    std::string integer_string = std::to_string(integer);
    return integer_string.length();
}

// Добавление цифр
void s21_smartcalc::push_nums()
{
    clear_result();
    QPushButton *button = (QPushButton *)sender();
    ui->result->setText(ui->result->text() + button->text());
}

// Вычисление выражения
void s21_smartcalc::on_push_eq_clicked()
{
    if(ui->result->text() != "") {
        save_history();
        if(graphWindow->check_brackets(ui->result->text())) {
            ui->result->setText("wrong brackets");
        } else {
            double res = graphWindow->calculate(ui->result->text(), 0);
            ui->result->setText(QString::number(res, 'g', countDigits(res) + 7));
        }
        clear_after = true;
    }
}

// Сохранить выражение в историю
void s21_smartcalc::save_history() {
    if(history_count + 1 != history.size()) {
        int list_size = history.size();
        for(int i = 0; i < list_size; i++) {
            history.removeAt(history_count + 1);
        }
    }
    if(history_count >= 0) {
        QString check = history.at(history_count);
        if(check != ui->result->text()) {
            history << ui->result->text();
            history_count++;
        }
    } else {
        history << ui->result->text();
        history_count++;
    }
}

// Квадратный корень из числа
void s21_smartcalc::on_push_sqrt_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "sqrt(");
}

// Десятичный логарифм
void s21_smartcalc::on_push_log_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "log(");
}

// Натуральный логарифм
void s21_smartcalc::on_push_ln_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "ln(");
}

// Синус
void s21_smartcalc::on_push_sin_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "sin(");
}

// Косинус
void s21_smartcalc::on_push_cos_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "cos(");
}

// Тангенс
void s21_smartcalc::on_push_tan_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "tan(");
}

// Арксинус
void s21_smartcalc::on_push_asin_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "asin(");
}

// Арккосинус
void s21_smartcalc::on_push_acos_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "acos(");
}

// Арктангенс
void s21_smartcalc::on_push_atan_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "atan(");
}

// Остаток от деления
void s21_smartcalc::on_push_mod_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + " mod ");
    }
}

// Добавить открывающую скобку
void s21_smartcalc::on_push_opn_brack_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "(");
}

// Добавить закрывающую скобку
void s21_smartcalc::on_push_cls_brack_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + ")");
    }
}

// Добавить деление
void s21_smartcalc::on_push_div_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + "/");
    }
}

// Добавить умножение
void s21_smartcalc::on_push_mul_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + "*");
    }
}

// Добавить вычитание
void s21_smartcalc::on_push_sub_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + "-");
    }
}

// Добавить сумму
void s21_smartcalc::on_push_sum_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + "+");
    }
}

// Научная нотация
void s21_smartcalc::on_push_e_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "e");
}

// Добавить число Пи
void s21_smartcalc::on_push_pi_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "P");
}

// Возведение в степень
void s21_smartcalc::on_push_exp_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        ui->result->setText(ui->result->text() + "^");
    }
}

// Очистить поле ввода
void s21_smartcalc::on_push_c_clicked()
{
    ui->result->setText("");
}

// Удалить символ
void s21_smartcalc::on_push_del_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        QString temp = ui->result->text();
        temp.chop(1);
        ui->result->setText(temp);
    }
}

// Унарный минус
void s21_smartcalc::on_push_unar_clicked()
{
    if(ui->result->text().length() > 0) {
        QString field = ui->result->text();
        QByteArray byteArray = field.toUtf8();
        char* charArray = byteArray.data();
        charArray = unar_operation(charArray);
        ui->result->setText(QString::fromUtf8(charArray));
    }
}

// Установка плавающей точки
void s21_smartcalc::on_push_dot_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        QString field = ui->result->text();
        QChar last_symbol = field[field.length() - 1];
        if(last_symbol >= '0' && last_symbol <= '9') {
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
    }
}

// Отмотка истории назад
void s21_smartcalc::on_turn_back_clicked()
{
    if(history_count >= 0) {
        ui->result->setText(history[history_count]);
        history_count--;
    }
}

// Перемотка истории вперед
void s21_smartcalc::on_move_frwd_clicked()
{
    if(history_count >= -1) {
        if(history_count < history.size() - 1) {
            history_count++;
            ui->result->setText(history[history_count]);
        }
    }
}

// Открытие/закрытие окна графиков
void s21_smartcalc::on_graph_clicked()
{
    if(!graphWindow) {
        QPoint currentPosGlobal = this->mapToGlobal(QPoint(-442, 0));
        graphWindow = new graphics();
        graphWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 440, 550);
        graphWindow->show();
        connect(graphWindow, SIGNAL(graphWindowClosed()), this, SLOT(on_graphWindowClosed()));

        switch_buttons();
    } else {
        graphWindow->close();
        on_graphWindowClosed();
    }
}

// Замена кнопки на = на x и plot
void s21_smartcalc::switch_buttons()
{
    pushButton = new QPushButton("plot", this);
    createPlotButton(pushButton, 6);
    connect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_plot_clicked);

    pushButton1 = new QPushButton("x", this);
    createPlotButton(pushButton1, 5);
    connect(pushButton1, &QPushButton::clicked, this, &s21_smartcalc::on_x_clicked);

    ui->graph->setStyleSheet("QPushButton { background-color: rgb(0, 119, 171); } QPushButton:pressed { background-color: rgb(175, 97, 33); } QToolTip { background-color: rgb(30, 27, 6);	border: 1px solid white; }");
    ui->push_eq->setStyleSheet("QPushButton { background-color: rgb(30, 27, 6); color: rgb(30, 27, 6) } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
}

// Создание замещающей кнопки
void s21_smartcalc::createPlotButton(QPushButton *button, int row)
{
    button->setMinimumSize(80, 50);
    button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    button->setStyleSheet("QPushButton { background-color: rgb(0, 119, 171); font-size: 20px; } QPushButton:pressed { background-color: rgb(175, 97, 33); }");
    ui->buttons_layer->addWidget(button, row, 4, 1, 1);
}

// Закрытие окна графиков
void s21_smartcalc::on_graphWindowClosed()
{
    delete pushButton;
    pushButton = nullptr;

    delete pushButton1;
    pushButton1 = nullptr;

    ui->push_eq->setStyleSheet("QPushButton { background-color: rgb(175, 97, 33); } QPushButton:pressed { background-color: rgb(50, 50, 50);}");
    ui->graph->setStyleSheet("QPushButton { background-color: rgb(81, 44, 6); } QPushButton:pressed { background-color: rgb(50, 50, 50); } QToolTip { background-color: rgb(30, 27, 6);	border: 1px solid white; }");
    graphWindow = nullptr;
}

// Добавить x
void s21_smartcalc::on_x_clicked()
{
    clear_result();
    ui->result->setText(ui->result->text() + "x");
}

// Построить график
void s21_smartcalc::on_plot_clicked()
{
    save_history();
    graphWindow->build_plot(ui->result->text());
    graphWindow->show();
}

// Очистить поле ввода в случае предыдущих вычислений
void s21_smartcalc::clear_result()
{
    if(clear_after) {
        ui->result->setText("");
        clear_after = false;
    }
}
