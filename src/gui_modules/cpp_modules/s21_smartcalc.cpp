#include "./../include/s21_smartcalc.h"
#include "./../include/s21_credit.h"
#include "./../include/s21_deposit.h"
#include "./ui_s21_smartcalc.h"

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

    QListView * listView = new QListView(ui->switch_window);
    listView->setStyleSheet("QListView {background-color: rgb(30, 27, 6);} QListView::item {border-bottom: 5px solid rgb(30, 27, 6); margin:3px; background-color: rgb(30, 27, 6); } QListView::item:selected {border-bottom: 5px solid rgb(175, 97, 33); margin:3px; color: white;}");
    ui->switch_window->setView(listView);

    ui->history_info_label->setVisible(false);
    ui->history_widget->setVisible(false);

    connect(this, &s21_smartcalc::resized, this, &s21_smartcalc::onResized);
    connect(ui->result, &QLineEdit::textChanged, this, &s21_smartcalc::onCheckExpr);
    connect(ui->switch_window, &QComboBox::currentTextChanged, this, &s21_smartcalc::change_mode);
    connect(this, &s21_smartcalc::keyPressed, this, &s21_smartcalc::handleKeyPress);
}

void s21_smartcalc::change_mode(const QString index)
{
    QPoint currentPosGlobal = this->mapToGlobal(QPoint(0, 0));
    QSize currentSize = this->size();
    QMainWindow* newWindow = nullptr;

    if (index == "Deposit") {
        newWindow = new s21_deposit();
        QIcon icon(":deposit.png");
        newWindow->setWindowIcon(icon);
    } else if (index == "Credit") {
        newWindow = new s21_credit();
        QIcon icon(":credit.png");
        newWindow->setWindowIcon(icon);
    }

    if (newWindow) {
        this->close();
        newWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), currentSize.width(), currentSize.height());
        newWindow->show();
    }
}

void s21_smartcalc::keyPressEvent(QKeyEvent *event)
{
    emit keyPressed(event->key());
}

void s21_smartcalc::handleKeyPress(int key)
{
    if(key >= 48 && key <= 57) {
        add(QString::number(key - 48));
    } else if(key == 43) {
        on_push_sum_clicked();
    } else if(key == 45) {
        on_push_sub_clicked();
    } else if(key == 42) {
        on_push_mul_clicked();
    } else if(key == 47) {
        on_push_div_clicked();
    } else if(key == 46) {
        on_push_dot_clicked();
    } else if(key == 40) {
        on_push_opn_brack_clicked();
    } else if(key == 41) {
        on_push_cls_brack_clicked();
    } else if(key == 94) {
        on_push_exp_clicked();
    } else if(key == 80) {
        on_push_pi_clicked();
    } else if(key == 69) {
        on_push_e_clicked();
    } else if(key == 16777219) {
        on_push_del_clicked();
    } else if(key == 16777220 || key == 61) {
        on_push_eq_clicked();
    } else if(key == 16777216) {
        on_push_c_clicked();
        clear_history(0);
        history_count = -1;
    } else if(key == 90) {
        on_turn_back_clicked();
    } else if(key == 88) {
        on_move_frwd_clicked();
    } else if(key == 86) {
        on_variable_clicked();
    } else if(key == 66) {
        on_graph_clicked();
    } else if(key == 77) {
        add("m");
    } else if(key == 79) {
        add("o");
    } else if(key == 68) {
        add("d");
    } else if(key == 83) {
        add("s");
    } else if(key == 73) {
        add("i");
    } else if(key == 78) {
        add("n");
    } else if(key == 67) {
        add("c");
    } else if(key == 84) {
        add("t");
    } else if(key == 65) {
        add("a");
    } else if(key == 81) {
        add("q");
    } else if(key == 82) {
        add("r");
    } else if(key == 76) {
        add("l");
    } else if(key == 71) {
        add("g");
    } else if(key == 88) {
        add("x");
    }
}

