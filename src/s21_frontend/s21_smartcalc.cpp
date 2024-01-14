#include "s21_smartcalc.h"
#include "ui_s21_smartcalc.h"

s21_smartcalc::s21_smartcalc(QWidget *parent)
    : QMainWindow(parent)
    , valid(0)
    , font_size(35)
    , ui(new Ui::s21_smartcalc)
    , pushButton(nullptr)
    , pushButton1(nullptr)
    , var(nullptr)
    , graphWindow(nullptr)
    , listWidget(nullptr)
    , correct_var(0)
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

    ui->history_info_label->setVisible(false);
    ui->history_widget->setVisible(false);

    connect(this, &s21_smartcalc::resized, this, &s21_smartcalc::onResized);
    connect(ui->result, &QLineEdit::textChanged, this, &s21_smartcalc::onCheckExpr);
}

void s21_smartcalc::on_actionVarChanged(const QString &text)
{
    static const QRegularExpression regex("^[0-9]{1,12}(\\.[0-9]{1,12})?$");
    QRegularExpressionMatch match = regex.match(text);

    if(text.length() == 0) {
        var->setStyleSheet(QString("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}"));
        correct_var = NO;
        var->setPlaceholderText("x = ");
    } else if(match.hasMatch() && (!text.toDouble() || (text.toDouble() && !(text[0] == '0' && text[1] != '.')))) {
        var->setStyleSheet(QString("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}"));
        correct_var = YES;
    } else {
        var->setStyleSheet(QString("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 50, 50, 150);color:black;border: 1px solid black;}"));
        correct_var = NO;
    }
}

void s21_smartcalc::onCheckExpr(const QString &text)
{
    int wrong_expression = NO;

    std::string str = text.toStdString();
    char *char_str = (char *)str.c_str();
    char c_str[512];
    strcpy(c_str, char_str);

    wrong_expression = graphWindow->check_symbol(text, '(', ')');
    if(wrong_expression == NO) {
        wrong_expression = str_without_spaces(c_str);
    }
    if(wrong_expression == NO) {
        input_varibles(c_str, 0);
        wrong_expression = func_substitution(c_str);
    }
    if(wrong_expression == NO) {
        ui->result->setStyleSheet(QString("background-color: rgb(30, 27, 6); font-size: %1px; border: 0px;color: rgb(255, 255, 255);").arg(font_size));
        valid = YES;
    } else {
        ui->result->setStyleSheet(QString("background-color: rgb(30, 27, 6); font-size: %1px; border: 0px;color: rgba(255, 50, 50, 150);").arg(font_size));
        valid = NO;
    }
}

void s21_smartcalc::onResized(const QSize &newSize)
{
    int maxWidth = 700;

    int width = newSize.width();
    int height = newSize.height();

    double scaleFactor = std::min(width / 1500.0, height / 1400.0);
    font_size = static_cast<int>(69 * scaleFactor);
    font_size = (font_size < 35) ? 35 : font_size;
    if(valid == NO) {
        ui->result->setStyleSheet(QString("background-color: rgb(30, 27, 6); font-size: %1px; border: 0px;color: rgba(255, 50, 50, 150);").arg(font_size));
    } else {
        ui->result->setStyleSheet(QString("background-color: rgb(30, 27, 6); font-size: %1px; border: 0px;color: rgb(255, 255, 255);").arg(font_size));
    }

    for(int i = 0; i < ui->buttons->count(); i++) {
        QLayoutItem *button_item = ui->buttons->itemAt(i);

        if(button_item) {
            if(QWidget *widget = button_item->widget()) {
                if(QPushButton *butt = qobject_cast<QPushButton*>(widget)) {
                    QString style = butt->styleSheet();
                    while(style.right(1) != ":") {
                        style.chop(1);
                    }
                    style += " " + QString::number((font_size > 40) ? 21 : font_size - 19) + "px;}";

                    butt->setStyleSheet(style);
                }
            }
        }
    }
    if (newSize.width() > maxWidth && !ui->history_info_label->isVisible()) {
        ui->history_info_label->setVisible(true);
        ui->history_widget->setVisible(true);
    } else if (newSize.width() <= maxWidth && ui->history_info_label->isVisible()) {
        ui->history_info_label->setVisible(false);
        ui->history_widget->setVisible(false);
    }
}