int s21_smartcalc::additional_validation(QString text)
{
    text.remove(' ');
    int count_open = 0;
    int count_close = 0;
    int valid = CORRECT_EXPR;
    int empty_brackets = 0;
    QString begin = "(-0123456789sctalPxe";
    QString nums = "0123456789";
    QString lexems = "+-*/^";
    if(text.length() && begin.count(text[0]) && text[text.length() - 1] != '.') {
        for(int i = 0; i < text.length(); i++) {
            if(text[i] == ')') {
                count_close++;
                int temp_count_open = 0;
                for(int j = 0; j < i; j++) {
                    if(text[j] == '(') {
                        temp_count_open++;
                    }
                }
                if(temp_count_open != count_close || empty_brackets) {
                    valid = WRONG_EXPR;
                } else {
                    valid = CORRECT_EXPR;
                }
            } else if(text[i] == '(') {
                count_open++;
                if(i < text.length() - 1 && (text[i + 1] == ')' || text[i + 1] == '^')) {
                    empty_brackets = 1;
                }
            } else if(i != text.length() && text[i] == '.' && !nums.count(text[i + 1])) {
                valid = WRONG_EXPR;
            } else if(i < text.length() - 1 && lexems.count(text[i]) && lexems.count(text[i + 1])){
                empty_brackets = 1;
            }
        }

        int number_now = 0;
        int dot_count = 0;
        for(int i = 0; i < text.length(); i++) {
            if(number_now && text[i] == '.') {
                dot_count++;
                if(dot_count > 1) {
                    valid = WRONG_EXPR;
                }
            }
            if(nums.count(text[i])) {
                number_now = 1;
            } else {
                if(text[i] != '.') {
                    number_now = 0;
                    dot_count = 0;
                }
            }
        }
    } else {
        valid = WRONG_EXPR;
    }

    return valid;
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
    if(clear_after) {
        ui->result->setText("");
        clear_after = false;
    } else {
        int wrong_expression = additional_validation(text);

        if(wrong_expression == NO) {
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
        } else {
            ui->result->setStyleSheet(QString("background-color: rgb(30, 27, 6); font-size: %1px; border: 0px;color: rgba(255, 50, 50, 150);").arg(font_size));
            valid = NO;
        }
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
                    style += " " + QString::number((font_size > 44) ? 25 : font_size - 19) + "px;}";

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

int s21_smartcalc::countDigits(double number)
{
    if(abs(number) < 1) {
        return 0;
    }
    int integer = static_cast<int>(number);
    std::string integer_string = std::to_string(integer);
    return integer_string.length();
}

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

void s21_smartcalc::on_push_dot_clicked()
{
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

void s21_smartcalc::on_graph_clicked()
{
    if(!graphWindow) {
        QPoint currentPosGlobal = this->mapToGlobal(QPoint(-600, 0));
        graphWindow = new graphics();
        graphWindow->setGeometry(currentPosGlobal.x(), currentPosGlobal.y(), 600, 600);
        QIcon icon(":plot.png");
        graphWindow->setWindowIcon(icon);
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

void s21_smartcalc::createPlotButton(QPushButton *button, int row)
{
    button->setMinimumSize(80, 50);
    button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->buttons->addWidget(button, row, 4, 1, 1);
}

void s21_smartcalc::on_actionPlotTriggered()
{
    int valid_range = graphWindow->compare_max_min_x_y();
    if(ui->result->text().length() > 0 && valid == YES && !valid_range) {
        save_history();
        graphWindow->build_plot(ui->result->text());
        graphWindow->show();
        clear_after = true;
    }
}

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

void s21_smartcalc::change_color(QPushButton *button, QString color)
{
    QString styleSheet = ui->push_0->styleSheet();
    QRegularExpression regex("font-size:\\s*(\\d+)px;");
    QRegularExpressionMatch match = regex.match(styleSheet);
    int fontSize = match.captured(1).toInt();
    if(color == "orange_eq") {
        button->setStyleSheet("QPushButton { background-color: rgb(175, 97, 33); color: rgb(255, 255, 255); font-size: " + QString::number(fontSize) + "px; } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
    } else if(color == "orange") {
        button->setStyleSheet("QPushButton { background-color: rgb(175, 97, 33); color: rgb(255, 255, 255);} QPushButton:pressed { background-color: rgb(50, 50, 50); } QToolTip { background-color: rgb(226, 226, 226); border: 1px solid white; color: rgb(0, 0, 0); }");
    } else if(color == "blue") {
        button->setStyleSheet("QPushButton { background-color: rgb(0, 119, 171); color: rgb(255, 255, 255); font-size: " + QString::number(fontSize) + "px; } QPushButton:pressed { background-color: rgb(175, 97, 33); }");
    } else if(color == "blue_graph") {
        button->setStyleSheet("QPushButton { background-color: rgb(0, 119, 171); color: rgb(255, 255, 255);} QPushButton:pressed { background-color: rgb(175, 97, 33); } QToolTip { background-color: rgb(226, 226, 226); border: 1px solid white; color: rgb(0, 0, 0); }");
    } else if(color == "blue_eq") {
        button->setStyleSheet("QPushButton { background-color: rgb(23, 135, 21); color: rgb(255, 255, 255);} QPushButton:pressed { background-color: rgb(50, 50, 50);}");
    } else if(color == "green") {
        button->setStyleSheet("QPushButton { background-color: rgb(23, 135, 21); color: rgb(255, 255, 255); font-size: " + QString::number(fontSize) + "px; } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
    } else if(color == "green_var") {
        button->setStyleSheet("QPushButton { background-color: rgb(23, 135, 21); color: rgb(255, 255, 255);} QPushButton:pressed { background-color: rgb(50, 50, 50); } QToolTip { background-color: rgb(226, 226, 226); border: 1px solid white; color: rgb(0, 0, 0); }");
    } else if(color == "black_eq") {
        button->setStyleSheet("QPushButton { background-color: rgb(30, 27, 6); color: rgb(30, 27, 6) } QPushButton:pressed { background-color: rgb(50, 50, 50); }");
    }
}

void s21_smartcalc::clear_history(int key)
{
    int list_size = history.size();
    if(key) {
        for(int i = 0; i < list_size - history_count - 1; i++) {
            history.removeAt(history_count + 1);
            QListWidgetItem *itemToRemove = ui->history_widget->takeItem(history_count + 1);
            delete itemToRemove;
        }
    } else {
        for(int i = list_size - 1; i >= 0; i--) {
            history.removeAt(i);
            QListWidgetItem *itemToRemove = ui->history_widget->takeItem(i);
            delete itemToRemove;
        }
    }
}

void s21_smartcalc::save_history() {
    if(history_count + 1 != history.size()) {
        clear_history(1);
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

void s21_smartcalc::on_turn_back_clicked()
{
    clear_after = false;
    if(history_count > 0) {
        if(!(history_count + 1 == history.size() &&  ui->result->text() != history[history_count]))
            history_count--;
    }
    if(history.size()) {
        ui->result->setText(history[history_count]);
    }
}

void s21_smartcalc::on_move_frwd_clicked()
{
    if(history_count >= -1) {
        if(history_count < history.size() - 1) {
            history_count++;
            ui->result->setText(history[history_count]);
        }
    }
}

void s21_smartcalc::on_push_del_clicked()
{
    if(ui->result->text().length() > 0) {
        QString temp = ui->result->text();
        temp.chop(1);
        ui->result->setText(temp);
    }
}

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

void s21_smartcalc::add(QString text) {
    ui->result->setText(ui->result->text() + text);
}

void s21_smartcalc::push_nums()
{
    QPushButton *button = (QPushButton *)sender();
    add(button->text());
}

void s21_smartcalc::clear_result()
{
    if(clear_after) {
        ui->result->setText("");
        clear_after = false;
    }
}

void s21_smartcalc::on_actionVarTriggered()
{
    add("x");
}

void s21_smartcalc::on_push_sqrt_clicked()
{
    add("sqrt(");
}

void s21_smartcalc::on_push_log_clicked()
{
    add("log(");
}

void s21_smartcalc::on_push_ln_clicked()
{
    add("ln(");
}

void s21_smartcalc::on_push_sin_clicked()
{
    add("sin(");
}

void s21_smartcalc::on_push_cos_clicked()
{
    add("cos(");
}

void s21_smartcalc::on_push_tan_clicked()
{
    add("tan(");
}

void s21_smartcalc::on_push_asin_clicked()
{
    add("asin(");
}

void s21_smartcalc::on_push_acos_clicked()
{
    add("acos(");
}

void s21_smartcalc::on_push_atan_clicked()
{
    add("atan(");
}

void s21_smartcalc::on_push_mod_clicked()
{
    if(ui->result->text().length() > 0) {
        add(" mod ");
    }
}

void s21_smartcalc::on_push_opn_brack_clicked()
{
    add("(");
}

void s21_smartcalc::on_push_cls_brack_clicked()
{
    if(ui->result->text().length() > 0) {
        add(")");
    }
}

void s21_smartcalc::on_push_div_clicked()
{
    if(ui->result->text().length() > 0) {
        add("/");
    }
}

void s21_smartcalc::on_push_mul_clicked()
{
    if(ui->result->text().length() > 0) {
        add("*");
    }
}

void s21_smartcalc::on_push_sub_clicked()
{
    if(ui->result->text().length() > 0) {
        add("-");
    }
}

void s21_smartcalc::on_push_sum_clicked()
{
    if(ui->result->text().length() > 0) {
        add("+");
    }
}

void s21_smartcalc::on_push_e_clicked()
{
    add("e");
}

void s21_smartcalc::on_push_pi_clicked()
{
    add("P");
}

void s21_smartcalc::on_push_exp_clicked()
{
    if(ui->result->text().length() > 0) {
        add("^");
    }
}

void s21_smartcalc::on_push_c_clicked()
{
    ui->result->setText("");
}