void s21_smartcalc::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    emit resized(event->size());
}

s21_smartcalc::~s21_smartcalc()
{
    if(pushButton) delete pushButton;
    if(pushButton1) delete pushButton1;
    if(var) delete var;
    delete ui;
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

// Вычисление выражения
void s21_smartcalc::on_push_eq_clicked()
{
    if(ui->result->text() != "" && valid == YES) {
        save_history();
        if(ui->result->text().count('x') > 0 && (!graphWindow && !var)) {
            ui->result->setText("use variable mode");
            ui->result->setStyleSheet(QString("background-color: rgb(30, 27, 6); font-size: %1px; border: 0px;color: rgba(50, 255, 50, 150);").arg(font_size));
        } else if(!graphWindow && var && correct_var == NO) {
            var->setPlaceholderText("Enter x");
            var->setStyleSheet(QString("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgba(255, 50, 50, 150);color:black;border: 1px solid black;}"));
        } else {
            double var_point = 0;
            if(var) {
                if(var->text().length() > 0) {
                    var_point = var->text().toDouble();
                }
            }
            double res = graphWindow->calculate(ui->result->text(), var_point);
            if(res != __DBL_MAX__) {
                ui->result->setText(QString::number(res, 'g', countDigits(res) + 7));
            }
        }
        clear_after = true;
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
                add(".");
            }
        }
    }
}

// Открытие/закрытие окна графиков
void s21_smartcalc::on_graph_clicked()
{
    if(!graphWindow) {
        QPoint currentPosGlobal = this->mapToGlobal(QPoint(-550, 0));
        graphWindow = new graphics();
        graphWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 550, 550);
        graphWindow->show();
        connect(graphWindow, SIGNAL(graphWindowClosed()), this, SLOT(on_graphWindowClosed()));

        change_color(ui->graph, "blue_graph");
        if(!var) {
            switch_buttons("plot", "x");
            change_color(pushButton1, "blue");
        }
        change_color(pushButton, "blue");
        pushButton->setText("plot");
        disconnect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_push_eq_clicked);
        connect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_actionPlotTriggered);
    } else {
        graphWindow->close();
    }
}

// События при закрытии окна графиков
void s21_smartcalc::on_graphWindowClosed()
{
    if(!var) {
        if(pushButton) {
            delete pushButton;
            pushButton = nullptr;
        }
        if(pushButton1) {
            delete pushButton1;
            pushButton1 = nullptr;
        }
        change_color(ui->push_eq, "orange_eq");
    } else {
        disconnect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_actionPlotTriggered);
        connect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_push_eq_clicked);
        change_color(pushButton, "green");
        pushButton->setText("=");
    }
    change_color(ui->graph, "orange");
    if (graphWindow) {
        graphWindow = nullptr;
    }
}

// Замена кнопки на = на x и plot
void s21_smartcalc::switch_buttons(QString name1, QString name2)
{
    if(!pushButton) {
        pushButton = new QPushButton(name1, this);
        createPlotButton(pushButton, 6);
        if(!graphWindow && var) {
            connect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_push_eq_clicked);
        } else {
            connect(pushButton, &QPushButton::clicked, this, &s21_smartcalc::on_actionPlotTriggered);
        }
    }
    if(!pushButton1) {
        pushButton1 = new QPushButton(name2, this);
        createPlotButton(pushButton1, 5);
        connect(pushButton1, &QPushButton::clicked, this, &s21_smartcalc::on_actionVarTriggered);
    }
    change_color(ui->push_eq, "black_eq");
}

// Создание замещающей кнопки
void s21_smartcalc::createPlotButton(QPushButton *button, int row)
{
    button->setMinimumSize(80, 50);
    button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->buttons->addWidget(button, row, 4, 1, 1);
}

// Построить график
void s21_smartcalc::on_actionPlotTriggered()
{
    if(ui->result->text().length() > 0 && valid == YES) {
        save_history();
        graphWindow->build_plot(ui->result->text());
        graphWindow->show();
        clear_after = true;
    }
}

// Добавить поле ввода переменной
void s21_smartcalc::on_variable_clicked()
{
    if(!var) {
        var = new QLineEdit(this);
        var->setFixedHeight(35);
        var->setMinimumWidth(90);
        var->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        var->setStyleSheet("QLineEdit {border-radius: 10px;padding: 0 8px;background-color: rgb(226, 226, 226);color:black;border: 1px solid black;}");
        var->setPlaceholderText("x =");
        change_color(ui->variable, "green_var");
        if(!graphWindow) {
            switch_buttons("=", "x");
            change_color(pushButton, "green");
        }
        change_color(pushButton1, "green");
        ui->settings->insertWidget(2, var);
        connect(var, &QLineEdit::textChanged, this, &s21_smartcalc::on_actionVarChanged);
    } else {
        disconnect(var, &QLineEdit::textChanged, this, &s21_smartcalc::on_actionVarChanged);
        change_color(ui->variable, "orange");
        delete var;
        var = nullptr;
        if(!graphWindow) {
            delete pushButton;
            pushButton = nullptr;

            delete pushButton1;
            pushButton1 = nullptr;
            change_color(ui->push_eq, "orange_eq");
        } else {
            change_color(pushButton1, "blue");
        }
    }
}

// Выбор цвета замещающих кнопок
void s21_smartcalc::change_color(QPushButton *button, QString color)
{
    QString styleSheet = ui->push_0->styleSheet();
    QRegularExpression regex("font-size:\\s*(\\d+)px;");
    QRegularExpressionMatch match = regex.match(styleSheet);
    int fontSize = match.captured(1).toInt();
    if(color == "orange_eq") {
        button->setStyleSheet("QPushButton { background-color: rgb(175, 97, 33); font-size: " + QString::number(fontSize) + "px; } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
    } else if(color == "orange") {
        button->setStyleSheet("QPushButton { background-color: rgb(81, 44, 6); } QPushButton:pressed { background-color: rgb(50, 50, 50); } QToolTip { background-color: rgb(30, 27, 6); border: 1px solid white; }");
    } else if(color == "blue") {
        button->setStyleSheet("QPushButton { background-color: rgb(0, 119, 171); font-size: " + QString::number(fontSize) + "px; } QPushButton:pressed { background-color: rgb(175, 97, 33); }");
    } else if(color == "blue_graph") {
        button->setStyleSheet("QPushButton { background-color: rgb(0, 119, 171); } QPushButton:pressed { background-color: rgb(175, 97, 33); } QToolTip { background-color: rgb(30, 27, 6);	border: 1px solid white; }");
    } else if(color == "blue_eq") {
        button->setStyleSheet("QPushButton { background-color: rgb(23, 135, 21); } QPushButton:pressed { background-color: rgb(50, 50, 50);}");
    } else if(color == "green") {
        button->setStyleSheet("QPushButton { background-color: rgb(23, 135, 21); font-size: " + QString::number(fontSize) + "px; } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
    } else if(color == "green_var") {
        button->setStyleSheet("QPushButton { background-color: rgb(23, 135, 21); } QPushButton:pressed { background-color: rgb(50, 50, 50); } QToolTip { background-color: rgb(30, 27, 6); border: 1px solid white; }");
    } else if(color == "black_eq") {
        button->setStyleSheet("QPushButton { background-color: rgb(30, 27, 6); color: rgb(30, 27, 6) } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
    }
}

// Сохранить выражение в историю
void s21_smartcalc::save_history() {
    if(history_count + 1 != history.size()) {
        int list_size = history.size();
        for(int i = 0; i < list_size - history_count - 1; i++) {
            history.removeAt(history_count + 1);
            QListWidgetItem *itemToRemove = ui->history_widget->takeItem(history_count + 1);
            delete itemToRemove;
        }
    }
    if(history_count >= 0) {
        QString check = history.at(history_count);
        if(check != ui->result->text()) {
            history << ui->result->text();
            ui->history_widget->addItem(ui->result->text());
            history_count++;
        }
    } else {
        history << ui->result->text();
        ui->history_widget->addItem(ui->result->text());
        history_count++;
    }
}

// Отмотка истории назад
void s21_smartcalc::on_turn_back_clicked()
{
    if(history_count > 0) {
        if(!(history_count + 1 == history.size() &&  ui->result->text() != history[history_count]))
            history_count--;
    }
    if(history.size()) {
        ui->result->setText(history[history_count]);
    }
    clear_after = false;
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

// Вспомогательная функция добавления текста на главный экран
void s21_smartcalc::add(QString text) {
    ui->result->setText(ui->result->text() + text);
}

// Добавление цифр
void s21_smartcalc::push_nums()
{
    clear_result();
    QPushButton *button = (QPushButton *)sender();
    add(button->text());
}

// Очистить поле ввода в случае предыдущих вычислений
void s21_smartcalc::clear_result()
{
    if(clear_after) {
        ui->result->setText("");
        clear_after = false;
    }
}

// Добавить переменную
void s21_smartcalc::on_actionVarTriggered()
{
    clear_result();
    add("x");
}

// Квадратный корень из числа
void s21_smartcalc::on_push_sqrt_clicked()
{
    clear_result();
    add("sqrt(");
}

// Десятичный логарифм
void s21_smartcalc::on_push_log_clicked()
{
    clear_result();
    add("log(");
}

// Натуральный логарифм
void s21_smartcalc::on_push_ln_clicked()
{
    clear_result();
    add("ln(");
}

// Синус
void s21_smartcalc::on_push_sin_clicked()
{
    clear_result();
    add("sin(");
}

// Косинус
void s21_smartcalc::on_push_cos_clicked()
{
    clear_result();
    add("cos(");
}

// Тангенс
void s21_smartcalc::on_push_tan_clicked()
{
    clear_result();
    add("tan(");
}

// Арксинус
void s21_smartcalc::on_push_asin_clicked()
{
    clear_result();
    add("asin(");
}

// Арккосинус
void s21_smartcalc::on_push_acos_clicked()
{
    clear_result();
    add("acos(");
}

// Арктангенс
void s21_smartcalc::on_push_atan_clicked()
{
    clear_result();
    add("atan(");
}

// Остаток от деления
void s21_smartcalc::on_push_mod_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add(" mod ");
    }
}

// Добавить открывающую скобку
void s21_smartcalc::on_push_opn_brack_clicked()
{
    clear_result();
    add("(");
}

// Добавить закрывающую скобку
void s21_smartcalc::on_push_cls_brack_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add(")");
    }
}

// Добавить деление
void s21_smartcalc::on_push_div_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add("/");
    }
}

// Добавить умножение
void s21_smartcalc::on_push_mul_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add("*");
    }
}

// Добавить вычитание
void s21_smartcalc::on_push_sub_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add("-");
    }
}

// Добавить сумму
void s21_smartcalc::on_push_sum_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add("+");
    }
}

// Научная нотация
void s21_smartcalc::on_push_e_clicked()
{
    clear_result();
    add("e");
}

// Добавить число Пи
void s21_smartcalc::on_push_pi_clicked()
{
    clear_result();
    add("P");
}

// Возведение в степень
void s21_smartcalc::on_push_exp_clicked()
{
    clear_result();
    if(ui->result->text().length() > 0) {
        add("^");
    }
}

// Очистить поле ввода
void s21_smartcalc::on_push_c_clicked()
{
    ui->result->setText("");
}
